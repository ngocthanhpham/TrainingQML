#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

#include "student.h"
#include "studentmodel.h"

int main(int argc, char *argv[])
{
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<Student>("sinhvien",1,0,"Student");
    qmlRegisterType<StudentModel>("sinhvien",1,0,"StudentModel");

    StudentModel stuModel;
    stuModel.addStudent(Student("hung","35","nam","hung@lge","hanoi","012345"));
    stuModel.addStudent(Student("hai","20","nu","hai@lge","hanoi","6789"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

//    QObject obj = engine.rootObjects().first();
//    obj.setProperty("stuModel",QVariant::fromValue(&stuModel));

    engine.rootContext()->setContextProperty("stuModel",QVariant::fromValue(&stuModel));
    QObject *obj = engine.rootObjects().first();
    QObject::connect(obj,SIGNAL(themSv(QVariant)),&stuModel,SLOT(addstudent(QVariant)));
    QObject::connect(obj,SIGNAL(xoaSv(int)),&stuModel,SLOT(delStudent(int)));
    QObject::connect(obj,SIGNAL(sendTblIndex(int)),&stuModel,SLOT(onSendTblIndex(int)));
    QObject::connect(obj,SIGNAL(suaSv(QVariant,int)),&stuModel,SLOT(modifyStudent(QVariant,int)));

//    QQuickView view;
//    view.setResizeMode(QQuickView::SizeRootObjectToView);
//    QQmlContext *ctxt = view.rootContext();
//    ctxt->setContextProperty("stuModel",&stuModel);
//    view.setSource(QUrl("qrc:view.qml"));
//    view.show();

    return app.exec();
}
