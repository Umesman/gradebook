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
    StudentTerm *st = new StudentTerm(891, "Bogdan", "Francu", "A", "bfrancu@sql.com",
                   9, 8.2, 11, 6.3, 7.2);

    m_pcollection->append(st);
    m_pcollection->append(new StudentTerm(991, "Boris", "Yeltsin", "A", "rrr@sql.com",
                                            2, 2.4, 5, 8, 6.10));
    m_pcollection->append(new StudentTerm(990, "Becky", "Haughton", "B", "bhaughton@sql.com",
                                            10, 4.7, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(112, "Billy", "Alberic", "C", "balberic@sql.com",
                                            9, 3.97, 7.60, 10, 9.10));
    m_pcollection->append(new StudentTerm(113, "Abraham", "Donar", "D", "adonar@sql.com",
                                            5, 7.3, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(111, "Abygaile", "Brunhild", "A", "abrunhild@sql.com",
                                            6, 2.4, 5, 8, 3.10));
    m_pcollection->append(new StudentTerm(114, "Abner", "Grimhilt", "B", "agrimhilt@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(115, "Aaron", "Gunther", "C", "agunther@sql.com",
                                            6, 2.4, 5, 8, 2.10));
    m_pcollection->append(new StudentTerm(116, "Abel", "Hagen", "D", "ahagen@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(117, "Adair", "Welan", "A", "awelan@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(118, "Adamina", "Wodan", "B", "awodan@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(119, "Adele", "Siegfried", "C", "asiegfried@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(996, "Adolph", "Nerthus", "D", "anerthus@sql.com",
                                            6, 2.4, 5, 8, 1.10));
    m_pcollection->append(new StudentTerm(995, "Agatha", "Lorelei", "A", "alorelei@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(121, "Albert", "Kriemhild", "B", "akriemhild@sql.com",
                                            6, 2.4, 5, 8, 4.10));
    m_pcollection->append(new StudentTerm(122, "Athelstan", "Aodhan", "C", "aaodhan@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(123, "Ragnar", "Aeilil", "D", "raeilil@sql.com",
                                            6, 2.4, 5, 8, 1.10));
    m_pcollection->append(new StudentTerm(124, "Guy", "Daire", "A", "gdaire@sql.com",
                                            6, 2.4, 5, 8, 9.10));
    m_pcollection->append(new StudentTerm(125, "Andrew", "Deirdre", "B", "adeirdre@sql.com",
                                            6, 2.4, 5, 4, 2.10));
    m_pcollection->append(new StudentTerm(126, "Angela", "Feidlimid", "D", "afeidlimid@sql.com",
                                            6, 2.4, 5, 8, 3.10));

    StudentTerm *stefan = new StudentTerm(892, "Stefan", "celMare", "C", "stefan@sql.com", 3,
                       6.03, 2.92, 3.21, 4.80);

    m_pcollection->append(stefan);
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
