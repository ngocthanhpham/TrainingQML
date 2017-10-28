#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QHostInfo>

#include "broadcast/message.h"
#include "broadcast/receiver.h"

#include "chat/messagecontroller.h"
#include "chat/messagemodel.h"
#include "chat/user.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // register QML type
    qmlRegisterType<MessageModel>("chat.messagemodel",1,0,"MessageModel");
    qmlRegisterType<Message>("chat.message",1,0,"Message");
    qmlRegisterType<User>("chat.user",1,0,"User");

    qDebug() << QHostInfo::localDomainName() << "; " << QHostInfo::localHostName();
    QHostInfo hostInfo;
    qDebug() << hostInfo.localHostName() << ";" << hostInfo.hostName();

    QString name = qgetenv("USER");
    if (name.isEmpty())
        name = qgetenv("USERNAME");

    User user;
    user.setName(name);

    QQmlApplicationEngine engine;
    // set context property
    engine.rootContext()->setContextProperty("user", QVariant::fromValue(&user));
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    qDebug() << engine.rootObjects() << " ; " << engine.rootObjects().size();
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* rootObj = engine.rootObjects().first();

    Receiver recv;

    // setProperty
    MessageController* messageController = new MessageController(rootObj->findChild<QObject*>("conversationPage"));
    recv.setController(messageController);
    messageController->joinNetWork(user);

    return app.exec();
}
