#include "messagecontroller.h"
#include "broadcast/message.h"
#include <QDebug>

MessageController::MessageController(QObject* rootObject)
    :mRootObj(rootObject)
{
    mModel = new MessageModel;

    mRootObj->setProperty("conversionModel", QVariant::fromValue(mModel));
    mRootObj->setProperty("userList", QVariant::fromValue(mListUser));

    connect(mRootObj, SIGNAL(sendMessage(QVariant)), this, SLOT(onSendMessage(QVariant)));
}

void MessageController::onSendMessage(QVariant data)
{
    Message* msg = qvariant_cast<Message*>(data);
    if (msg->content() != "")
    {
        mSender.broadcastDatagram(*msg);
        qDebug() << msg->content();
    }
}

void MessageController::updateMessage(const Message &msg)
{
//    if(mUser.name() != msg.name())
    qDebug() << msg.join();
    if(msg.join())
        mModel->updateMessage(msg);
    else
    {
        bool found = false;

        foreach (QObject* var, mListUser) {
            User* user = (User*)var;
            if(user->name() == msg.name()){
                found = true;
                break;
            }
        }

        if(!found){
            User* user = new User();
            user->setName(msg.name());
            mListUser.push_back(user);
            mRootObj->setProperty("userList", QVariant::fromValue(mListUser));
            QString name = qgetenv("USER");
            if (name.isEmpty())
                name = qgetenv("USERNAME");
            Message msg;
            msg.setName(name);
            msg.setJoin(false);
            mSender.broadcastDatagram(msg);
        }
    }

    if(msg.leave())
    {
        foreach (QObject* var, mListUser) {
            User* user = (User*)var;
            if(user->name() == msg.name()){
                mListUser.removeOne(var);
                break;
            }
        }
        mRootObj->setProperty("userList", QVariant::fromValue(mListUser));
    }
}

void MessageController::setUser(const User &user)
{
//    mUser = user;
    Message msg;
    msg.setName(user.name());
    msg.setJoin(false);
    mSender.broadcastDatagram(msg);
}

void MessageController::joinNetWork(const User& user)
{
    Message msg;
    msg.setName(user.name());
    msg.setJoin(false);
    mSender.broadcastDatagram(msg);
}
