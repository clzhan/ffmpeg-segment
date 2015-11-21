#ifndef PATHPROCESS
#define PATHPROCESS

#include <QThread>
#include <QProcess>
#include <QDir>
#include <QFileInfo>



//  process 子线程处理文件夹的ts文件
class PathProcess : public QThread
{
    Q_OBJECT
public:
    explicit PathProcess(QObject *parent = 0);
    ~PathProcess();

    void setpath(QString path); //设置文件路径

protected:
     virtual void run();

private slots:

    void readyReadStandardOutput();

signals:
    void commandSuccessed(QString ip);
    void commandFailed(QString ip);

    void Log(QString   sMessage);

public slots:


private:
    QProcess * mConvertProcess;
    QString path;
    QString mOutputString;
};


#endif // PATHPROCESS

