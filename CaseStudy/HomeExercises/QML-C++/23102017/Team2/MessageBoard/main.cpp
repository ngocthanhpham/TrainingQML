#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>

#include "message_board.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<CMessageAuthor>("Sample", 1, 0, "CMessageAuthor");
    qmlRegisterType<CMessageBody>("Sample", 1, 0, "CMessageBody");
    qmlRegisterType<CMessage>("Sample", 1, 0, "CMessage");
    qmlRegisterType<CMessageBoard>("Sample", 1, 0, "CMessageBoard");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    Ex1
    CMessageBoard msgBoard1;
    engine.rootObjects().first()->setProperty("msgBoard", QVariant::fromValue(&msgBoard1));

//    Ex2
    QObject *obj1 = engine.rootObjects().first();
    CMessageBoard msgBoard2;
    QObject::connect(obj1, SIGNAL(simpleSignalCount()), &msgBoard2, SLOT(count()));

//    Ex3
    QObject *obj2 = engine.rootObjects().first();
    CMessageBoard msgBoard3;
    QObject::connect(obj2, SIGNAL(signalExposeObject(QVariant)), &msgBoard3, SLOT(find(QVariant)));

    return app.exec();
}
