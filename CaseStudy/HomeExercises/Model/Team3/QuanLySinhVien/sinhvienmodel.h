#ifndef SINHVIENMODEL_H
#define SINHVIENMODEL_H
#include <QAbstractListModel>
#include <QStringList>
#include "sinhvien.h"


class SinhvienModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SinhvienRoles
    {
        COL_Name = Qt::UserRole + 1,
        COL_TUOI,
        COL_DIACHI,
        COL_EMAIL,
        COL_SODIENTHOAI
    };
    SinhvienModel();


public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QHash<int, QByteArray> roleNames() const;
    void updatesinhvien(const Sinhvien &dat);
signals:
    void sendData(QString name, QString tuoi, QString sodienthoai,QString diachi,QString email);

public slots:
    void onIndextabelview(int index);
    void cppSlot(const QVariant &v);
    void Removesinhvien(int index);
private:

    QHash<int, QByteArray> m_nameRoles;
    QList<Sinhvien*> m_sinhvien;

};


#endif // SINHVIENMODEL_H
