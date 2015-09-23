#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pathChoice.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //put the events handling here
    connect(ui->selectFile,SIGNAL(clicked()),this,SLOT(selectTarFile()));
    connect(ui->saveCurrent,SIGNAL(clicked()),this,SLOT(savCurrent()));
    connect(ui->viewList, SIGNAL(clicked(const QModelIndex &)),this,SLOT(changeCurrentChoice(const QModelIndex &)));
    connect(ui->showComments, SIGNAL(clicked()),this,SLOT(getComments()));
    connect(ui->setReference, SIGNAL(clicked()),this, SLOT(setReference()));
    connect(ui->retrieveVersion,SIGNAL(clicked()),this, SLOT(retrieveReference()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getFileName()
{
    return filename;
}

void MainWindow::selectTarFile()
{
    QString file = QFileDialog::getOpenFileName(this, "Open File", ".", "*.cpp *.pdf *.txt *.docx *.doc");
    if(!file.isEmpty())
    {
        ui->showRoute->setText(file);
    }
    
    filename = file;
    if(myArchiver.exists(filename.toStdString())){
        ui->saveCurrent->setEnabled(true);
        ui->setReference->setEnabled(true);
        
        
        versions = myArchiver.getVersionInfo(filename.toStdString());
        vector<versionRec>::iterator it = versions.begin();
        vector<RecordPtr> myReocrd;
        while(it != versions.end()){
            RecordPtr record = new versionRec;
            record->setversionnum((*it).getversionnum());
            record->setlength((*it).getlength());
            record->setdate((*it).getdate());

            myReocrd.push_back(record);
            it++;
        }
        
        myModel = new MyTableModel(0);
        myModel->addTheData(myReocrd);
        ui->viewList->setModel(myModel);
        ui->viewList->resizeRowsToContents();
        ui->viewList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->viewList->setColumnWidth(0, 90);
        ui->viewList->setColumnWidth(1, 244);
        ui->viewList->setColumnWidth(2, 90);
        
        ifNew = false;
    }else{
        ui->saveCurrent->setEnabled(true);
        myModel = new MyTableModel(0);
        ui->viewList->setModel(myModel);
        ui->viewList->resizeRowsToContents();
        ifNew = true;
    }
}

void MainWindow::savCurrent()
{
    if(filename.isEmpty())
    {
        msgBox.setWindowTitle("Warning");
        msgBox.setText("The file you refer is not available!");
        msgBox.exec();
        return;
    }
    if(!filename.isEmpty())
    {
        bool ok;
        if(ifNew){
            QString comment = QInputDialog::getText(this,
                                                tr("Comments for save"),
                                                tr("Comments:"),
                                                QLineEdit::Normal,
                                                "", &ok);
            if (ok && myArchiver.insertNew(filename.toStdString(),comment.toStdString()))
            {
                versions = myArchiver.getVersionInfo(filename.toStdString());
                vector<versionRec>::iterator it = versions.begin();
                vector<RecordPtr> myReocrd;
                while(it != versions.end()){
                    RecordPtr record = new versionRec;
                    record->setversionnum((*it).getversionnum());
                    record->setlength((*it).getlength());
                    record->setdate((*it).getdate());

                    myReocrd.push_back(record);
                    it++;
                }

                myModel = new MyTableModel(0);
                myModel->addTheData(myReocrd);
                ui->viewList->setModel(myModel);
                ui->viewList->resizeRowsToContents();
                ui->viewList->setSelectionBehavior(QAbstractItemView::SelectRows);
                ui->viewList->setColumnWidth(1, 244);
                ui->viewList->setColumnWidth(2, 90);
                
                msgBox.setWindowTitle("Success");
                msgBox.setText("The file already be saved!");
                msgBox.exec();
            }
            else if (!ok){
                msgBox.setWindowTitle("Fail");
                msgBox.setText("Comment is required!");
                msgBox.exec();
            } else{
                msgBox.setWindowTitle("Fail");
                msgBox.setText("The file cannot be saved!");
                msgBox.exec();
            }
        }else {
            if(myArchiver.differs(filename.toStdString())){
                QString comment = QInputDialog::getText(this,
                                                tr("Comments for save"),
                                                tr("Comments:"),
                                                QLineEdit::Normal,
                                                QDir::home().dirName(), &ok);
                if (myArchiver.update(filename.toStdString(), comment.toStdString()))
                {
                    versions = myArchiver.getVersionInfo(filename.toStdString());
                    vector<versionRec>::iterator it = versions.begin();
                    vector<RecordPtr> myReocrd;
                    while(it != versions.end()){
                        RecordPtr record = new versionRec;
                        record->setversionnum((*it).getversionnum());
                        record->setlength((*it).getlength());
                        record->setdate((*it).getdate());

                        myReocrd.push_back(record);
                        it++;
                    }

                    myModel = new MyTableModel(0);
                    myModel->addTheData(myReocrd);
                    ui->viewList->setModel(myModel);
                    ui->viewList->resizeRowsToContents();
                    ui->viewList->setSelectionBehavior(QAbstractItemView::SelectRows);
                    ui->viewList->setColumnWidth(1, 244);
                    ui->viewList->setColumnWidth(2, 90);
                
                    msgBox.setWindowTitle("Success");
                    msgBox.setText("The file already be saved!");
                    msgBox.exec();
                }
                else
                {
                    msgBox.setWindowTitle("Error");
                    msgBox.setText("The file is the same as last version!");
                    msgBox.exec();                
                }
            } else{
                msgBox.setWindowTitle("Error");
                msgBox.setText("The file is the same as last version!");
                msgBox.exec();
            }       
        }
        this->getFileName();
        return;
    }
}

void MainWindow::changeCurrentChoice(const QModelIndex &index){
    currentAccess = index.row();
    ui->showComments->setEnabled(true);
    ui->retrieveVersion->setEnabled(true);
}

void MainWindow::getComments(){
    string comment = myArchiver.getComment(filename.toStdString(),versions.at(currentAccess).getversionnum());

    msgBox.setWindowTitle("Comments");
    msgBox.setText(comment.c_str());
    msgBox.exec();
}

string MainWindow::toString(int i){
    ostringstream ss;
    ss << i;

    return ss.str();
}

void MainWindow::setReference(){
    if(myArchiver.setReference(filename.toStdString(),versions.at(currentAccess).getversionnum(),"non comments")){
        string info = "Drop ";
        for(int i = 0; i < currentAccess; i++){
            if (i == 0)
                info += toString(i);
            else
                info += " and " + toString(i);
        }
        
        versions = myArchiver.getVersionInfo(filename.toStdString());
        vector<versionRec>::iterator it = versions.begin();
        vector<RecordPtr> myReocrd;
        while(it != versions.end()){
            RecordPtr record = new versionRec;
            record->setversionnum((*it).getversionnum());
            record->setlength((*it).getlength());
            record->setdate((*it).getdate());

            myReocrd.push_back(record);
            it++;
        }

        myModel = new MyTableModel(0);
        myModel->addTheData(myReocrd);
        ui->viewList->setModel(myModel);
        ui->viewList->resizeRowsToContents();
        ui->viewList->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->viewList->setColumnWidth(1, 244);
        ui->viewList->setColumnWidth(2, 90);
        
        msgBox.setWindowTitle("Success");
        msgBox.setText(info.c_str());
        msgBox.exec();
    }else{
        msgBox.setWindowTitle("Error");
        msgBox.setText("THis is the oldest version you have.");
        msgBox.exec();
    }
}

void MainWindow::retrieveReference(){
    pathChoice p;
    p.exec();
    
    string newfilename = p.getNewName();
    if(newfilename == ""){
        msgBox.setWindowTitle("Error");
        msgBox.setText("File name or File path cannot be null");
        msgBox.exec();
        
        return;
    }
    
    bool ok = myArchiver.retrieveVersion(versions.at(currentAccess).getversionnum(), filename.toStdString(), newfilename);
    
    if(ok){
        msgBox.setWindowTitle("Success");
        msgBox.setText("File has been saved");
        msgBox.exec();
    }else {
        msgBox.setWindowTitle("Error");
        msgBox.setText("Something wrong, please contact our support");
        msgBox.exec();
     }
}