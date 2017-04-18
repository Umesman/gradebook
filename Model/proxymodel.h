#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

//class QSortFilterProxyModel;
class GradebookModel;

class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_ENUMS (Proxy_Filter)
    Q_PROPERTY (int filter READ getFilter WRITE setFilter NOTIFY filterChanged)


public:

    enum Proxy_Filter{
        GROUP_A,
        GROUP_B,
        GROUP_C,
        GROUP_D,
        GROUP_ALL
    };

     ProxyModel(QObject *parent = 0);
     ProxyModel(GradebookModel *model);

    virtual ~ProxyModel();

    int getFilter();

public slots:
    void setFilter(int filter);

signals:
    void filterChanged();

protected:
    virtual bool filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const;


private:
    Proxy_Filter m_filter;
};

#endif // PROXYMODEL_H
