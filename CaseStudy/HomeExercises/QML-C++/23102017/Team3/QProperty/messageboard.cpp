#include <QQuickItem>


#include "messageboard.h"

MessageBoard::MessageBoard(QObject *parent) : QObject(parent)
{

}

QQmlListProperty<Message> MessageBoard::messages()
{
//    return QQmlListProperty<Message>(this, &MessageBoard::appendMessage);
    return QQmlListProperty<Message>(this,this,&MessageBoard::appendMessage,
                                     &MessageBoard::messageCount,
                                     &MessageBoard::message,
                                     &MessageBoard::clearMessages);

}

void MessageBoard::appendMessage(Message *msg)
{
    m_ListMsg.append(msg);
}

int MessageBoard::messageCount() const
{
    return m_ListMsg.count();
}

Message *MessageBoard::message(int index) const
{
    return m_ListMsg.at(index);
}

void MessageBoard::clearMessages()
{
    m_ListMsg.clear();
}

void MessageBoard::appendMessage(QQmlListProperty<Message> *list, Message *message)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    msgBoard->m_ListMsg.append(message);
}

int MessageBoard::messageCount(QQmlListProperty<Message> *list)
{
     MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
     return msgBoard->messageCount();
//    return reinterpret_cast< Message* >(list->data)->messageCount();
}

Message* MessageBoard::message(QQmlListProperty<Message> *list, int index)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    return msgBoard->message(index);
//    return reinterpret_cast< Message* >(list->data)->message(index);
}

void MessageBoard::clearMessages(QQmlListProperty<Message> *list)
{
    MessageBoard* msgBoard = qobject_cast<MessageBoard*>(list->object);
    msgBoard->messageCount();
    //return msgBoard->messageCount();
//    reinterpret_cast< Message* >(list->data)->clearMessages();

}


void MessageBoard::setMessages(QQmlListProperty<Message>)
{
    emit messageChanged();
}

bool MessageBoard::setData(QString content, QString name, QString email)
{
    Message *msg = new Message();
    if(!msg){
        qDebug()<<"msg: ";
        return false;
    }
    MessageBody *body = msg->messageBody();
    if(!body){
        qDebug()<<"body: ";
        return false;
    }
    body->setContent(content);
    MessageAuthor *author = msg->messageAuthor();
    if(!author){
        qDebug()<<"author: ";
        return false;
    }
    author->setName(name);
    author->setEmail(email);
    appendMessage(msg);

    emit messageChanged();
    qDebug()<<"Count: " <<messageCount();
    return true;
}


void MessageBoard::receiveObject(const QVariant &object, int mode)
{
    QQuickItem *item = qobject_cast<QQuickItem*>(object.value<QObject*>());
    if(mode == 1){
        qDebug()<< "width: " << item->width() << " height: " << item->height();
    }
    else {
         qDebug()<< "text from QML: " << item->property("textInput").toString();
    }
}

void MessageBoard::receiveText(QString text)
{
    qDebug()<< "text from QML: " << text;


}


QString MessageBoard::strText() const
{
    return m_Text;
}

void MessageBoard::setStrText(QString text)
{
    if(m_Text == text)
        return;
    m_Text = text;
    qDebug()<< "Binding: " << m_Text;
    //emit strTextChanged();
}
