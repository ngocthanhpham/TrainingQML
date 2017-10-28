#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString avatar READ avatar WRITE setAvatar NOTIFY avatarChanged)

public:
    User();
    QString name() const
    {
        return m_name;
    }

    QString avatar() const
    {
        return m_avatar;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }

    void setAvatar(QString avatar)
    {
        if (m_avatar == avatar)
            return;

        m_avatar = avatar;
        emit avatarChanged(m_avatar);
    }

signals:
    void nameChanged(QString name);

    void avatarChanged(QString avatar);

private:

    QString m_name;
    QString m_avatar;
};

#endif // USER_H
