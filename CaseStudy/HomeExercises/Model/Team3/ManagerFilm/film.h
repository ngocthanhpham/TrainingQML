#ifndef FILM_H
#define FILM_H

#include <QObject>
#include "director.h"
#include "actor.h"

class Film : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Director* mDirector READ mDirector WRITE setmDirector NOTIFY mDirectorChanged)
    Q_PROPERTY(Actor* mActor READ mActor WRITE setmActor NOTIFY mActorChanged)
    Q_PROPERTY(qint32 yom READ yom WRITE setyom NOTIFY yomChanged)
    Q_PROPERTY(qint32 pb READ pb WRITE setpb NOTIFY pbChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

private:

    Director* m_mDirector;

    Actor* m_mActor;

    qint32 m_yom;

    qint32 m_pb;

    QString m_name;

public:
    Film(QObject *parent = nullptr);

    ~Film();

    Director* mDirector() const;

    Actor* mActor() const;

    qint32 yom() const;

    qint32 pb() const;

    QString name() const;

signals:

    void mDirectorChanged(Director* mDirector);

    void mActorChanged(Actor* mActor);

    void yomChanged(qint32 yom);

    void pbChanged(qint32 pb);

    void nameChanged(QString name);

public slots:

    void setmDirector(Director* mDirector);
    void setmActor(Actor* mActor);
    void setyom(qint32 yom);
    void setpb(qint32 pb);
    void setName(QString name);
};

#endif // FILM_H
