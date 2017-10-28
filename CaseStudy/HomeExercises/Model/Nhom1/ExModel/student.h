#ifndef STUDENT_H
#define STUDENT_H
#include <QObject>
#include <QDataStream>

class Student:public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString sex READ sex WRITE setSex NOTIFY sexChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(QString mobilNumber READ mobilNumber WRITE setMobilNumber NOTIFY mobilNumberChanged)

public:
Student();
Student(QString name, QString age,QString sex,QString email,QString address,QString mobilNumber);
QString name() const;
QString age() const;

QString sex() const;

QString email() const;

QString address() const;

QString mobilNumber() const;

public slots:
void setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
void setAge(QString age)
{
    if (m_age == age)
        return;

    m_age = age;
    emit ageChanged(m_age);
}

void setSex(QString sex)
{
    if (m_sex == sex)
        return;

    m_sex = sex;
    emit sexChanged(m_sex);
}

void setEmail(QString email)
{
    if (m_email == email)
        return;

    m_email = email;
    emit emailChanged(m_email);
}

void setAddress(QString address)
{
    if (m_address == address)
        return;

    m_address = address;
    emit addressChanged(m_address);
}

void setMobilNumber(QString mobilNumber)
{
    if (m_mobilNumber == mobilNumber)
        return;

    m_mobilNumber = mobilNumber;
    emit mobilNumberChanged(m_mobilNumber);
}

signals:
void nameChanged(QString name);
void ageChanged(QString age);
void sexChanged(QString sex);
void emailChanged(QString email);
void addressChanged(QString address);
void mobilNumberChanged(QString mobilNumber);
public:

    friend QDataStream &operator<<(QDataStream &stream, const Student &student)
    {
        return stream << (QString)student.name() << (QString)student.age()<< (QString)student.sex() << student.email() << (QString)student.address() << (QString)student.mobilNumber();
    }
    friend QDataStream &operator>>( QDataStream &stream, Student &student )
    {
        QString name, age, sex, email, address, mobilNumber;
        stream >>name >> age >> sex >> email >> address >> mobilNumber;
        student.setName(name);
        student.setAge(age);
        student.setSex(sex);
        student.setEmail(email);
        student.setAddress(address);
        student.setMobilNumber(mobilNumber);
        return stream;
    }
private:
QString m_name;

QString m_age;

QString m_sex;

QString m_email;

QString m_address;

QString m_mobilNumber;
};

#endif // STUDENT_H
