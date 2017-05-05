#include "studentterm.h"
#include <iostream>
#include <QDebug>
#include <cmath>
#include <limits>

//void StudentTerm::set(const QString &name)
//{
//    m_name = name;
//    emit nameChanged();
//}

void StudentTerm::setFirstName(const QString &name)
{
    m_firstName = name;
}

void StudentTerm::setLastName(const QString &name)
{
    m_lastName = name;
}

void StudentTerm::setEmail(const QString &email)
{
    m_email = email;
}

void StudentTerm::setAssesments(const unsigned int assesments)
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

void StudentTerm::updateByValue(QVariant value, int attribute)
{
    switch (attribute)
    {
    case FIRST_NAME : setFirstName(value.toString());
        break;
    case LAST_NAME : setLastName(value.toString());
        break;
    case GROUP : setGroup(value.toString());
        break;
    case EMAIL : setEmail(value.toString());
        break;
    case ASSESSMENTS : setAssesments(value.toInt());
        calculateFinal();
        break;
    case HOMEWORK1 : setHomework1(value.toDouble());
        calculateFinal();
        break;
    case HOMEWORK2 : setHomework2(value.toDouble());
        calculateFinal();
        break;
    case LABGRADE : setLabGrade(value.toDouble());
        calculateFinal();
        break;
    case TESTGRADE : setTestGrade(value.toDouble());
        calculateFinal();
        break;
    default :
        qDebug() << "No valid attribute specified: " << attribute ;
    }
}

QVariant StudentTerm::returnValueByAttribute(int attribute)
{
    switch (attribute)
    {
    case FIRST_NAME :
        return QVariant(firstName());
    case LAST_NAME :
        return QVariant(lastName());
    case GROUP :
        return QVariant(group());
    case EMAIL :
        return QVariant(email());
    case ASSESSMENTS :
        return QVariant(assesments());
    case HOMEWORK1 :
        return QVariant(homework1());
    case HOMEWORK2 :
        return QVariant(homework2());
    case LABGRADE :
        return QVariant(labGrade());
    case TESTGRADE :
        return QVariant(testGrade());
    default :
        qDebug() << "No valid attribute specified: " << attribute ;
        return QVariant();
    }
}

bool StudentTerm::checkIfAttributeChanged(const StudentTerm *st, Attributes attribute)
{
    qDebug() << Q_FUNC_INFO << attribute;
    if (Q_NULLPTR == st){
        qDebug() << Q_FUNC_INFO << "Address of st: " << st;
        return false;
    }

    bool ret(false);

    switch (attribute) {
    case Attributes::ID:
        if (st->id() != this->id())
            ret = true;
        break;
    case Attributes::FIRST_NAME:
        qDebug() << Q_FUNC_INFO << "FIRST";
        qDebug() << st->firstName() << " : " << firstName();
        if (st->firstName() != this->firstName())
            ret = true;
        break;
    case Attributes::LAST_NAME:
        qDebug() << Q_FUNC_INFO << "LAST";
        qDebug() << st->lastName() << " : " << lastName();
        if (st->lastName() != this->lastName())
            ret = true;
        break;
    case Attributes::GROUP:
        qDebug() << Q_FUNC_INFO << "GROUP";
        qDebug() << st->group() << " : " << this->group();
        if (st->group() != this->group())
            ret = true;
        break;
    case Attributes::EMAIL:
        qDebug() << Q_FUNC_INFO << "EMAIL";
        qDebug() << st->email() << " : " << email();
        if (st->email() != this->email())
            ret = true;
        break;
    case Attributes::ASSESSMENTS:
        qDebug() << Q_FUNC_INFO << "ASSESSMENTS";
        qDebug() << st->assesments() << " : " << assesments();
        if (st->assesments() != this->assesments())
            ret = true;
        break;
    case Attributes::HOMEWORK1:
        qDebug() << Q_FUNC_INFO << "HMK1";
        if (!areSame(st->homework1(), this->homework1()))
            ret = true;
        break;
    case Attributes::HOMEWORK2:
        qDebug() << Q_FUNC_INFO << "HMK2";
        if (!areSame(st->homework2(), this->homework2()))
            ret = true;
        break;
    case Attributes::LABGRADE:
        qDebug() << Q_FUNC_INFO << "LAB";
        if (!areSame(st->labGrade(), this->labGrade()))
            ret = true;
        break;
    case Attributes::TESTGRADE:
        qDebug() << Q_FUNC_INFO << "TEST";
        if (!areSame(st->testGrade(), this->testGrade()))
            ret = true;
        break;
    default:
        break;
    }

    return ret;
}

void StudentTerm::resetInternalData()
{
    m_firstName = QString("");
    m_lastName = QString("");
    m_group = QString();
    m_email = QString();
    m_id = 0;
    m_assesments = 0;
    m_homework1 = 1;
    m_homework2 = 1;
    m_labGrade = 1;
    m_testGrade = 1;
    calculateFinal();
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

bool StudentTerm::areSame(double a, double b)
{
    qDebug() << Q_FUNC_INFO << a << " : " << b;
    std::cout << "StudentTerm::areSame";
    return std::fabs(a - b) < std::numeric_limits<double>::epsilon();
}


std::ostream& operator<<(std::ostream& os, const StudentTerm& st)
{
    qDebug() << "operator<< StudentTerm";
    os << "Name: "  << st.firstName().toStdString() << std::endl;
    os << "Group: " << st.group().toStdString() << std::endl;
    os << "Email: " << st.email().toStdString() << std::endl;
    os << "Assessments: " << st.assesments() << std::endl;
    os << "Homework1: " << st.homework1() << std::endl;
    os << "Homework2: " << st.homework2() << std::endl;
    os << "Lab grade: " << st.labGrade() << std::endl;
    os << "Test grade: " << st.testGrade() << std::endl;

    return os;
}
