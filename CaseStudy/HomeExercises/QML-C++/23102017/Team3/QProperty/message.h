#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include "messagebody.h"
#include "messageauthor.h"

class Message : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(MessageBody *messageBody READ messageBody WRITE setmessageBody NOTIFY messageBodyChanged)
    Q_PROPERTY(MessageAuthor *messageAuthor READ messageAuthor WRITE setMessageAuthor NOTIFY messageAuthorChanged)


public:
    explicit Message(QObject *parent = nullptr);

    //QString content() const;
    int count() const;
    MessageBody *messageBody() const;
    MessageAuthor* messageAuthor() const;

signals:
    //void contentChanged();
    void countChanged();
    void messageBodyChanged();
    void messageAuthorChanged();

public slots:
    //void setContent(QString content);
    void setCount(int iCount);
    void setmessageBody(MessageBody *message);
    void setMessageAuthor(MessageAuthor *message);

private:
    //QString m_Content;
    int m_iCount;
    MessageBody *m_MessageBody;
    MessageAuthor *m_MessageAuthor;
};

#endif // MESSAGE_H
