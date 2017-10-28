#ifndef MESSAGEAUTHOR_H
#define MESSAGEAUTHOR_H
#include <QObject>

class MessageAuthor: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mName READ mName WRITE setMName NOTIFY mNameChanged)
    Q_PROPERTY(QString mEmail READ mEmail WRITE setMEmail NOTIFY mEmailChanged)

public:
    QString m_mName;
    QString m_mEmail;
    QString mName() const
    {
        return m_mName;
    }
    QString mEmail() const
    {
        return m_mEmail;
    }

public slots:
    void setMName(QString mName)
    {
        if (m_mName == mName)
            return;

        m_mName = mName;
        emit mNameChanged(m_mName);
    }
    void setMEmail(QString mEmail)
    {
        if (m_mEmail == mEmail)
            return;

        m_mEmail = mEmail;
        emit mEmailChanged(m_mEmail);
    }

signals:
    void mNameChanged(QString mName);
    void mEmailChanged(QString mEmail);
};
#endif // MESSAGEAUTHOR_H
