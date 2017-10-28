#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "message.h"
#include "messageauthor.h"
#include "messagebody.h"
#include "messageboard.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Message>("chat.message",1,0,"Message");
    qmlRegisterType<MessageAuthor>("chat.message",1,0,"MessageAuthor");
    qmlRegisterType<MessageBody>("chat.message",1,0,"MessageBody");
    qmlRegisterType<MessageBoard>("chat.message",1,0,"MessageBoard");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
//    engine.rootContext()->setContextProperty("msgBoard1", QVariant::fromValue(&msgBoard));
    MessageBoard msgBoard;
    QObject* rootObj = engine.rootObjects().first();
    QObject* rootObj1 = rootObj->findChild<QObject*>("test");
    rootObj1->setProperty("msgBoard1", QVariant::fromValue(&msgBoard));

    QObject::connect(rootObj, SIGNAL(postMessage(QString)), &msgBoard, SLOT(postMessage(QString)));

    QQuickView view;
    view.rootObject();

    return app.exec();
}
