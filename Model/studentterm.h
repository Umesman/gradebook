#ifndef STUDENTTERM_H
#define STUDENTTERM_H

#include <QString>
#include <QVariant>
#include <QObject>

#include "publicdefinitions.h"

class StudentTerm : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)


private:
    void calculateFinal ();
    double limits(double grade);

    unsigned int m_id;
    QString m_name;
    QString m_group;
    QString m_email;
    unsigned int m_assesments;
    double m_homework1;
    double m_homework2;
    double m_labGrade;
    double m_testGrade;
    double m_finalGrade;

    void setEmail(const QString &email);
    void setAssesments(const int  assesments);
    void setHomework1(const double homework);
    void setHomework2(const double homework);
    void setLabGrade(const double labGrade);
    void setTestGrade(const double testGrade);
    void setGroup(const QString &group);

public:

    // default constructor
    StudentTerm(QObject* parent = 0) :
        QObject(parent),
        m_id {001}, m_name {"Unknown"}, m_email {"default@sql.com"}, m_assesments{1},
        m_homework1{1}, m_homework2{1}, m_labGrade{1}, m_testGrade{1}
    {}

    // general use constructor
    StudentTerm(unsigned int id, QString name, QString group, QString email, unsigned int assessments,
                double homework1, double homework2, double labGrade, double testGrade,
                QObject* parent = 0) :
        QObject(parent),
        m_id {id},
        m_name{name},
        m_group{group},
        m_email{email},
        m_assesments{assessments},
        m_homework1{limits(homework1)},
        m_homework2{limits(homework2)},
        m_labGrade{limits(labGrade)},
        m_testGrade{limits(testGrade)}
    {}

    /*
    StudentTerm(const StudentTerm &st) :
        QObject(st)
    {}*/

    void setName(const QString &name);

    unsigned int id() const { return m_id;}
    QString name() const { return m_name;}
    QString email() const {return m_email;}
    int assesments() const {return m_assesments;}
    double homework1() const {return m_homework1;}
    double homework2() const {return m_homework2;}
    double labGrade() const {return m_labGrade;}
    double testGrade() const { return m_testGrade;}
    QString group() const { return m_group;}

    void updateByValue(QVariant value, int attribute);
    friend std::ostream& operator<<(std::ostream& os, StudentTerm& st);

signals:
    void nameChanged();
};

#endif // STUDENTTERM_H
