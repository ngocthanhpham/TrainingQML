#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <QObject>

class Sinhvien : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString tuoi READ tuoi WRITE setTuoi NOTIFY tuoiChanged)
    Q_PROPERTY(QString diachi READ diachi WRITE setDiachi NOTIFY diachiChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString sodienthoai READ sodienthoai WRITE setSodienthoai NOTIFY sodienthoaiChanged)


public:
    explicit Sinhvien(QObject *parent = nullptr);

QString name() const
{
    return m_name;
}

QString tuoi() const
{
    return m_tuoi;
}

QString diachi() const
{
    return m_diachi;
}

QString email() const
{
    return m_email;
}

QString sodienthoai() const
{
    return m_sodienthoai;
}

signals:

void nameChanged(QString name);

void tuoiChanged(QString tuoi);

void diachiChanged(QString diachi);

void emailChanged(QString email);

void sodienthoaiChanged(QString sodienthoai);

public slots:


void setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
void setTuoi(QString tuoi)
{
    if (m_tuoi == tuoi)
        return;

    m_tuoi = tuoi;
    emit tuoiChanged(m_tuoi);
}

void setDiachi(QString diachi)
{
    if (m_diachi == diachi)
        return;

    m_diachi = diachi;
    emit diachiChanged(m_diachi);
}

void setEmail(QString email)
{
    if (m_email == email)
        return;

    m_email = email;
    emit emailChanged(m_email);
}

void setSodienthoai(QString sodienthoai)
{
    if (m_sodienthoai == sodienthoai)
        return;

    m_sodienthoai = sodienthoai;
    emit sodienthoaiChanged(m_sodienthoai);
}

private:
QString m_name;
QString m_tuoi;
QString m_diachi;
QString m_email;
QString m_sodienthoai;
};

#endif // SINHVIEN_H
