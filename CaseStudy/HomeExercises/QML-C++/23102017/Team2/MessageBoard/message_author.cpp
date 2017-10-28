#include "message_author.h"

CMessageAuthor::CMessageAuthor(QObject *parent) : QObject(parent)
{

}

QString CMessageAuthor::name() const
{
    return this->m_sz_name_;
}

QString CMessageAuthor::email() const
{
    return this->m_sz_email_;
}

void CMessageAuthor::setName(const QString &sz_value)
{
    if (this->m_sz_name_ == sz_value)
        return;

    this->m_sz_name_ = sz_value;
    emit nameChange();
}

void CMessageAuthor::setEmail(const QString &sz_value)
{
    if (this->m_sz_email_ == sz_value)
        return;

    this->m_sz_email_ = sz_value;
    emit emailChange();
}
