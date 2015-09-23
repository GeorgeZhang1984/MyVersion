/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *showRoute;
    QPushButton *selectFile;
    QTableView *viewList;
    QPushButton *saveCurrent;
    QPushButton *retrieveVersion;
    QPushButton *setReference;
    QPushButton *showComments;
    QLabel *emptyLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(614, 447);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 59, 16));
        showRoute = new QLineEdit(centralWidget);
        showRoute->setObjectName(QString::fromUtf8("showRoute"));
        showRoute->setEnabled(false);
        showRoute->setGeometry(QRect(110, 20, 331, 21));
        selectFile = new QPushButton(centralWidget);
        selectFile->setObjectName(QString::fromUtf8("selectFile"));
        selectFile->setGeometry(QRect(470, 10, 121, 41));
        viewList = new QTableView(centralWidget);
        viewList->setObjectName(QString::fromUtf8("viewList"));
        viewList->setGeometry(QRect(160, 60, 431, 301));
        saveCurrent = new QPushButton(centralWidget);
        saveCurrent->setObjectName(QString::fromUtf8("saveCurrent"));
        saveCurrent->setEnabled(false);
        saveCurrent->setGeometry(QRect(10, 60, 141, 51));
        retrieveVersion = new QPushButton(centralWidget);
        retrieveVersion->setObjectName(QString::fromUtf8("retrieveVersion"));
        retrieveVersion->setEnabled(false);
        retrieveVersion->setGeometry(QRect(10, 140, 141, 51));
        setReference = new QPushButton(centralWidget);
        setReference->setObjectName(QString::fromUtf8("setReference"));
        setReference->setEnabled(false);
        setReference->setGeometry(QRect(10, 220, 141, 51));
        showComments = new QPushButton(centralWidget);
        showComments->setObjectName(QString::fromUtf8("showComments"));
        showComments->setEnabled(false);
        showComments->setGeometry(QRect(10, 310, 141, 51));
        emptyLabel = new QLabel(centralWidget);
        emptyLabel->setObjectName(QString::fromUtf8("emptyLabel"));
        emptyLabel->setGeometry(QRect(50, 360, 66, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        selectFile->setText(QApplication::translate("MainWindow", "select", 0, QApplication::UnicodeUTF8));
        saveCurrent->setText(QApplication::translate("MainWindow", "Save Current", 0, QApplication::UnicodeUTF8));
        retrieveVersion->setText(QApplication::translate("MainWindow", "Retrieve Version", 0, QApplication::UnicodeUTF8));
        setReference->setText(QApplication::translate("MainWindow", "Set as Reference", 0, QApplication::UnicodeUTF8));
        showComments->setText(QApplication::translate("MainWindow", "Show Comment", 0, QApplication::UnicodeUTF8));
        emptyLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
