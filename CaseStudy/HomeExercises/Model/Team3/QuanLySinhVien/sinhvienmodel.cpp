#include "sinhvienmodel.h"
#include <QDebug>
#include "sinhvien.h"
#include <QDebug>
SinhvienModel::SinhvienModel()
{
    m_nameRoles[COL_Name] ="name";
    m_nameRoles[COL_TUOI] ="tuoi";
    m_nameRoles[COL_EMAIL]="email";
    m_nameRoles[COL_DIACHI]="diachi";
    m_nameRoles[COL_SODIENTHOAI]="sodienthoai";




}

int SinhvienModel::rowCount(const QModelIndex &parent) const
{
    return m_sinhvien.count();

}

int SinhvienModel::columnCount(const QModelIndex &parent) const
{
    return m_nameRoles.count();

}

QVariant SinhvienModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
       if(row<0 || row >= m_sinhvien.count())
       {
           return QVariant();
       }
       Sinhvien *var= m_sinhvien.at(row);
       switch (role)
       {
       case COL_Name:
           return var->name();
       case COL_TUOI:
           return var->tuoi();
       case COL_DIACHI:
           return var->diachi();
       case COL_EMAIL:
           return var->email();
       case COL_SODIENTHOAI:
           return var->sodienthoai();

       }
       return QVariant();
}

QVariant SinhvienModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QHash<int, QByteArray> SinhvienModel::roleNames() const
{

    return m_nameRoles;

}

void SinhvienModel::updatesinhvien(const Sinhvien &data)
{
    qDebug() << "MessageModel::updateMessage update message";
    beginInsertRows(QModelIndex(),0,0);
    Sinhvien* sv= new Sinhvien;
    sv->setName(data.name());
    sv->setDiachi(data.diachi());
    sv->setTuoi(data.tuoi());
    sv->setEmail(data.email());
    sv->setSodienthoai(data.sodienthoai());

    qDebug() << data.email();
    m_sinhvien.insert(0,sv);
    endInsertRows();
    emit layoutChanged();
}

void SinhvienModel::onIndextabelview(int index)
{
    Sinhvien *sv = m_sinhvien.at(index);
    QString name = sv->name();
    QString tuoi =sv->tuoi();
    QString sodienthoai =sv->sodienthoai();
    QString diachi =sv->diachi();
    QString email =sv->email();
//    qDebug()<<name<<tuoi<<sodienthoai;

    emit sendData(name,tuoi,sodienthoai,diachi,email);


}

void SinhvienModel::Removesinhvien(int index)
{

    beginRemoveRows(QModelIndex(),index,index);
    m_sinhvien.removeAt(index);
    endRemoveRows();

}

void SinhvienModel::cppSlot(const QVariant &v)
{
    qDebug()<<"xin chao cac ban"<<v;

    Sinhvien *item = qobject_cast<Sinhvien*>(v.value<QObject*>());

    updatesinhvien(*item);

}



