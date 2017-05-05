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

    // methods to interface with the tcp client socket
    void addStudentField(StudentTerm *st);
    void removeStudentField(int index);
    void updateStudentField(int index, QVariant value, int attribute);

    ~DataHandler();

    const StudentCollection *getCollection() const;

public slots:
    // slots to communicate with the model manager
    void sltRowAdded(const StudentTerm &st);
    void sltRowRemoved(int row);
    void sltStudentInfoChanged(const QModelIndex &index, const QVariant &value, int role);

private:
    void initialize();

    StudentCollection *m_pcollection;
};

#endif // DATAHANDLER_H
