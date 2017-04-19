#include <iostream>
#include "datahandler.h"

DataHandler::DataHandler(QObject *parent) :
    QObject(parent),
    m_pcollection(new StudentCollection)
{
    qDebug() << "DataHandler::DataHandler";
    initialize();
}


DataHandler::~DataHandler()
{
    qDebug() << "DataHandler::~DataHandler";
    delete m_pcollection;
}

const StudentCollection *DataHandler::getCollection() const
{
    qDebug() << "DataHandler::getCollectionList";
    return m_pcollection;
}

void DataHandler::sltRowAdded(const StudentTerm &st)
{

}

void DataHandler::sltRowRemoved(int row)
{

}

void DataHandler::sltStudentInfoChanged(const QModelIndex &index, const QVariant &value, int role)
{

}

void DataHandler::initialize()
{
    qDebug() << "DataHandler::initialize";
    StudentTerm *st = new StudentTerm(891, "Bogdan", "A", "bfrancu@sql.com",
                   9, 8.2, 11, 6.3, 7.2);

    m_pcollection->append(st);
    m_pcollection->append(new StudentTerm(991, "Boris", "2004B", "rrr@rrr.com",
                                            6, 2.4, 5, 8, 9.10));

    //std::cout << *((*m_collection)[1]);//->email().toStdString();
}

void DataHandler::addStudentField(StudentTerm *st)
{
    qDebug() << "DataHandler::addStudentField";
    m_pcollection->append(st);
}

void DataHandler::removeStudentField(int index)
{
    qDebug() << "DataHandler::removeStudentField";
    m_pcollection->removeEntry(index);
}

void DataHandler::updateStudentField(int index, QVariant value, int attribute)
{
    qDebug() << "DataHandler::updateStudentField";
    m_pcollection->updateEntry(index, value, attribute);
}
