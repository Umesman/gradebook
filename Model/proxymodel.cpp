#include <QSortFilterProxyModel>

#include "proxymodel.h"
#include "gradebookmodel.h"


ProxyModel::ProxyModel(QObject *parent) :
     QSortFilterProxyModel(parent)
{}

ProxyModel::ProxyModel(GradebookModel *model) :
    QSortFilterProxyModel()
{
    //QSortFilterProxyModel::setSourceModel(model);
    this->setSourceModel(model);
}

ProxyModel::~ProxyModel()
{

}

void ProxyModel::setFilter(int filter)
{
    if (m_filter != filter)
        m_filter = ProxyModel::Proxy_Filter(filter);
    emit filterChanged();
}

int ProxyModel::getFilter()
{
    return m_filter;
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

    bool ret (false);
    auto index = sourceModel()->index(source_row, 0, source_parent);

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
    return ret;
}

