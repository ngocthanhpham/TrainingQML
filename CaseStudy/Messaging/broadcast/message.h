#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QDataStream>

class Message : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
    Q_PROPERTY(QString owner READ owner WRITE setOwner NOTIFY ownerChanged)
    Q_PROPERTY(QString timestamp READ timestamp WRITE setTimestamp NOTIFY timestampChanged)
    Q_PROPERTY(bool join READ join WRITE setJoin NOTIFY joinChanged)
    Q_PROPERTY(bool leave READ leave WRITE setLeave NOTIFY leaveChanged)
    Q_PROPERTY(int check READ check WRITE setCheck NOTIFY checkChanged)
public:
    Message();

    QString content() const
    {
        return m_content;
    }

    QString name() const
    {
        return m_name;
    }

    QString owner() const
    {
        return m_owner;
    }

    QString timestamp() const
    {
        return m_timestamp;
    }

public slots:

    void setContent(QString content)
    {
        if (m_content == content)
            return;

        m_content = content;
        emit contentChanged(m_content);
    }

    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }

    void setOwner(QString owner)
    {
        if (m_owner == owner)
            return;

        m_owner = owner;
        emit ownerChanged(m_owner);
    }

    void setTimestamp(QString timestamp)
    {
        if (m_timestamp == timestamp)
            return;

        m_timestamp = timestamp;
        emit timestampChanged(m_timestamp);
    }

    void setJoin(bool join)
    {
        if (m_join == join)
            return;

        m_join = join;
        emit joinChanged(m_join);
    }

    void setLeave(bool leave)
    {
        if (m_leave == leave)
            return;

        m_leave = leave;
        emit leaveChanged(m_leave);
    }


    bool join() const
    {
        return m_join;
    }

    bool leave() const
    {
        return m_leave;
    }

    void setCheck(int check)
    {
        if (m_check == check)
            return;

        m_check = check;
        emit checkChanged(m_check);
    }

signals:
//    void idChanged(int id);
    void contentChanged(QString content);

    void nameChanged(QString name);

    void ownerChanged(QString owner);

    void timestampChanged(QString timestamp);

    void joinChanged(bool join);

    void leaveChanged(bool leave);

    void checkChanged(int check);

public:

    friend QDataStream &operator<<(QDataStream &stream, const Message &msg)
    {
        return stream << (QString)msg.name() << (QString)msg.content() << (QString)msg.owner() << msg.join() << (QString)msg.timestamp();
    }
    friend QDataStream &operator>>( QDataStream &stream, Message &msg )
    {
        QString name, content, owner, timestamp;
        bool join;
        stream >> name >> content >> owner >> join >> timestamp;
        msg.setName(name);
        msg.setContent(content);
        msg.setOwner(owner);
        msg.setJoin(join);
        msg.setTimestamp(timestamp);
        return stream;
    }


    int check() const
    {
        return m_check;
    }

private:
//    int m_id;

    QString m_name;

    QString m_content;

    QString m_owner;

    QString m_timestamp;

    bool m_join;
    bool m_leave;
    int m_check;
};


#endif // MESSAGE_H
