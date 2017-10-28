#include "content.h"

CContent::CContent(QObject *parent) : QObject(parent)
{

}

QString CContent::content() const
{
    return this->sz_text_;
}

void CContent::setContent(const QString szValue)
{
    this->sz_text_ = szValue;

    emit contentChanged();

    showContent();
}

void CContent::showContent()
{
    std::string std_string = sz_text_.toStdString();
    const char* p_char = std_string.c_str();
    qDebug(p_char);
}
