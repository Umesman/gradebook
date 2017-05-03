#include "editform.h"
#include <QDebug>
#include <iostream>

EditForm::EditForm(QObject *parent) :
    QObject(parent),
    m_localStudentInfo(),
    m_pStudentInfo(Q_NULLPTR)
{

}

void EditForm::setStudentInfo(const StudentTerm *st)
{
    qDebug() << Q_FUNC_INFO << st;
    m_pStudentInfo = const_cast<StudentTerm*>(st);
    if (Q_NULLPTR != st)
    {
        resetStudentInfo();
        m_localStudentInfo = (*m_pStudentInfo);
    }
}

void EditForm::confirmStudentInfo()
{
   qDebug() << Q_FUNC_INFO;
   this->hasStudentInfoChanged();
}

void EditForm::resetStudentInfo()
{
    qDebug() << Q_FUNC_INFO;
    m_localStudentInfo.resetInternalData();
}


bool EditForm::hasStudentInfoChanged()
{
    qDebug() << Q_FUNC_INFO;
    bool ret(false);
    for (int attribute = Attributes::ID; attribute < Attributes::FINAL; attribute++)
    {
        if (m_localStudentInfo.checkIfAttributeChanged(m_pStudentInfo, static_cast<Attributes>(attribute)))
        {
            ret = true;
            // emit signal for viewmgr sgnChangeStudentInfo
        }
        std::cout << ret;
    }
    qDebug() << Q_FUNC_INFO << " :" << ret;
    return ret;
}

QString EditForm::firstName() const
{
    return m_localStudentInfo.firstName();
}

QString EditForm::lastName() const
{
    return m_localStudentInfo.lastName();
}

QString EditForm::email() const
{
    return m_localStudentInfo.email();
}

QString EditForm::group() const
{
    return m_localStudentInfo.group();
}

unsigned int EditForm::id() const
{
    return m_localStudentInfo.id();
}

unsigned int EditForm::assesments() const
{
    return m_localStudentInfo.assesments();
}

double EditForm::homework1() const
{
    return m_localStudentInfo.homework1();
}

double EditForm::homework2() const
{
    return m_localStudentInfo.homework2();
}

double EditForm::labGrade() const
{
    return m_localStudentInfo.labGrade();
}

double EditForm::testGrade() const
{
    return m_localStudentInfo.testGrade();
}

void EditForm::setFirstName(QString firstName)
{
    m_localStudentInfo.updateByValue(firstName, Attributes::FIRST_NAME);
}

void EditForm::setLastName(QString lastName)
{
    m_localStudentInfo.updateByValue(lastName, Attributes::LAST_NAME);
}

void EditForm::setEmail(QString email)
{
    m_localStudentInfo.updateByValue(email, Attributes::EMAIL);
}

void EditForm::setGroup(QString group)
{
    m_localStudentInfo.updateByValue(group, Attributes::GROUP);
}

void EditForm::setAssesments(int assesments)
{
    m_localStudentInfo.updateByValue(assesments, Attributes::ASSESSMENTS);
}

void EditForm::setHomework1(const double homework)
{
    m_localStudentInfo.updateByValue(homework, Attributes::HOMEWORK2);
}

void EditForm::setHomework2(const double homework)
{
    m_localStudentInfo.updateByValue(homework, Attributes::HOMEWORK2);
}

void EditForm::setLabGrade(const double labGrade)
{
    m_localStudentInfo.updateByValue(labGrade, Attributes::LABGRADE);
}

void EditForm::setTestGrade(const double testGrade)
{
    m_localStudentInfo.updateByValue(testGrade, Attributes::TESTGRADE);
}
