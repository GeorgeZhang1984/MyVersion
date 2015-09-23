/********************************************************************************
** Form generated from reading UI file 'pathChoice.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHCHOICE_H
#define UI_PATHCHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pathChoice
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *okbutton;

    void setupUi(QDialog *pathChoice)
    {
        if (pathChoice->objectName().isEmpty())
            pathChoice->setObjectName(QString::fromUtf8("pathChoice"));
        pathChoice->resize(443, 125);
        label = new QLabel(pathChoice);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 66, 17));
        lineEdit = new QLineEdit(pathChoice);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(74, 38, 211, 21));
        pushButton = new QPushButton(pathChoice);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(295, 34, 98, 27));
        label_2 = new QLabel(pathChoice);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 71, 17));
        lineEdit_2 = new QLineEdit(pathChoice);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(114, 88, 171, 21));
        okbutton = new QPushButton(pathChoice);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setGeometry(QRect(294, 83, 98, 27));

        retranslateUi(pathChoice);

        QMetaObject::connectSlotsByName(pathChoice);
    } // setupUi

    void retranslateUi(QDialog *pathChoice)
    {
        pathChoice->setWindowTitle(QApplication::translate("pathChoice", "pathChoice", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pathChoice", "Path:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("pathChoice", "select path", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("pathChoice", "File Name: ", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("pathChoice", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pathChoice: public Ui_pathChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHCHOICE_H
