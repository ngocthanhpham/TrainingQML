#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <message.h>
#include <messageboard.h>
#include <messagebody.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<message>("message_test", 1, 0, "Message");
    qmlRegisterType<MessageBody>("MessageBody_test", 1, 0, "MessageBody");
    qmlRegisterType<MessageAuthor>("MessageAuthor_test", 1, 0, "MessageAuthor");
    qmlRegisterType<message_board>("MessageBoard_test", 1, 0, "MessageBoard");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

//    message_board msgBoard;
//    QQuickView view;
//    view.rootContext()->setContextProperty("msgBoard", &msgBoard);
//    view.setSource(QUrl::fromLocalFile(":/MyItem.qml"));
//    QObject *item = view.rootObject();

    message_board msgBoard;
    QObject* rootObj = engine.rootObjects().first();
    rootObj->setProperty("msgBoard", QVariant::fromValue(&msgBoard));

    QObject::connect( rootObj, SIGNAL(add_element(QString)), &msgBoard, SLOT(post_msg_v3(QString)));
    QObject::connect( rootObj, SIGNAL(add_element_v1(QString, QString, QString)), &msgBoard, SLOT(post_msg_v2(QString, QString, QString)));

    //view.show();
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
