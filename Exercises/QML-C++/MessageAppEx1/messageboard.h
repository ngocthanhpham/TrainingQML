#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

#include "message.h"

class MessageBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Message> messages READ messages WRITE setMessages NOTIFY messageChanged)


public:
    explicit MessageBoard(QObject *parent = nullptr);

    QQmlListProperty<Message> messages();
public:
    void appendMessage(Message*);
    int messageCount() const;
    Message *message(int) const;
    void clearMessages();

public slots:
    void setMessages(QQmlListProperty<Message> messages);

signals:
    void messageChanged(/*QQmlListProperty<Message>* messages*/);

private:
    static void appendMessage(QQmlListProperty<Message> *list, Message* message);
    static int messageCount(QQmlListProperty<Message>*);
    static Message* message(QQmlListProperty<Message>*, int);
    static void clearMessages(QQmlListProperty<Message>*);

//signals:
//    void messageChanged();

public slots:
    void postMessage(QQmlListProperty<Message>*);
    void postMessage(QString content);

private:
    QList<Message*> m_messages;
};

#endif // MESSAGEBOARD_H
