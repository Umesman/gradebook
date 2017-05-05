#include <QDebug>
#include <iostream>

#include "editform.h"
#include "mainviewmgr.h"

EditForm::EditForm(QObject *parent) :
    QObject(parent),
    m_pViewMgr(static_cast<MainViewMgr*>(parent)),
    m_localStudentInfo(),
    m_pStudentInfo(Q_NULLPTR)
{
   connectSignals();
}

void EditForm::setStudentInfo(const StudentTerm *st)
{
    qDebug() << Q_FUNC_INFO << st;
    if (m_pViewMgr->editMode())
        return;
    m_pStudentInfo = const_cast<StudentTerm*>(st);
    if (Q_NULLPTR != st)
    {
        resetStudentInfo();
        m_localStudentInfo = (*m_pStudentInfo);
        m_pViewMgr->setEditMode(true);
    }
}

void EditForm::cancelStudentInfo()
{
    m_pViewMgr->setEditMode(false);
    resetStudentInfo();
    m_pStudentInfo = Q_NULLPTR;
}

void EditForm::confirmStudentInfo()
{
   qDebug() << Q_FUNC_INFO;
   this->hasStudentInfoChanged();
   m_pViewMgr->setEditMode(false);
   //m_pStudentInfo = Q_NULLPTR;
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
           QVariant value = m_localStudentInfo.returnValueByAttribute(attribute);
           qDebug() << Q_FUNC_INFO << "value changed for " << attribute;
           emit notifyStudentInfoChange(value, static_cast<Attributes> (attribute), m_pStudentInfo->id());
        }
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
    qDebug() << Q_FUNC_INFO << group;
    m_localStudentInfo.updateByValue(group, Attributes::GROUP);
}

void EditForm::setAssesments(int assesments)
{
    m_localStudentInfo.updateByValue(assesments, Attributes::ASSESSMENTS);
}

void EditForm::setHomework1(const double homework)
{
    m_localStudentInfo.updateByValue(homework, Attributes::HOMEWORK1);
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

void EditForm::connectSignals()
{
   qDebug() << Q_FUNC_INFO;
   connect(this, &EditForm::notifyStudentInfoChange,
           m_pViewMgr, &MainViewMgr::sltNotifyStudentInfoChange);
}
