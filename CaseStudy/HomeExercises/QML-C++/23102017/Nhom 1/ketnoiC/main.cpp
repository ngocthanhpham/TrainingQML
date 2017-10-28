#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "cmessagebody.h"
#include "cmessageauthor.h"
#include "cmessage.h"
#include "cmessageboard.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<CMessageBody>("Chat.message",1,0,"CMessageBody");
    qmlRegisterType<CMessageAuthor>("Chat.message",1,0,"CMessageAuthor");
    qmlRegisterType<CMessage>("Chat.message",1,0,"CMessage");
    qmlRegisterType<CMessageBoard>("Chat.message",1,0,"CMessageBoard");

    // used with main.qml
//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    // used with main2_connection
    CMessageBody m_MessageBody;
    QQuickView view;
    view.rootContext()->setContextProperty("messageBody",&m_MessageBody);
    view.setSource(QUrl(QLatin1String("qrc:/main2_connection.qml")));

    view.show();

    return app.exec();
}
