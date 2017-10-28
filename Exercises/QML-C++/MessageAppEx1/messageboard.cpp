#include "messageboard.h"
#include "messageauthor.h"
#include "messagebody.h"

MessageBoard::MessageBoard(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<Message> MessageBoard::messages()
{
//    return QQmlListProperty<Message>(this, this,&MessageBoard::appendMessage);
    // phai tra ve 4 con tro ham kia vi QQmlList phai tra ve cac con tro ham do
    return QQmlListProperty<Message>(this,this,&MessageBoard::appendMessage,
                                     &MessageBoard::messageCount,
                                     &MessageBoard::message,
                                     &MessageBoard::clearMessages);
}

void MessageBoard::appendMessage(Message *msg)
{
    m_messages.append(msg);
}

int MessageBoard::messageCount() const
{
    return m_messages.count();
}

Message *MessageBoard::message(int index) const
{
    return m_messages.at(index);
}

void MessageBoard::clearMessages()
{
    m_messages.clear();
}


void MessageBoard::appendMessage(QQmlListProperty<Message> *list, Message *message) // quy uoc doi so cua ham vao phai la: QQmlListProperty<Message> *list, Message *message{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    msgBoard->m_messages.append(message);
}

int MessageBoard::messageCount(QQmlListProperty<Message> *list)
{
     MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
     return msgBoard->messageCount();
//    return reinterpret_cast< Message* >(list->data)->messageCount();

}

Message *MessageBoard::message(QQmlListProperty<Message> *list, int index)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    return msgBoard->message(index);
//    return reinterpret_cast< Message* >(list->data)->message(index);
}

void MessageBoard::clearMessages(QQmlListProperty<Message> *list)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);

    return msgBoard->clearMessages();
//    reinterpret_cast< Message* >(list->data)->clearMessages();

}

void MessageBoard::postMessage(QQmlListProperty<Message>* list)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    Message* msg = new Message();
    MessageBody* msgBody = new MessageBody();
    msgBody->setContent("Hello1");
    MessageAuthor* msgAuthor = new MessageAuthor();
    msgAuthor->setName("B");
    msg->setMessageBody(msgBody);
    msg->setMessageAuthor(msgAuthor);
    msgBoard->m_messages.append(msg);
//    emit messageChanged(list);

}

void MessageBoard::postMessage(QString content)
{
    Message* msg = new Message();
    msg->messageBody()->setContent(content);
//    *msg = m_messages[0];

//    MessageBody*


//    MessageBody* msgBody = new MessageBody();
//    *msgBody = *(msg->messageBody());
//    msgBody->setContent("Hello1");
//    MessageAuthor* msgAuthor = new MessageAuthor();
//    msgAuthor->setName(content);
//    msg->setMessageBody(msgBody);
//    msg->setMessageAuthor(msgAuthor);
    m_messages.append(msg);
    emit messageChanged();
}
