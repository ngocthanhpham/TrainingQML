#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    */
    // qrc:/createRectange.qml

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/createRectange.qml")));
    view.show();
    return app.exec();
}
