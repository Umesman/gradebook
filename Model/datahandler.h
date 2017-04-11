#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QObject>
#include <QDebug>

#include "studentcollection.h"

class DataHandler : public QObject
{
    Q_OBJECT

signals:

public:
    explicit DataHandler(QObject *parent = 0);

    void addStudentField(StudentTerm *st);
    void removeStudentField(int index);
    void updateStudentField(int index, QVariant value, int attribute);

    ~DataHandler();

    const QList<StudentTerm *> *getCollectionList() const;

private:
    void initialize();

    StudentCollection *m_collection;
};

#endif // DATAHANDLER_H
