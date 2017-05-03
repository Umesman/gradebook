#ifndef EDITFORM_H
#define EDITFORM_H

#include <QObject>
#include "../Model/studentterm.h"


//class StudentTerm;
class MainViewMgr;

class EditForm : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString group READ group WRITE setGroup NOTIFY groupChanged)
    Q_PROPERTY(int assesments READ assesments WRITE setAssesments NOTIFY assesmentsChanged)
    Q_PROPERTY(int id READ id)
    Q_PROPERTY(double homework1 READ homework1 WRITE setHomework1 NOTIFY homework1Changed)
    Q_PROPERTY(double homework2 READ homework2 WRITE setHomework2 NOTIFY homework2Changed)
    Q_PROPERTY(double labGrade READ labGrade WRITE setLabGrade NOTIFY labGradeChanged)
    Q_PROPERTY(double testGrade READ testGrade WRITE setTestGrade NOTIFY testGradeChanged)

signals:
    void firstNameChanged();
    void lastNameChanged();
    void emailChanged();
    void groupChanged();
    void assesmentsChanged();
    void homework1Changed();
    void homework2Changed();
    void labGradeChanged();
    void testGradeChanged();

public:
    EditForm(QObject *parent=0);
    // set the pointer to the current studentterm which should be edited
    void setStudentInfo(const StudentTerm *st);
    Q_INVOKABLE void confirmStudentInfo();
    void resetStudentInfo();
    bool hasStudentInfoChanged();

    QString firstName() const;
    QString lastName() const;
    QString email() const;
    QString group() const;
    unsigned int id() const;
    unsigned int assesments() const;
    double homework1() const;
    double homework2() const;
    double labGrade() const;
    double testGrade() const;

    void setFirstName(QString firstName);
    void setLastName (QString lastName);
    void setEmail (QString email);
    void setGroup (QString group);
    void setAssesments(int assesments);
    void setHomework1(const double homework);
    void setHomework2(const double homework);
    void setLabGrade(const double labGrade);
    void setTestGrade(const double testGrade);

private:
    MainViewMgr *m_pViewMgr;
    StudentTerm m_localStudentInfo;
    StudentTerm *m_pStudentInfo;

};

#endif // EDITFORM_H
