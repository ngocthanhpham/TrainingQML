#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "sinhvien.h"
#include "sinhvienmodel.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<Sinhvien>("mySinhvien",1,0,"Sinhvien");
    qmlRegisterType<SinhvienModel>("mySinhvienModel",1,0,"SinhvienModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    SinhvienModel svmodel;
    engine.rootContext()->setContextProperty("svmodel",&svmodel);

//    Sinhvien *sv = new Sinhvien();
//    sv->setName("Nguyen van A");
//    sv->setDiachi("Ha noi");
//    sv->setTuoi("19");
//    sv->setEmail("namgmail.com");
//    sv->setSodienthoai("01649407096");
//    Sinhvien* sv2 = new Sinhvien();
//    sv2->setName("Hung1");
//    sv2->setDiachi("Ha Nam");
//    sv2->setTuoi("20");
//    sv2->setEmail("Hunggmail.com");
//    sv2->setSodienthoai("091534873");

//    svmodel.updatesinhvien(*sv);
//    svmodel.updatesinhvien(*sv2);

   QObject *item = engine.rootObjects().first();
   QObject::connect(item,SIGNAL(sendMessage(QVariant)), &svmodel,SLOT(cppSlot(QVariant)));
   QObject::connect(item,SIGNAL(sendindex(int)), &svmodel,SLOT(Removesinhvien(int)));
   QObject::connect(item,SIGNAL(sendindextable(int)), &svmodel,SLOT(onIndextabelview(int)));


   //test count
    QModelIndex haha;
    qDebug() << "count" <<svmodel.columnCount(haha);
    qDebug() << "count" << svmodel.rowCount(haha);






    return app.exec();
}
