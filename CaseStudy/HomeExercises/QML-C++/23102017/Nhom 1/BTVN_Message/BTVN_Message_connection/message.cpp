#include<messageboard.h>
#include <QDebug>

message_board::message_board(QObject *parent)
: QObject(parent), m_msg(0)
{
}

message::message(QObject *parent): QObject(parent)
{
    m_body = new MessageBody();
    m_body->m_mContent = "default";
    m_author = new MessageAuthor();
    m_author->m_mName = "Test";
    m_author->m_mEmail = "test1.nguyen";
}
message::~message()
{
    if(m_body){
        free(m_body);
    }
    if(m_author){
        free(m_author);
    }
}
bool message_board::post_msg(const QString &p) {
    qDebug() << "SHOW MESSAGE: " << p;
    message *new_message = new message();
    new_message->m_body->m_mContent = p;
    m_list_msgs.append(new_message);
    emit list_msgsChanged(m_list_msgs.count());
}
bool message_board::post_msg_v1(const QString &body,const QString &name, const QString &email) {
    qDebug() << "SHOW MESSAGE v1: " << body;
    message *new_message = new message();
    new_message->m_body->m_mContent = body;
    new_message->m_author->m_mName = name;
    new_message->m_author->m_mEmail = email;
    m_list_msgs.append(new_message);
    emit list_msgsChanged(m_list_msgs.count());
}
void message_board::post_msg_v2(const QString &body,const QString &name, const QString &email) {
    qDebug() << "SHOW MESSAGE V2: " << body << name << email;
    message *new_message = new message();
    new_message->m_body->m_mContent = body;
    new_message->m_author->m_mName = name;
    new_message->m_author->m_mEmail = email;
    m_list_msgs.append(new_message);
    emit list_msgsChanged(m_list_msgs.count());
}
void message_board::post_msg_v3(const QString &body) {
    qDebug() << "SHOW MESSAGE v3: " << body;
    message *new_message = new message();
    new_message->m_body->m_mContent = body;
    m_list_msgs.append(new_message);
    emit list_msgsChanged(m_list_msgs.count());
}
void message_board::someSlot(const QString &text)
{
    QString nText = text;
    emit someSignal(nText);

    qDebug() << "someSlot: "<< nText;
}

void message_board::appendMsg(message* p) {
    m_list_msgs.append(p);
}
int message_board::msgCount() const
{
    return m_list_msgs.count();
}
message *message_board::list_msg(int index) const
{
    return m_list_msgs.at(index);
}
void message_board::clearmsgs() {
    return m_list_msgs.clear();
}

void message_board::appendMsg(QQmlListProperty<message>* list, message* p) {
    reinterpret_cast< message_board* >(list->data)->appendMsg(p);
}

void message_board::clearmsgs(QQmlListProperty<message>* list) {
    reinterpret_cast< message_board* >(list->data)->clearmsgs();
}

message* message_board::list_msg(QQmlListProperty<message>* list, int i) {
    return reinterpret_cast< message_board* >(list->data)->list_msg(i);
}

int message_board::msgCount(QQmlListProperty<message>* list) {
    return reinterpret_cast< message_board* >(list->data)->msgCount();
}
QQmlListProperty<message> message_board::list_msgs()
{
    return QQmlListProperty<message>(this, this,
                           &message_board::appendMsg,
                           &message_board::msgCount,
                           &message_board::list_msg,
                           &message_board::clearmsgs);

}
