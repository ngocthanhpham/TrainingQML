#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include <message.h>
#include <QDebug>

class MessageBoard : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Message> message READ messages WRITE setMessages NOTIFY messageChanged)
    Q_PROPERTY(QString strText READ strText WRITE setStrText NOTIFY strTextChanged)
public:
    explicit MessageBoard(QObject *parent = nullptr);
    QQmlListProperty<Message> messages();
    QString strText() const;

public:
    void appendMessage(Message*);
    int messageCount() const;
    Message *message(int) const;
    void clearMessages();


    Q_INVOKABLE bool postMessage(const QString &msg){
        qDebug() << "Called the c++ method width" << msg;
        //printf("Called the c++ method width: %s", msg);
        return true;
    }

    //Q_INVOKABLE bool setData(QString content, QString name, QString email);

signals:
    void messageChanged();
    void strTextChanged();

public slots:
    void setMessages(QQmlListProperty<Message>);
    bool setData(QString content, QString name, QString email);
    void refresh(){
        qDebug() << "Called the C++ slot";
        //printf("Called the C++ slot");
    }

    void receiveObject(const QVariant &object, int mode);
    void receiveText(QString text);
    void setStrText(QString text);

private:
    static void appendMessage(QQmlListProperty<Message> *list, Message* message);
    static int messageCount(QQmlListProperty<Message>*);
    static Message* message(QQmlListProperty<Message>*, int);
    static void clearMessages(QQmlListProperty<Message>*);

public:
    QString m_Text;
private:
    QList<Message*> m_ListMsg;
};

#endif // MESSAGEBOARD_H
