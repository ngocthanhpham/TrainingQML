#ifndef MESSAGEAUTHOR_H
#define MESSAGEAUTHOR_H

#include <QObject>

class MessageAuthor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)


public:
    explicit MessageAuthor(QObject *parent = nullptr);

QString name() const
{
    return m_name;
}

QString email() const
{
    return m_email;
}

signals:

    void nameChanged(QString name);

    void emailChanged(QString email);

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }
    void setEmail(QString email)
    {
        if (m_email == email)
            return;

        m_email = email;
        emit emailChanged(m_email);
    }

private:
    QString m_name;

    QString m_email;
};

#endif // MESSAGEAUTHOR_H
