#include "message.h"

CMessage::CMessage(QObject *parent) : QObject(parent)
{
    p_author_ = new CMessageAuthor();
    p_body_ = new CMessageBody();
}

CMessage::~CMessage()
{
    delete p_author_;
    p_author_ = NULL;
    delete p_body_;
    p_body_ = NULL;
}

CMessageAuthor *CMessage::author() const
{
     return this->p_author_;
}

CMessageBody *CMessage::body() const
{
    return this->p_body_;
}

void CMessage::setAuthor(CMessageAuthor *p_value)
{
    this->p_author_ = p_value;
    emit authorChanged();
}

void CMessage::setBody(CMessageBody *p_value)
{
    this->p_body_ = p_value;
    emit bodyChanged();
}
