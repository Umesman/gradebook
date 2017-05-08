#include <QSortFilterProxyModel>

#include "proxymodel.h"
#include "gradebookmodel.h"


ProxyModel::ProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent),
    m_filter(Proxy_Filter::GROUP_ALL),
    m_sortRole(GradebookModel::FirstNameRole),
    m_sortOrder(Qt::AscendingOrder),
    m_passed(false)
{

    //setDynamicSortFilter(true);
    qDebug() << Q_FUNC_INFO;
}

ProxyModel::ProxyModel(GradebookModel *model, QObject *parent) :
    QSortFilterProxyModel(parent),
    m_filter(Proxy_Filter::GROUP_ALL),
    m_sortRole(GradebookModel::FirstNameRole),
    m_passed(false)
{
    qDebug() << Q_FUNC_INFO;
    QSortFilterProxyModel::setSourceModel(model);
    QSortFilterProxyModel::setSortRole(m_sortRole);
    QSortFilterProxyModel::sort(0, m_sortOrder);

    //this->setSourceModel(model);
}

ProxyModel::~ProxyModel()
{

}

void ProxyModel::setFilter(int filter)
{
    qDebug() << Q_FUNC_INFO << " group: " << filter;
    if (m_filter != filter)
    {
        m_filter = ProxyModel::Proxy_Filter(filter);
        QSortFilterProxyModel::invalidateFilter();
        emit filterChanged();
    }
}

void ProxyModel::setSortRole(int role)
{
    qDebug() << Q_FUNC_INFO << " sort role: " << role
             << " current role: " << m_sortRole;

    if (m_sortRole != role)
    {
        m_sortRole = role;
        m_sortOrder = Qt::AscendingOrder;
    }
    else {
        if (Qt::AscendingOrder == m_sortOrder)
            m_sortOrder = Qt::DescendingOrder;
        else
            m_sortOrder = Qt::AscendingOrder;
    }

    qDebug() << Q_FUNC_INFO << " sort order: " << m_sortOrder;
    QSortFilterProxyModel::setSortRole(m_sortRole);
    QSortFilterProxyModel::sort(0, m_sortOrder);
}

int ProxyModel::filter()
{
    qDebug() << Q_FUNC_INFO;
    return m_filter;
}

bool ProxyModel::passed()
{
    qDebug() << Q_FUNC_INFO;
    return m_passed;
}

int ProxyModel::sortRole()
{
    return m_sortRole;
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    GradebookModel *model = static_cast<GradebookModel *> (this->sourceModel());
    return model->headerData(section, orientation, role);
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
    qDebug() << "ProxyModel::filterAcceptsRow " <<  ret << " "<<source_row;
    return ret;

}

//bool ProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
//{
//    qDebug() << Q_FUNC_INFO;
//    QVariant leftData = sourceModel()->data(source_left);
//    QVariant rightData = sourceModel()->data(source_right);

//    if (rightData.type() == QVariant::String)
//    {
//        qDebug() << Q_FUNC_INFO << leftData.toString() << " : " << rightData.toString();
//        return leftData.toString() < rightData.toString();
//    }

//    return false;
//}

bool ProxyModel::verifyPassedCondition(const QModelIndex &index) const
{
    qDebug() << "ProxyModel::verifyPassedCondition ";

    double final_grade = index.data(GradebookModel::StudentRoles::FinalRole).toDouble();
    bool ret = final_grade >= 5.0 ? true : false;
    return ret;
    qDebug() << "ProxyModel::verifyPassedCondition " << ret;
}

