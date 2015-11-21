#include "pathprocess.h"

#include <QtDebug>
#include <QProcess>



PathProcess::PathProcess(QObject *parent):QThread(parent)
{
   // connect(mConvertProcess, SIGNAL(started()), this, SLOT(processStarted()));


   // connect(mConvertProcess, SIGNAL(finished(int)), this, SLOT(encodingFinished()));

}
PathProcess::~PathProcess()
{

}

void PathProcess::setpath(QString path)
{
    this->path = path;
}

void PathProcess::readyReadStandardOutput()
{
    mOutputString.append(mConvertProcess->readAllStandardOutput());
    emit Log(mOutputString);
}

void PathProcess::run()
{
   emit Log("jejee");

    mConvertProcess = new QProcess(this);
    connect(mConvertProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(readyReadStandardOutput()));

    QDir dir(this->path);
    if (!dir.exists())
    {
        return;
    }
    QStringList filters;
    filters << QString("*.ts") << QString("*.TS");
    dir.setFilter(QDir::Files); //设置类型过滤器，只为文件格式
    dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式（后缀为.jpeg等图片格式）

    QFileInfoList list = dir.entryInfoList();

    int file_count = list.count();
    if (file_count <= 0)
    {
        return;
    }

    emit Log("The path has ts file number:" + QString::number(file_count));

    for (int i = 0; i < file_count; i++)
    {
        QFileInfo fileInfo = list.at(i);


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

        args <<"-i"<<fileInfo.absoluteFilePath();
        args <<"-c"<<"copy";
        args <<"-map"<<"0";
        args <<"-f"<<"segment";
        args <<"-segment_list"<< m3u8_name;
        args <<"-segment_time"<<"10";
        args <<list_name;

        qDebug() << args << endl;

        mConvertProcess->setProcessChannelMode(QProcess::MergedChannels);

        QString program = "D:/ffmpeg/qtffmpeg/ffmpeghls/ffmpegtosegment/github/ffmpeg-segment/bin/ffmpeg";
        mConvertProcess->start(program, args);


        while (false == mConvertProcess->waitForFinished())
        {
        }

    }
     emit Log("convert finished");
}
