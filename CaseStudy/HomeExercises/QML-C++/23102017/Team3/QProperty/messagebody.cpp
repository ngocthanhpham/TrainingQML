#include "messagebody.h"

MessageBody::MessageBody(QObject *parent) : QObject(parent)
{
}


QString MessageBody::content() const
{
    return m_Content;
}


void MessageBody::setContent(QString content)
{
    if(m_Content == content)
        return;
    m_Content = content;
    emit contentChanged();
}
