#ifndef MESSAGE_AUTHOR_H
#define MESSAGE_AUTHOR_H

#include <QObject>

class CMessageAuthor : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChange)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChange)


public:
    explicit CMessageAuthor(QObject *parent = nullptr);

public:
    QString name() const;
    QString email() const;

signals:
    void nameChange();
    void emailChange();

public slots:
    void setName(const QString &sz_value);
    void setEmail(const QString &sz_value);

private:
     QString m_sz_name_;
     QString m_sz_email_;

};

#endif // MESSAGE_AUTHOR_H
