/*
 * File:   pathChoice.cpp
 * Author: hz740
 *
 * Created on 14 September 2015, 9:39 PM
 */

#include "pathChoice.h"

pathChoice::pathChoice() {
    widget.setupUi(this);
    
    //put the events handling here
    connect(widget.pushButton,SIGNAL(clicked()),this,SLOT(selectPath()));
    connect(widget.okbutton,SIGNAL(clicked()),this,SLOT(setFileName()));
}

pathChoice::~pathChoice() {
}

std::string pathChoice::getNewName(){
    if (path.toStdString() == "" || newfile.toStdString() == "")
        return "";
    
    return (path.toStdString() + "/" + newfile.toStdString());};

void pathChoice::selectPath(){
    path = QFileDialog::getExistingDirectory(this, 
                                             tr("Open Directory"), 
                                             ".",
                                             QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    widget.lineEdit->setText(path);  
    newfile = widget.lineEdit_2->text();
};

void pathChoice::setFileName(){
    newfile = widget.lineEdit_2->text();
    pathChoice::close();
}