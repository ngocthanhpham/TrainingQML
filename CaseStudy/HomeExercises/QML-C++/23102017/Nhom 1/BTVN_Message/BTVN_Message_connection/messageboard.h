#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H
#include <QObject>
#include <QVector>
#include <QQmlListProperty>
#include <message.h>
#include <QDebug>

class message_board: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QQmlListProperty<message> list_msgs READ list_msgs WRITE setList_msgs NOTIFY list_msgsChanged)
    Q_PROPERTY(QQmlListProperty<message> list_msgs READ list_msgs NOTIFY list_msgsChanged)
    //QQmlListProperty<message> m_t_list_msgs;
public:
    message_board(QObject *parent = 0);
    QQmlListProperty<message> list_msgs();
    void appendMsg(message*);
    int msgCount() const;
    message *list_msg(int) const;
    void clearmsgs();
    Q_INVOKABLE bool post_msg(const QString &p);
    Q_INVOKABLE bool post_msg_v1(const QString &body,const QString &name, const QString &email);
public slots:
    //    void setList_msgs(QQmlListProperty<message> list_msgs)
    //    {
    //        if (m_t_list_msgs == list_msgs)
    //            return;

    //        m_t_list_msgs = list_msgs;
    //        emit list_msgsChanged(m_t_list_msgs);
    //    }
    void post_msg_v2(const QString &body,const QString &name, const QString &email);
    void post_msg_v3(const QString &body);
    void someSlot(const QString &text);
   // void testconnection(const QString &text);
signals:
    //void list_msgsChanged(QQmlListProperty<message> list_msgs);
    void list_msgsChanged(int arg);
    void someSignal(const QString &text);
private:
    static void appendMsg(QQmlListProperty<message>*, message*);
    static int msgCount(QQmlListProperty<message>*);
    static message* list_msg(QQmlListProperty<message>*, int);
    static void clearmsgs(QQmlListProperty<message>*);
    message* m_msg;
    QList<message*> m_list_msgs;

};


#endif // MESSAGEBOARD_H
