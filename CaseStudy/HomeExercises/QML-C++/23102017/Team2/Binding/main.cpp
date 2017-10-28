#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "content.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<CContent>("Content", 1, 0, "Content");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    CContent msgBoard1;
    engine.rootObjects().first()->setProperty("contentObj", QVariant::fromValue(&msgBoard1));

    return app.exec();
}
