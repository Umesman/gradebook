#ifndef STUDENTTERM_H
#define STUDENTTERM_H

#include <QString>


class StudentTerm
{

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

public:

    // default constructor
    StudentTerm() :
        m_id {001}, m_name {"Unknown"}, m_email {"default@sql.com"}, m_assesments{1},
        m_homework1{1}, m_homework2{1}, m_labGrade{1}, m_testGrade{1}
    {}

    // general use constructor
    // no memory allocation in this class - I can use the default copy constr
    StudentTerm(unsigned int id, QString name, QString group, QString email, unsigned int assessments,
                double homework1, double homework2, double labGrade, double testGrade) :
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

    unsigned int id() const { return m_id;}

    QString name() const { return m_name;}
    void setName(const QString &name);

    QString email() const {return m_email;}
    void setEmail(const QString &email);

    int assesments() const {return m_assesments;}
    void setAssesments(const int  assesments);

    double homework1() const {return m_homework1;}
    void setHomework1(const double homework);

    double homework2() const {return m_homework2;}
    void setHomework2(const double homework);

    double labGrade() const {return m_labGrade;}
    void setLabGrade(const double labGrade);

    double testGrade() const { return m_testGrade;}
    void setTestGrade(const double testGrade);

    QString group() const { return m_group;}
    void setGroup(const QString &group);

    friend std::ostream& operator<<(std::ostream& os, StudentTerm& st);
};

#endif // STUDENTTERM_H
