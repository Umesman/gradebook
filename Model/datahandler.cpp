#include <iostream>
#include "datahandler.h"

DataHandler::DataHandler(QObject *parent) :
    QObject(parent),
    m_collection(new StudentCollection)
{
    qDebug() << "DataHandler::DataHandler";
    initialize();
}


DataHandler::~DataHandler()
{
    qDebug() << "DataHandler::~DataHandler";
    delete m_collection;
}

const QList<StudentTerm *> *DataHandler::getCollectionList() const
{
    qDebug() << "DataHandler::getCollectionList";
    return m_collection->getList();
}

void DataHandler::initialize()
{
    qDebug() << "DataHandler::initialize";
    StudentTerm *st = new StudentTerm(891, "Bogdan", "2003A", "bogdan.francu6@gmail.com",
                   9, 8.2, 11, 6.3, 7.2);

    m_collection->addEntry(st);
    m_collection->addEntry(new StudentTerm(991, "RRR", "2004B", "rrr@rrr.com",
                                            6, 2.4, 5, 8, 9.10));

    //std::cout << *((*m_collection)[1]);//->email().toStdString();
}

void DataHandler::addStudentField(StudentTerm *st)
{
    qDebug() << "DataHandler::addStudentField";
    m_collection->addEntry(st);
}

void DataHandler::removeStudentField(int index)
{
    qDebug() << "DataHandler::removeStudentField";
    m_collection->removeEntry(index);
}

void DataHandler::updateStudentField(int index, QVariant value, int attribute)
{
    qDebug() << "DataHandler::updateStudentField";
    m_collection->updateEntry(index, value, attribute);
}
