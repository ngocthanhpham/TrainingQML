#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>

class Actor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nameActor READ nameActor WRITE setnameActor NOTIFY nameActorChanged)
    Q_PROPERTY(QString nationalityActor READ nationalityActor WRITE setnationalityActor NOTIFY nationalityActorChanged)
    Q_PROPERTY(qint32 ageActor READ ageActor WRITE setageActor NOTIFY ageActorChanged)
    QString m_nameActor;

    QString m_nationalityActor;

    qint32 m_ageActor;

public:
    explicit Actor(QObject *parent = nullptr);

    QString nameActor() const;

    QString nationalityActor() const;

    qint32 ageActor() const;

signals:

    void nameActorChanged(QString nameActor);

    void nationalityActorChanged(QString nationalityActor);

    void ageActorChanged(qint32 ageActor);

public slots:
    void setnameActor(QString nameActor);
    void setnationalityActor(QString nationalityActor);
    void setageActor(qint32 ageActor);
};

#endif // ACTOR_H
