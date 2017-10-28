#include "message.h"
#include "messagebody.h"
#include "messageauthor.h"

Message::Message(QObject *parent) : QObject(parent)
{
    m_messageBody = new MessageBody();
    m_messageAuthor = new MessageAuthor();

    m_messageBody->setContent("Hello1");
    m_messageAuthor->setName("content");
}

Message::~Message()
{
    delete m_messageBody;
    delete m_messageAuthor;
}
