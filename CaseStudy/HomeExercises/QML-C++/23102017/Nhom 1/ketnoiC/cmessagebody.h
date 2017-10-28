#ifndef CMESSAGEBODY_H
#define CMESSAGEBODY_H

#include <QObject>
#include <QDebug>

class CMessageBody:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
public:
    CMessageBody();
    ~CMessageBody();
    QString content() const
    {
        return m_Content;
    }
public slots:
    void setContent(QString Content)
    {
        if (m_Content == Content)
            return;

        m_Content = Content;
        qDebug()<< m_Content;
        emit contentChanged(m_Content);
    }
signals:
    void contentChanged(QString Content);
private:
    QString m_Content;
};

#endif // CMESSAGEBODY_H
