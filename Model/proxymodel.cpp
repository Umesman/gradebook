#include <QSortFilterProxyModel>

#include "proxymodel.h"
#include "gradebookmodel.h"


ProxyModel::ProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent),
    m_filter(Proxy_Filter::GROUP_ALL),
    m_passed(false)
{

}

ProxyModel::ProxyModel(GradebookModel *model) :
    QSortFilterProxyModel(),
    m_filter(Proxy_Filter::GROUP_ALL),
    m_passed(true)
{
    QSortFilterProxyModel::setSourceModel(model);
    //this->setSourceModel(model);
}

ProxyModel::~ProxyModel()
{

}

void ProxyModel::setFilter(int filter)
{
    if (m_filter != filter)
    {
        m_filter = ProxyModel::Proxy_Filter(filter);
        QSortFilterProxyModel::invalidateFilter();
        emit filterChanged();
    }
}

int ProxyModel::filter()
{
    return m_filter;
}

bool ProxyModel::passed()
{
    return m_passed;
}

void ProxyModel::setPassed(bool passed)
{
    qDebug() << "ProxyModel::setPassed " << passed;
    if (m_passed != passed)
    {
        m_passed = passed;
        QSortFilterProxyModel::invalidateFilter();
        emit passedChanged();
    }
}

/*
QVariant ProxyModel::data(const QModelIndex &index, int role) const
{
    return sourceModel()->data(index, role);
}*/

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

    qDebug() << "ProxyModel::filterAcceptsRow ";
    bool ret (false);
    QModelIndex index;

    if (sourceModel() != NULL)
        index = sourceModel()->index(source_row, 0, source_parent);

    if ((m_passed) && (!verifyPassedCondition(index)))
        return false;

    //QAbstractItemModel *model = sourceModel();
    //auto index = model->index(source_row, 0, source_parent);


    if (index.isValid())
        switch (m_filter){
        case Proxy_Filter::GROUP_ALL :
            ret = true;
            break;
        case Proxy_Filter::GROUP_A :
            if (index.data(GradebookModel::StudentRoles::GroupRole) == "A")
                ret = true;
            break;
        case Proxy_Filter::GROUP_B :
            if (index.data(GradebookModel::StudentRoles::GroupRole) == "B")
                ret = true;
            break;
        case Proxy_Filter::GROUP_C :
            if (index.data(GradebookModel::StudentRoles::GroupRole) == "C")
                ret = true;
            break;
        case Proxy_Filter::GROUP_D :
            if (index.data(GradebookModel::StudentRoles::GroupRole) == "D")
                ret = true;
            break;
        default :
            ret = false;
        }
    else
        ret = true;
    qDebug() << "ProxyModel::filterAcceptsRow " <<  ret;
    return ret;

}

bool ProxyModel::verifyPassedCondition(const QModelIndex &index) const
{
    qDebug() << "ProxyModel::verifyPassedCondition ";

    double final_grade = index.data(GradebookModel::StudentRoles::FinalRole).toDouble();
    bool ret = final_grade >= 5.0 ? true : false;
    return ret;
    qDebug() << "ProxyModel::verifyPassedCondition " << ret;
}

