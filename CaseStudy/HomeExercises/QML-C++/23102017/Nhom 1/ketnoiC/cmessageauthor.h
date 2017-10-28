#ifndef CMESSAGEAUTHOR_H
#define CMESSAGEAUTHOR_H

#include <QObject>

class CMessageAuthor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString eMail READ eMail WRITE setEMail NOTIFY eMailChanged)

    QString m_name;

    QString m_eMail;

public:
CMessageAuthor();
QString name() const
{
    return m_name;
}
QString eMail() const
{
    return m_eMail;
}

public slots:
void setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
void setEMail(QString eMail)
{
    if (m_eMail == eMail)
        return;

    m_eMail = eMail;
    emit eMailChanged(m_eMail);
}

signals:
void nameChanged(QString name);
void eMailChanged(QString eMail);
};

#endif // CMESSAGEAUTHOR_H
