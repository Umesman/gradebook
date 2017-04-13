#ifndef MAINVIEWMGR_H
#define MAINVIEWMGR_H

#include <QObject>

class GradebookModel;


class MainViewMgr : public QObject
{
    Q_OBJECT

public:
    explicit MainViewMgr(QObject *parent = 0);

signals:

private:
   GradebookModel* model;
};

#endif // MAINVIEWMGR_H
