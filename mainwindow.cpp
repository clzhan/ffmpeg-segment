#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isfile = true; //代表是文件或者是文件夹
    hasfile = false; // 代表该文件是ts 或者文件夹内有ts文件


    // Create process
    // transcoding
    mTranscodingProcess = new QProcess(this);

    connect(mTranscodingProcess, SIGNAL(started()), this, SLOT(processStarted()));

    connect(mTranscodingProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));
    connect(mTranscodingProcess, SIGNAL(finished(int)), this, SLOT(encodingFinished()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processStarted()
{
    qDebug() << "processStarted()";
}
void MainWindow::readyReadStandardOutput()
{
    mOutputString.append(mTranscodingProcess->readAllStandardOutput());
    ui->textBrowser->setText(mOutputString);

    // put the slider at the bottom
    ui->textBrowser->verticalScrollBar()
            ->setSliderPosition(
                ui->textBrowser->verticalScrollBar()->maximum());
}
void MainWindow::TranscodingFinished()
{
    // Set the encoding status by checking output file's existence
//    QString fileName = ui->toLineEdit->text();

//    if (QFile::exists(fileName)) {
//        ui->transcodingStatusLabel
//                ->setText("Transcoding Status: Successful!");
//        ui->playOutputButton->setEnabled(true);
//    }
//    else {
//        ui->transcodingStatusLabel
//                ->setText("Transcoding Status: Failed!");
//    }
}

void MainWindow::on_fileopenButton_clicked()
{
    if(isfile)
    {
        QString fileName =
            QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "C:/",
                    tr("videoss (*.ts)"));
        if (!fileName.isEmpty()) {
            ui->fileEdit->setText(fileName);
            ui->textBrowser->setText("Now you open file:" + fileName);
            hasfile = true;
        }
        else
        {
            hasfile = false;
            ui->textBrowser->setText("There is not TS file, please input correct path!!!!");
        }

    }
    else
    {
        QString dirpath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
            "c:/",
            QFileDialog::ShowDirsOnly
            | QFileDialog::DontResolveSymlinks);

        qDebug() << dirpath;

        QDir dir(dirpath);
        if (!dir.exists())
        {
            hasfile = false;
            ui->textBrowser->setText("There is not TS file, please input correct path!!!!");
            return;
        }
        QStringList filters;
        filters << QString("*.ts") << QString("*.TS");
        dir.setFilter(QDir::Files);
        dir.setNameFilters(filters);

        QFileInfoList list = dir.entryInfoList();

        int file_count = list.count();
        if (file_count <= 0)
        {
            hasfile = false;
            ui->textBrowser->setText("There is not TS file, please input correct path!!!!");
            return;
        }

        hasfile = true;
        ui->fileEdit->setText(dirpath);
        ui->textBrowser->setText("Now you open path:" + dirpath);


    }

}

void MainWindow::on_radioButton_file_clicked()
{
    isfile = true;
    qDebug() << "isfile is : " <<   isfile;
}

void MainWindow::on_radioButton_path_clicked()
{
    isfile = false;
     qDebug() << "isfile is : " <<   isfile;
}

void MainWindow::on_ConvertButton_clicked()
{
    if(!hasfile)
    {
       ui->textBrowser->setText("There is not TS file, please input correct path or ts file!!!!");
       return;
    }
    //fmpeg - i h : / itvfile / hd / 1_zh_003.ts.ts - c copy - map 0 - f segment - segment_list h : / itvfile / hd / 1_zh_003.m3u8 - segment_time 10 h : / itvfile / hd / 1_zh_003%03d.ts

    if(isfile)
    {
        //获取文本框的输入
        QString inputfile =  ui->fileEdit->text();
        if(inputfile.isEmpty()) {
            qDebug() << "No input";
            return;
        }
        QFileInfo fileInfo(inputfile);

        QString mkdir_path = fileInfo.path() + "/" + fileInfo.baseName();
        qDebug() << "mkdir_path" + mkdir_path;

        //mkdir same name dir
        QDir *dir_mkdir = new QDir;
        bool exist = dir_mkdir->exists(mkdir_path);
        if (exist)
        {
        }
        else
        {
            bool ok = dir_mkdir->mkdir(mkdir_path);
            if (ok)
            {
                //textEdit->append(mkdir_path + " path create ok");
            }
        }
        delete dir_mkdir;

        QString m3u8_name = fileInfo.path() + "/" + fileInfo.baseName()+"/" + fileInfo.baseName() +".m3u8";
        QString list_name = fileInfo.path() + "/" + fileInfo.baseName()+"/" + fileInfo.baseName() +"%03d.ts";

        QStringList args;

        args <<"-i"<<inputfile;
        args <<"-c"<<"copy";
        args <<"-map"<<"0";
        args <<"-f"<<"segment";
        args <<"-segment_list"<< m3u8_name;
        args <<"-segment_time"<<"10";
        args <<list_name;

        qDebug() << args << endl;

        mTranscodingProcess->setProcessChannelMode(QProcess::MergedChannels);

        QString program = "D:/ffmpeg/qtffmpeg/ffmpeghls/ffmpegtosegment/github/ffmpeg-segment/bin/ffmpeg";
        mTranscodingProcess->start(program, args);

    }


//

//    QStringList arguments;

//    QString output = ui->toLineEdit->text();
//    if(output.isEmpty()) {
//        qDebug() << "No output";
//        QMessageBox::information(this,
//                     tr("ffmpeg"),tr("Output file not specified"));
//        return;
//    }

//    QString fileName = ui->toLineEdit->text();
//    qDebug() << "output file check " << fileName;
//    qDebug() << "QFile::exists(fileName) = " << QFile::exists(fileName);
//    if (QFile::exists(fileName)) {
//         if (QMessageBox::question(this, tr("ffmpeg"),
//                    tr("There already exists a file called %1 in "
//                    "the current directory. Overwrite?").arg(fileName),
//                    QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
//             == QMessageBox::No)
//             return;
//         QFile::remove(fileName);
//         while(QFile::exists(fileName)) {
//             qDebug() << "output file still there";
//         }
//     }

//    arguments << "-i" << input << output;

//    qDebug() << arguments;

//    mTranscodingProcess->setProcessChannelMode(QProcess::MergedChannels);
//    mTranscodingProcess->start(program, arguments);

}
