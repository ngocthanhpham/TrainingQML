#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickView>
#include <QQuickItem>

#include "message.h"
#include "messageboard.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    qmlRegisterType<Message>("sample", 1, 0, "Message");
    qmlRegisterType<MessageBody>("sample", 1, 0, "MessageBody");
    qmlRegisterType<MessageAuthor>("sample", 1, 0, "MessageAuthor");
    qmlRegisterType<MessageBoard>("sample", 1, 0, "MessageBoard");

    MessageBoard msgBoard;


    QQuickView view;

    //QObject::connect(rootObj, SIGNAL())
    //view.engine()->rootContext()->setContextProperty("msgBoard", &msgBoard);
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *rootObj = view.rootObject();
    rootObj->setProperty("msgBoard", QVariant::fromValue(&msgBoard));
    QObject::connect(rootObj, SIGNAL(postSignal(QString, QString, QString)), &msgBoard, SLOT(setData(QString, QString, QString)));
    QObject::connect(rootObj, SIGNAL(postSignalObject(QVariant, int)), &msgBoard, SLOT(receiveObject(QVariant, int)));
    QObject::connect(rootObj, SIGNAL(postSignalText(QString)), &msgBoard, SLOT(receiveText(QString)));
    view.show();



    return app.exec();
}
