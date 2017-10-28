#include <QDebug>
#include "cmessageboard.h"

CMessageBoard::CMessageBoard(QObject *parent)
: QObject(parent), m_msg(0)
{

}

CMessage *CMessageBoard::msg() const
{
    return m_msg;
}

void CMessageBoard::setMsg(CMessage *msg)
{
    if (m_msg == msg)
        return;

    m_msg = msg;
}

QQmlListProperty<CMessage> CMessageBoard::listMsg()
{
    return QQmlListProperty<CMessage>(this, this,
                &CMessageBoard::appendMessage,
                &CMessageBoard::msgCount,
                &CMessageBoard::lMsg,
                &CMessageBoard::clearMessage);
}


void CMessageBoard::appendMessage(CMessage *m)
{
    m_listMsg.append(m);
}

int CMessageBoard::msgCount() const
{
    return m_listMsg.count();
}

CMessage *CMessageBoard::lMsg(int index) const
{
    return m_listMsg.at(index);
}

void CMessageBoard::clearMessage()
{
    m_listMsg.clear();
}

int CMessageBoard::onButtonClick()
{
    CMessage* msg = new CMessage();
    appendMessage(msg);
    qDebug()<<"append message success";
    emit listMsgchanged();

    return 0;
}

//void CMessageBoard::listMsgchanged()
//{
//    emit listMsgchanged();
//}

//void CMessageBoard::setlistMsg(QQmlListProperty<CMessage> mlist)
//{

//}

void CMessageBoard::appendMessage(QQmlListProperty<CMessage> * list, CMessage *m)
{
    reinterpret_cast<CMessageBoard*>(list->data)->appendMessage(m);
}

void CMessageBoard::clearMessage(QQmlListProperty<CMessage> *list)
{
    reinterpret_cast<CMessageBoard*>(list->data)->clearMessage();
}

int CMessageBoard::msgCount(QQmlListProperty<CMessage>* list)
{
    reinterpret_cast<CMessageBoard*>(list->data)->msgCount();
}

CMessage *CMessageBoard::lMsg(QQmlListProperty<CMessage>* list, int i)
{
    reinterpret_cast<CMessageBoard*>(list->data)->lMsg(i);
}

