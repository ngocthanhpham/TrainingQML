#include "filmboard.h"

void FilmBoard::appendFilm(QQmlListProperty<Film> *lpFilm, Film *film)
{
    FilmBoard *fb = qobject_cast<FilmBoard*>(lpFilm->object);
    fb->appendFilm(film);
}

int FilmBoard::countFilm(QQmlListProperty<Film> *lpFilm)
{
    FilmBoard *fb = qobject_cast<FilmBoard*>(lpFilm->object);
    return fb->countFilm();
}

Film *FilmBoard::getFilm(QQmlListProperty<Film> *lpFilm, int index)
{
    FilmBoard *fb = qobject_cast<FilmBoard*>(lpFilm->object);
    return fb->getFilm(index);
}

void FilmBoard::clearFilm(QQmlListProperty<Film> *lpFilm)
{
    FilmBoard *fb = qobject_cast<FilmBoard*>(lpFilm->object);
    fb->clearFilm();
}

void FilmBoard::appendFilm(Film *f)
{
    m_lfilm.append(f);
}

int FilmBoard::countFilm()
{
    return m_lfilm.count();
}

Film *FilmBoard::getFilm(int index)
{
    return m_lfilm.at(index);
}

void FilmBoard::clearFilm()
{
    m_lfilm.clear();
}

FilmBoard::FilmBoard(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 5; i++){
        Film *film = new Film();
        film->setName("Default");
        film->setyom(2017);
        film->setpb(1000);
        m_lfilm.append(film);
    }
}

QQmlListProperty<Film> FilmBoard::listFilm()
{
    qDebug() << "Size of listFilm: " << m_lfilm.size();
    return QQmlListProperty<Film>(this, this, &FilmBoard::appendFilm,
                                  &FilmBoard::countFilm,
                                  &FilmBoard::getFilm,
                                  &FilmBoard::clearFilm);
}

void FilmBoard::insertFilm()
{
    Film *film = new Film();
    film->setName("Default");
    film->setyom(2017);
    m_lfilm.append(film);
    emit listFilmChanged(m_listFilm);
}

void FilmBoard::removeFilm(int index)
{
    m_lfilm.removeAt(index);
    qDebug() << "Remove film at index: " << index;
    emit listFilmChanged(m_listFilm);
}

void FilmBoard::removeFilm(QVariant data)
{
    qDebug() << "FilmBoard::removeFilm(QVariant data) " << data;
    FilmBoard *filmBoard = qvariant_cast<FilmBoard*>(data);
    if(filmBoard->countFilm() > 0){
        filmBoard->clearFilm();
    }
    emit listFilmChanged(m_listFilm);
}

void FilmBoard::receiveMsg(QString msg)
{
      qDebug() << "Received message: " << msg;
}

void FilmBoard::setlistFilm(QQmlListProperty<Film> listFilm)
{
    if (m_listFilm == listFilm)
        return;

    m_listFilm = listFilm;
    emit listFilmChanged(m_listFilm);
}
