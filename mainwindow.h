#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtCore/QString>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include "filearchiver.h"
#include "MyTableModel.h"

typedef versionRec* RecordPtr;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString getFileName();
    string toString (int i);

public slots:
    void selectTarFile();
    void savCurrent();
    void getComments();
    void setReference();
    void retrieveReference();
    void changeCurrentChoice(const QModelIndex &index);
private:
    Ui::MainWindow *ui;
    QString filename;
    filearchiver myArchiver;
    vector<versionRec> versions;
    bool ifNew;
    MyTableModel* myModel;
    int currentAccess;
    QMessageBox msgBox;
};

#endif // MAINWINDOW_H
