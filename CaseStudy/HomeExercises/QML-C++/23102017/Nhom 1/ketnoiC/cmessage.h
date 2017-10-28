#ifndef CMESSAGE_H
#define CMESSAGE_H

#include <QObject>
#include "cmessagebody.h"
#include "cmessageauthor.h"

class CMessage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(CMessageAuthor* author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(CMessageBody*  body READ body WRITE setBody NOTIFY bodyChanged)


public:
CMessage();
~CMessage();
CMessageAuthor* author() const
{
    return m_author;
}
CMessageBody* body() const
{
    return m_body;
}

public slots:
void setAuthor(CMessageAuthor* author)
{
    if (m_author == author)
        return;

    m_author = author;
    emit authorChanged(m_author);
}
void setBody(CMessageBody* body)
{
    if (m_body == body)
        return;

    m_body = body;
    emit bodyChanged(m_body);
}

signals:
void authorChanged(CMessageAuthor* author);
void bodyChanged(CMessageBody* body);
private:
CMessageAuthor* m_author;

CMessageBody* m_body;
};

#endif // CMESSAGE_H
