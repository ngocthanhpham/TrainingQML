#include "csingnal_connection.h"
#include <QDebug>

CSingnal_Connection::CSingnal_Connection(QObject *parent) : QObject(parent)
{

}

void CSingnal_Connection::Csignal(QString text)
{
    qDebug()<< "signal : "<< text;
}

void CSingnal_Connection::connection1(QString text)
{
    qDebug()<< "connection : "<< text;
}
