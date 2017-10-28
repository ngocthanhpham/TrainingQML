#include "studentmodel.h"
#include "student.h"
#include <QDebug>
#include <QObject>

StudentModel::StudentModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_nameRoles[STU_NAME] = "name";
    m_nameRoles[STU_AGE] = "age";
    m_nameRoles[STU_SEX] = "sex";
    m_nameRoles[STU_EMAIL] = "email";
    m_nameRoles[STU_ADDRESS] = "address";
    m_nameRoles[STU_NUMBER] = "mobilNumber";

}

void StudentModel::addstudent(const QVariant &stud)
{
    qDebug() << "StudentModel::add student slot";
    Student *stu = qobject_cast<Student*>(stud.value<QObject*>());
    addStudent(*stu);
//    beginInsertRows(QModelIndex(),rowCount(),rowCount());
//    Student* sv = new Student;
//    sv->setName(stu->name());
//    sv->setAge(stu->age());
//    sv->setSex(stu->sex());
//    sv->setEmail(stu->email());
//    sv->setAddress(stu->address());
//    sv->setMobilNumber(stu->mobilNumber());
//    m_listStudent.insert(0,sv);
//    endInsertRows();
    //    emit layoutChanged();
}

void StudentModel::delStudent(const int i)
{
    if(i<0 || i >= m_listStudent.count())
        return ;
    m_listStudent.removeAt(i);
    emit layoutChanged();
}

void StudentModel::onSendTblIndex(const int i)
{
    if(i<0 || i >= m_listStudent.count())
        return ;
    Student* sv = m_listStudent.at(i);
    emit updateUi(sv->name(),sv->age(),sv->sex(),sv->email(),sv->address(),sv->mobilNumber());

}

void StudentModel::modifyStudent(const QVariant &stud, const int i)
{
    qDebug()<< "C++: modify";
    if(i<0 || i >= m_listStudent.count())
        return ;
    Student *stu = qobject_cast<Student*>(stud.value<QObject*>());
    Student* sv = m_listStudent.at(i);
    sv->setName(stu->name());
    sv->setAge(stu->age());
    sv->setSex(stu->sex())  ;
    sv->setEmail(stu->email()) ;
    sv->setAddress(stu->address());
    sv->setMobilNumber(stu->mobilNumber()) ;
    emit layoutChanged();
//    qDebug()<< "C++: end modify"<<sv->name() << stu->name();
}

void StudentModel::addStudent(const Student &student)
{
    qDebug() << "StudentModel::add student";
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    Student* sv = new Student;
    sv->setName(student.name());
    sv->setAge(student.age());
    sv->setSex(student.sex());
    sv->setEmail(student.email());
    sv->setAddress(student.address());
    sv->setMobilNumber(student.mobilNumber());
    m_listStudent.insert(rowCount(),sv);
    endInsertRows();
    emit layoutChanged();
}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listStudent.count();
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row() >= m_listStudent.count())
        return QVariant();
    int row = index.row();
//    const Student &student = m_listStudent[index.row()];
    const Student *student = m_listStudent.at(row);


    switch (role) {
    case STU_NAME:
        return student->name();
        break;
    case STU_AGE:
        return student->age();
        break;
    case STU_SEX:
        return student->sex();
        break;
    case STU_EMAIL:
        return student->email();
        break;
    case STU_ADDRESS:
        return student->address();
        break;
    case STU_NUMBER:
        return student->mobilNumber();
        break;
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> StudentModel::roleNames() const
{
//    QHash<int, QByteArray> roles;
//    roles[STU_NAME] = "name";
//    roles[STU_AGE] = "age";
//    roles[STU_SEX] = "sex";
//    roles[STU_EMAIL] = "email";
//    roles[STU_ADDRESS] = "address";
//    roles[STU_NUMBER] = "mobilNumber";
    return m_nameRoles;
}
