#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <QObject>
#include "messagemodel.h"
#include "broadcast/sender.h"
#include "chat/user.h"

class MessageController : public QObject
{
    Q_OBJECT
public:
    MessageController(QObject* rootObject);

public slots:
    void onSendMessage(QVariant data);
    void updateMessage(const Message& msg);
public:
    void setUser(const User& user);
    void joinNetWork(const User& user);

private:
    QObject* mRootObj;
    MessageModel* mModel;
    Sender mSender;
    User mUser;
    QList<QObject*> mListUser;
};

#endif // MESSAGECONTROLLER_H
