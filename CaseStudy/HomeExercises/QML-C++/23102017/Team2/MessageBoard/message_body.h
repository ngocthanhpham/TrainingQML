#ifndef MESSAGEBODY_H
#define MESSAGEBODY_H

#include <QObject>

class CMessageBody : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChange)

public:
    explicit CMessageBody(QObject *parent = nullptr);

public:
    QString content() const;

signals:
    void contentChange();


public slots:
    void setContent(const QString &sz_value);

private:
    QString m_sz_content_;
};

#endif // MESSAGEBODY_H
