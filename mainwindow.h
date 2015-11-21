#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QScrollBar>
#include <process.h>
#include "pathprocess.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_fileopenButton_clicked();

    void on_radioButton_file_clicked();

    void on_radioButton_path_clicked();

    void on_ConvertButton_clicked();
    void processStarted();
    void readyReadStandardOutput();
    void TranscodingFinished();

    void Log (QString   sMessage);


private:
    Ui::MainWindow *ui;
    QProcess *mTranscodingProcess;
    bool isfile;
    bool hasfile;
    QString mOutputString;
    PathProcess *mypathProcess;

};

#endif // MAINWINDOW_H
