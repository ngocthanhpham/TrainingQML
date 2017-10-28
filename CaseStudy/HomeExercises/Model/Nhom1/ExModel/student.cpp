#include "student.h"

Student::Student()
{

}

Student::Student(QString name, QString age, QString sex, QString email, QString address, QString mobilNumber)
{
    m_name = name;

    m_age = age;

    m_sex = sex;

    m_email = email;

    m_address = address;

    m_mobilNumber = mobilNumber;
}

QString Student::name() const
{
    return m_name;
}

QString Student::age() const
{
    return m_age;
}

QString Student::sex() const
{
    return m_sex;
}

QString Student::email() const
{
    return m_email;
}

QString Student::address() const
{
    return m_address;
}

QString Student::mobilNumber() const
{
    return m_mobilNumber;
}
