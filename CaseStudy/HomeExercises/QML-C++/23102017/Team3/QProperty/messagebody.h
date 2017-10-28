#ifndef MESSAGEBODY_H
#define MESSAGEBODY_H

#include <QObject>

class MessageBody : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)
public:
    explicit MessageBody(QObject *parent = nullptr);
    QString content() const;

signals:
    void contentChanged();

public slots:
    void setContent(QString content);

private:
    QString m_Content;
};

#endif // MESSAGEBODY_H
