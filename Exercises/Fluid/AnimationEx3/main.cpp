#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/EasingCurves.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    QQuickView view;
    view.setSource(QUrl("qrc:/EasingCurves.qml"));
    view.show();

    return app.exec();
}
