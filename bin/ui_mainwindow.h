/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *fromlabel;
    QLineEdit *fileEdit;
    QPushButton *fileopenButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_file;
    QRadioButton *radioButton_path;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ConvertButton;
    QProgressBar *ConvertBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(454, 454);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 100, 411, 251));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 70, 411, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        fromlabel = new QLabel(layoutWidget);
        fromlabel->setObjectName(QStringLiteral("fromlabel"));

        horizontalLayout_5->addWidget(fromlabel);

        fileEdit = new QLineEdit(layoutWidget);
        fileEdit->setObjectName(QStringLiteral("fileEdit"));

        horizontalLayout_5->addWidget(fileEdit);

        fileopenButton = new QPushButton(layoutWidget);
        fileopenButton->setObjectName(QStringLiteral("fileopenButton"));

        horizontalLayout_5->addWidget(fileopenButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 1, 411, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        horizontalLayout_2->addWidget(label);

        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(11, 11, 114, 18));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_file = new QRadioButton(layoutWidget2);
        radioButton_file->setObjectName(QStringLiteral("radioButton_file"));
        radioButton_file->setChecked(true);

        horizontalLayout->addWidget(radioButton_file);

        radioButton_path = new QRadioButton(layoutWidget2);
        radioButton_path->setObjectName(QStringLiteral("radioButton_path"));

        horizontalLayout->addWidget(radioButton_path);


        horizontalLayout_2->addWidget(groupBox);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 360, 411, 25));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        ConvertButton = new QPushButton(widget);
        ConvertButton->setObjectName(QStringLiteral("ConvertButton"));

        horizontalLayout_3->addWidget(ConvertButton);

        ConvertBar = new QProgressBar(widget);
        ConvertBar->setObjectName(QStringLiteral("ConvertBar"));
        ConvertBar->setValue(24);

        horizontalLayout_3->addWidget(ConvertBar);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        textBrowser->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        ConvertBar->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 454, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ffmpeg\345\210\207\347\211\207\345\260\217\345\267\245\345\205\267", 0));
        fromlabel->setText(QApplication::translate("MainWindow", "From\357\274\232", 0));
        fileopenButton->setText(QApplication::translate("MainWindow", "brower", 0));
        label->setText(QApplication::translate("MainWindow", "\350\257\245\345\267\245\345\205\267\346\224\257\346\214\201\346\226\207\344\273\266\347\232\204\350\275\254\346\215\242\344\271\237\346\224\257\346\214\201\346\226\207\344\273\266\345\244\271\347\232\204\346\211\271\351\207\217\345\244\204\347\220\206\357\274\214\350\257\267\351\200\211\346\213\251\350\207\252\345\267\261\345\220\210\351\200\202\347\232\204\351\200\211\351\241\271\357\274\232", 0));
        groupBox->setTitle(QString());
        radioButton_file->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        radioButton_path->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\271", 0));
        ConvertButton->setText(QApplication::translate("MainWindow", "Convert", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
