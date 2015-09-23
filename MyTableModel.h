/* 
 * File:   MyTableModel.h
 * Author: hz740
 *
 * Created on 28 August 2015, 10:45 PM
 */

#ifndef MYTABLEMODEL_H
#define	MYTABLEMODEL_H
#include <QAbstractTableModel>
#include <QtGui>
#include <vector>
#include "version.h"
using namespace std;

typedef versionRec* RecordPtr;

class MyTableModel : public QAbstractTableModel{
    Q_OBJECT
public:
    MyTableModel(QObject *parent);
    void addTheData(vector<RecordPtr> data){this->recordsCollection = data;};
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index,const QVariant &value,int role = Qt::EditRole);
    bool insertRows(int position,int rows,const QModelIndex &index = QModelIndex());
    bool removeRows(int position,int rows,const QModelIndex &index = QModelIndex());
    void addRecord(RecordPtr newone);
private:
    vector<RecordPtr> recordsCollection;
    MyTableModel& operator=(const MyTableModel&);
    MyTableModel(const MyTableModel& orig);
};


#endif	/* MYTABLEMODEL_H */

