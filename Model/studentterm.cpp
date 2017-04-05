#include "studentterm.h"
#include <iostream>

void StudentTerm::setName(const QString &name)
{
    m_name = name;
}

void StudentTerm::setEmail(const QString &email)
{
    m_email = email;
}

void StudentTerm::setAssesments(const int assesments)
{
    m_assesments = assesments;
}

void StudentTerm::setHomework1(const double homework)
{
    m_homework1 = homework;
}

void StudentTerm::setHomework2(const double homework)
{
    m_homework2 = homework;
}

void StudentTerm::setLabGrade(const double labGrade)
{
    m_labGrade = labGrade;
}

void StudentTerm::setTestGrade(const double testGrade)
{
    m_testGrade = testGrade;
}

void StudentTerm::setGroup(const QString &group)
{
    m_group = group;
}

void StudentTerm::calculateFinal()
{
   m_finalGrade = m_assesments * 0.3 + (m_homework1 + m_homework2) * 0.15
           + m_labGrade * 0.2 + m_testGrade * 0.2;
}

double StudentTerm::limits(double grade)
{
    if (grade > 10)
        return 10;
    if (grade < 1)
        return 1;

    return grade;
}

std::ostream& operator<<(std::ostream& os, StudentTerm& st)
{
    os << "Name: "  << st.name().toStdString() << std::endl;
    os << "Group: " << st.group().toStdString() << std::endl;
    os << "Email: " << st.email().toStdString() << std::endl;
    os << "Assessments: " << st.assesments() << std::endl;
    os << "Homework1: " << st.homework1() << std::endl;
    os << "Homework2: " << st.homework2() << std::endl;
    os << "Lab grade: " << st.labGrade() << std::endl;
    os << "Test grade: " << st.testGrade() << std::endl;

    return os;
}
