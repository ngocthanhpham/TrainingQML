#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QQmlListProperty>

#include "message.h"
#include "message_body.h"

class CMessageBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CMessage> messages READ messages NOTIFY messagesChanged)

public:
    explicit CMessageBoard(QObject *parent = nullptr);
    ~CMessageBoard();

public:
    QQmlListProperty<CMessage> messages();
    void initData();

signals:
    void messagesChanged();

public slots:

    void addNew();
    void count();
    CMessage *find(const QString szName, const QString szEmail, const QString szContent);
    void find(const CMessage *objSource);
    void erase(const CMessage *p_value);
    void append(CMessage *p_value);
    void clear();

private:
    QList<CMessage*> vt_message_;
};

#endif // MESSAGEBOARD_H
