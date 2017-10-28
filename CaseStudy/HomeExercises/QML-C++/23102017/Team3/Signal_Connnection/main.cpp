#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "csingnal_connection.h"
#include <QObject>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    CSingnal_Connection myclass;
    QObject *item= engine.rootObjects().first();
    QObject::connect(item,SIGNAL(testsignal(QString)), &myclass,SLOT(Csignal(QString)));

    engine.rootContext()->setContextProperty("msgconnection",&myclass);
    return app.exec();
}
