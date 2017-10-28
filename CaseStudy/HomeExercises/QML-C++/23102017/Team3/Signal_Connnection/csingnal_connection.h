#ifndef CSINGNAL_CONNECTION_H
#define CSINGNAL_CONNECTION_H

#include <QObject>

class CSingnal_Connection : public QObject
{
    Q_OBJECT

public:
    explicit CSingnal_Connection(QObject *parent = nullptr);

signals:


public slots:

    void Csignal (QString text);
     void connection1 (QString text);

};

#endif // CSINGNAL_CONNECTION_H
