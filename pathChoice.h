    /* 
     * File:   pathChoice.h
     * Author: hz740
     *
     * Created on 14 September 2015, 9:39 PM
     */

    #ifndef _PATHCHOICE_H
    #define	_PATHCHOICE_H
    #include <QtGui/QFileDialog>
    #include <QtGui/QMessageBox>
    #include <QtGui/QCloseEvent>
    #include "ui_pathChoice.h"

    class pathChoice : public QDialog {
        Q_OBJECT
    public:
        pathChoice();
        virtual ~pathChoice();
        std::string getNewName();
    public slots:
        void selectPath();
        void setFileName();
    private:
        Ui::pathChoice widget;
        QString path;
        QString newfile;
    };

    #endif	/* _PATHCHOICE_H */
