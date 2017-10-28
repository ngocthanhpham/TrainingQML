#include "cmessage.h"

CMessage::CMessage()
{
    m_author = new CMessageAuthor();
    m_author->setEMail("new Emal");
    m_author->setName("New Name");
    m_body = new CMessageBody();
    m_body->setContent("Add content");
}

CMessage::~CMessage()
{
    delete m_author;
    m_author = NULL;
    delete m_body;
    m_body = NULL;
}
