#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class MessageBody;
class MessageAuthor;

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MessageAuthor* messageAuthor READ messageAuthor WRITE setMessageAuthor NOTIFY messageAuthorChanged)
    Q_PROPERTY(MessageBody* messageBody READ messageBody WRITE setMessageBody NOTIFY messageBodyChanged)


public:
    explicit Message(QObject *parent = nullptr);
    ~Message();
MessageAuthor* messageAuthor() const
{
    return m_messageAuthor;
}

MessageBody* messageBody() const
{
    return m_messageBody;
}

signals:

    void messageAuthorChanged(MessageAuthor* messageAuthor);

    void messageBodyChanged(MessageBody* messageBody);

public slots:
    void setMessageAuthor(MessageAuthor* messageAuthor)
    {
        if (m_messageAuthor == messageAuthor)
            return;

        m_messageAuthor = messageAuthor;
        emit messageAuthorChanged(m_messageAuthor);
    }
    void setMessageBody(MessageBody* messageBody)
    {
        if (m_messageBody == messageBody)
            return;

        m_messageBody = messageBody;
        emit messageBodyChanged(m_messageBody);
    }

private:
    MessageAuthor* m_messageAuthor;

    MessageBody* m_messageBody;
};

#endif // MESSAGE_H
