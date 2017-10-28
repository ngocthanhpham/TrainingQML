#include "film.h"

Film::Film(QObject *parent) : QObject(parent)
{
    m_mActor = new Actor();
    m_mActor->setageActor(0);
    m_mActor->setnameActor("Default");
    m_mActor->setnationalityActor("Default");

    m_mDirector = new Director();
    m_mDirector->setageDirector(0);
    m_mDirector->setnameDirector("Default");
    m_mDirector->setnationalityDirector("Default");
}

Film::~Film()
{
    delete m_mActor;
    delete m_mDirector;
}

Director *Film::mDirector() const
{
    return m_mDirector;
}

Actor *Film::mActor() const
{
    return m_mActor;
}

qint32 Film::yom() const
{
    return m_yom;
}

qint32 Film::pb() const
{
    return m_pb;
}

QString Film::name() const
{
    return m_name;
}

void Film::setmDirector(Director *mDirector)
{
    if (m_mDirector == mDirector)
        return;

    m_mDirector = mDirector;
    emit mDirectorChanged(m_mDirector);
}

void Film::setmActor(Actor *mActor)
{
    if (m_mActor == mActor)
        return;

    m_mActor = mActor;
    emit mActorChanged(m_mActor);
}

void Film::setyom(qint32 yom)
{
    if (m_yom == yom)
        return;

    m_yom = yom;
    emit yomChanged(m_yom);
}

void Film::setpb(qint32 pb)
{
    if (m_pb == pb)
        return;

    m_pb = pb;
    emit pbChanged(m_pb);
}

void Film::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
