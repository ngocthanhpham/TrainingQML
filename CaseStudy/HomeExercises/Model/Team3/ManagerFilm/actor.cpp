#include "actor.h"

Actor::Actor(QObject *parent) : QObject(parent)
{

}

QString Actor::nameActor() const
{
    return m_nameActor;
}

QString Actor::nationalityActor() const
{
    return m_nationalityActor;
}

qint32 Actor::ageActor() const
{
    return m_ageActor;
}

void Actor::setnameActor(QString NameActor)
{
    if (m_nameActor == NameActor)
        return;

    m_nameActor = NameActor;
    emit nameActorChanged(m_nameActor);
}

void Actor::setnationalityActor(QString NationalityActor)
{
    if (m_nationalityActor == NationalityActor)
        return;

    m_nationalityActor = NationalityActor;
    emit nationalityActorChanged(m_nationalityActor);
}

void Actor::setageActor(qint32 AgeActor)
{
    if (m_ageActor == AgeActor)
        return;

    m_ageActor = AgeActor;
    emit ageActorChanged(m_ageActor);
}
