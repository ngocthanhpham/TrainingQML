#ifndef MESSAGEAUTHOR_H
#define MESSAGEAUTHOR_H

#include <QObject>

class MessageAuthor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
public:
    explicit MessageAuthor(QObject *parent = nullptr);
    QString name() const;
    QString email() const;

signals:
    void nameChanged();
    void emailChanged();

public slots:
    void setName(QString name);
    void setEmail(QString email);

private:
    QString m_Name;
    QString m_Email;
};

#endif // MESSAGEAUTHOR_H
