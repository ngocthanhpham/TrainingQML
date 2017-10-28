#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QStringList listString;
    listString << "A" << "B" << "C";
    qDebug() << listString.size();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myModel", QVariant::fromValue(listString));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
