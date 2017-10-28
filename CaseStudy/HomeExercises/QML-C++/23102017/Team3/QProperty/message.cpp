#include "message.h"

Message::Message(QObject *parent) : QObject(parent)
{
    m_MessageBody = new MessageBody();
    m_MessageAuthor = new MessageAuthor();
}


//QString Message::content() const
//{
//    return m_Content;
//}


//void Message::setContent(QString content)
//{
//    if(m_Content == content)
//        return;
//    m_Content = content;
//    emit contentChanged();
//}


int Message::count() const
{
    return m_iCount;
}

void Message::setCount(int iCount)
{
    if(m_iCount == iCount)
        return;
    m_iCount = iCount;
    emit countChanged();
}

MessageBody* Message::messageBody() const
{
    return m_MessageBody;
}

void Message::setmessageBody(MessageBody *message)
{
    if(m_MessageBody == message)
        return;
    m_MessageBody = message;
    emit messageBodyChanged();
}

MessageAuthor* Message::messageAuthor() const
{
    return m_MessageAuthor;
}


void Message::setMessageAuthor(MessageAuthor *message)
{
    if(m_MessageAuthor == message)
        return;
    m_MessageAuthor = message;
    emit messageAuthorChanged();
}
