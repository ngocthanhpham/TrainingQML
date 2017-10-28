#include "message_board.h"

CMessageBoard::CMessageBoard(QObject *parent) : QObject(parent)
{
    // initData();
}

CMessageBoard::~CMessageBoard()
{
    for(int i = 0; i < vt_message_.count(); i++)
    {
        delete vt_message_.at(i);
    }
    vt_message_.clear();
}

QQmlListProperty<CMessage> CMessageBoard::messages()
{
    return QQmlListProperty<CMessage>(this, vt_message_);
}

void CMessageBoard::append(CMessage *p_value)
{
    vt_message_.append(p_value);
}

void CMessageBoard::erase(const CMessage *p_value)
{
    qDebug("This is erase functions");
}

CMessage *CMessageBoard::find(const QString szName, const QString szEmail, const QString szContent)
{
    qDebug("This is find text functions");
    return NULL;
}

void CMessageBoard::find(const CMessage *objSource)
{
    qDebug("This is find object functions");
    //return NULL;
}

void CMessageBoard::clear()
{
    qDebug("This is clear functions");
    vt_message_.clear();
}

void CMessageBoard::count()
{
    qDebug("This is count functions");
}

void CMessageBoard::addNew()
{
    qDebug("This is add functions");
    CMessage *p_mess = new CMessage();
    QString szCount = " ";//QString::number(count());

    QString text = "new name" + szCount;
    p_mess->author()->setName(text);
    text = "new email" + szCount;
    p_mess->author()->setEmail(text);
    text = "new content" + szCount;
    p_mess->body()->setContent(text);
    append(p_mess);

    emit messagesChanged();
}

void CMessageBoard::initData()
{
    CMessage *p_mess1 = new CMessage();
    p_mess1->author()->setName("name init 1");
    p_mess1->author()->setEmail("email init 1");
    p_mess1->body()->setContent("content init 1");
    //vt_message_.append(p_mess1);
    append(p_mess1);

    CMessage *p_mess2 = new CMessage();
    p_mess2->author()->setName("name init 2");
    p_mess2->author()->setEmail("email init 2");
    p_mess2->body()->setContent("content init 2");
    vt_message_.append(p_mess2);

    CMessage *p_mess3 = new CMessage();
    p_mess3->author()->setName("name init 3");
    p_mess3->author()->setEmail("email init 3");
    p_mess3->body()->setContent("content init 3");
    vt_message_.append(p_mess3);
}


