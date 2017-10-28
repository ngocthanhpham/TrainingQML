#include "message_body.h"

CMessageBody::CMessageBody(QObject *parent) : QObject(parent)
{

}

QString CMessageBody::content() const
{
    return this->m_sz_content_;
}

void CMessageBody::setContent(const QString &sz_value)
{
    if(this->m_sz_content_ != sz_value)
    {
        this->m_sz_content_ = sz_value;
        emit contentChange();
    }
}
