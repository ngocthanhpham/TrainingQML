#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include "message_author.h"
#include "message_body.h"

class CMessage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CMessageAuthor* author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(CMessageBody* body READ body WRITE setBody NOTIFY bodyChanged)

public:
    explicit CMessage(QObject *parent = nullptr);
    ~CMessage();

public:
    CMessageAuthor *author() const;
    CMessageBody *body() const;

signals:
    void authorChanged();
    void bodyChanged();

public slots:
    void setAuthor( CMessageAuthor *p_value);
    void setBody( CMessageBody *p_value);

private:
    CMessageAuthor *p_author_;
    CMessageBody *p_body_;
};

#endif // MESSAGE_H
