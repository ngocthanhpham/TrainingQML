#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H
//#include <QObject>
#include <QAbstractListModel>
//#include <memory>
//#include <QStringList>

//#include "student.h"
class Student;

class StudentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum LIST_STU_PRO
    {
        STU_NAME = Qt::UserRole + 1,
        STU_AGE,
        STU_SEX,
        STU_EMAIL,
        STU_ADDRESS,
        STU_NUMBER
    };

    StudentModel(QObject *parent = 0);

    //Abtract Item Interface

    void addStudent (const Student &student);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Student*> m_listStudent;
    QHash<int, QByteArray> m_nameRoles;
public slots:
    void addstudent(const QVariant &stud);
    void delStudent(const int i);
    void onSendTblIndex(const int i);
    void modifyStudent(const QVariant &stud,const int i);
signals:
    void updateUi(QString name, QString age,QString sex,QString email,QString address,QString mobilNumber);
};

#endif // STUDENTMODEL_H
