#ifndef MESSAGEBODY_H
#define MESSAGEBODY_H

#include <QObject>

class MessageBody : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)


public:
    explicit MessageBody(QObject *parent = nullptr);

    QString content() const
    {
        return m_content;
    }

signals:

    void contentChanged(QString content);

public slots:
    void setContent(QString content)
    {
        if (m_content == content)
            return;

        m_content = content;
        emit contentChanged(m_content);
    }

private:
    QString m_content;
};

#endif // MESSAGEBODY_H
