#ifndef CMESSAGEBOARD_H
#define CMESSAGEBOARD_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include "cmessage.h"

class CMessageBoard:public QObject
{
    Q_OBJECT
    Q_PROPERTY(CMessage* msg READ msg WRITE setMsg)
    Q_PROPERTY(QQmlListProperty<CMessage> listMsg READ listMsg NOTIFY listMsgchanged)



//    QQmlListProperty<CMessage> m_listMsg;

public:
    CMessageBoard(QObject *parent = 0);
    CMessage *msg() const;
    void setMsg(CMessage *);

    QQmlListProperty<CMessage> listMsg();
    void appendMessage(CMessage*);
    int msgCount() const;
    CMessage *lMsg(int) const;
    void clearMessage();


public slots:
    int onButtonClick();
//    void setlistMsg(QQmlListProperty<CMessage> mlist);
signals:
    void listMsgchanged();

private:
    static void appendMessage(QQmlListProperty<CMessage>*, CMessage*);
    static int msgCount(QQmlListProperty<CMessage>*);
    static CMessage *lMsg(QQmlListProperty<CMessage>*, int);
    static void clearMessage(QQmlListProperty<CMessage>*);
    CMessage *m_msg;
    QList<CMessage *> m_listMsg;
};

#endif // CMESSAGEBOARD_H
