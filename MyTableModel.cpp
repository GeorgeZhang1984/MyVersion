#include <boost/foreach.hpp>
#include <sstream>
#include <string>
#include "MyTableModel.h"
#include "version.h"
using namespace std;

string toString(int a){
    ostringstream s;
    s << a;
    
    return s.str(); 
    
}

MyTableModel::MyTableModel(QObject *parent):QAbstractTableModel(parent)
{}
        
int MyTableModel::rowCount(const QModelIndex &) const
{
    return recordsCollection.size();
}
        
int MyTableModel::columnCount(const QModelIndex & ) const
{
    return 3;
    
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole){
        if (orientation == Qt::Horizontal){
            switch (section){
                case 0:
                    return QString("Nun");
                case 1:
                    return QString("Create Date");
                case 2:
                    return QString("File Length");
            }
        }
    }
    return QVariant();
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0){
            return QString(toString(recordsCollection.at(index.row())->getversionnum()).c_str());
        }
        if (index.column() == 1){
            return QString(recordsCollection.at(index.row())->getdate().c_str());
        }
        if (index.column() == 2){
            return QString(toString(recordsCollection.at(index.row())->getlength()).c_str());
        }
    }
    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index,const QVariant &value,int role){

	return false;
}

bool MyTableModel::insertRows(int position,int rows,const QModelIndex &index ){
//	Q_UNUSED(index);
//	beginInsertRows(QModelIndex(),position,position+rows-1)
	
//	endInsertRows();
//	return true;
//	cout<<"In insertRows - which isn't implemented" <<endl;
	return true;
}
bool MyTableModel::removeRows(int position,int rows,const QModelIndex &index){
	return true;
}







