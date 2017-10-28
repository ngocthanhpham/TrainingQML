#ifndef CONTENT_H
#define CONTENT_H

#include <QObject>

class CContent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content READ content WRITE setContent NOTIFY contentChanged)

public:
    explicit CContent(QObject *parent = nullptr);

public:
    QString content() const;

signals:
    void contentChanged();

public slots:
    void setContent(const QString szValue);

private:
    void showContent();

private:
    QString sz_text_;
};

#endif // CONTENT_H
