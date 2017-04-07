#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H
#include "studentterm.h"
#include "studentcollection.h"
#include <QList>
#include <QObject>
#include <iostream>
#include <QDebug>


class StudentCollection : public QObject
{
    Q_OBJECT

signals:
    void NotifyEntryRemoved(int index);
    void NotifyEntryAdded(int index);

public:

    StudentCollection() :
        m_studentList(new QList<StudentTerm *>)
    {}
     virtual ~StudentCollection();

    void addEntry(StudentTerm *st);
    void removeEntry(int index);
    void updateEntry(int index, QVariant value, int attribute);
    StudentTerm * getTermAt(int index);
    int size() const;
    const QList<StudentTerm *> *getList() const ;

    friend std::ostream& operator<<(std::ostream &os,const StudentCollection &coll);

private:
    QList<StudentTerm *> * m_studentList;
};

#endif // STUDENTCOLLECTION_H
