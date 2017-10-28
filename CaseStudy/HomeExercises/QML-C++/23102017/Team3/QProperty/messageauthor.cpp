#include "messageauthor.h"

MessageAuthor::MessageAuthor(QObject *parent) : QObject(parent)
{

}

QString MessageAuthor::name() const
{
    return m_Name;
}
QString MessageAuthor::email() const
{
    return m_Email;
}

void MessageAuthor::setName(QString name)
{
    if(m_Name == name)
        return;
    m_Name = name;
    emit nameChanged();
}
void MessageAuthor::setEmail(QString email)
{
    if(m_Email == email)
        return;
    m_Email = email;
    emit emailChanged();
}
