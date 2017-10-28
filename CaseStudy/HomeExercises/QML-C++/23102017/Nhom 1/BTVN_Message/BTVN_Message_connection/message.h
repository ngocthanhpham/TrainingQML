#ifndef MESSAGE_H
#define MESSAGE_H
#include <QObject>
#include <QQmlListProperty>
#include <messagebody.h>
#include <messageauthor.h>

class message: public QObject
{
    Q_OBJECT
    Q_PROPERTY(MessageBody* body READ body WRITE setBody NOTIFY bodyChanged)
    Q_PROPERTY(MessageAuthor* author READ author WRITE setAuthor NOTIFY authorChanged)


public:
     explicit message(QObject *parent = 0);
    ~message();

    MessageBody* m_body;

    MessageAuthor* m_author;
    MessageBody* body() const
    {
        return m_body;
    }
    MessageAuthor* author() const
    {
        return m_author;
    }

public slots:
    void setBody(MessageBody* body)
    {
        if (m_body == body)
            return;

        m_body = body;
        emit bodyChanged(m_body);
    }
    void setAuthor(MessageAuthor* author)
    {
        if (m_author == author)
            return;

        m_author = author;
        emit authorChanged(m_author);
    }

signals:
    void bodyChanged(MessageBody* body);
    void authorChanged(MessageAuthor* author);
};


#endif // MESSAGE_H
