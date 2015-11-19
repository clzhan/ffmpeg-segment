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

}
