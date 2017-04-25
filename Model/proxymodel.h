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
    Q_PROPERTY (int filter READ filter WRITE setFilter NOTIFY filterChanged)
    Q_PROPERTY(bool passed READ passed WRITE setPassed NOTIFY passedChanged)

public:

    enum Proxy_Filter{
        GROUP_ALL,
        GROUP_A,
        GROUP_B,
        GROUP_C,
        GROUP_D
    };

     ProxyModel(QObject *parent = 0);
     ProxyModel(GradebookModel *model, QObject *parent=0);

    virtual ~ProxyModel();

     /**
      * @return Returns the current filter.
      */

    int filter();
    //QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * @return Returns the current pass condition.
     */
    bool passed();


public slots:
    /**
     * @brief setPassCondition sets the current pass condition.
     * @param passed is used to filter the students who have the final grade above 5.
     */
    void setPassed(bool passed);

    /**
     * @brief setFilter sets the current filter.
     * @param filter is the filter setting the proxy model should use.
     */
    void setFilter(int filter);


signals:
    /**
     * @brief filterChanged is emitted when the filter changes.
     */

    void filterChanged();

    /**
     * @brief passedChanged is emitted when the passed condition changes.
     */

    void passedChanged();

protected:
    /**
     * @brief filterAcceptsRow is a predict that is run against each data entry when the souce model is added or changed.
     * If this method returns true then the data entry has satisfied the filter logic and is to be included in the proxys data set.
     * If this method returns false then the data entry is ignored (looks like it does not exist).
     * @note The base implementations of index(), parent(), rowCount(), columnCount(), data(), and setData() are all aware of the results
     * of this predict, that is they to will ignore any data entries from the source model that don't pass the filter logic.
     * @param source_row is the row number within the source model of a data entry to check.
     * @param source_parent is the parent of the data entry (used if the source model is a tree).
     * @return Returns true if the data entry passed the filter logic, false otherwise
     */

    virtual bool filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const;


private:
    /**
     * @brief verifyPassedCondition is intended to be used within the filterAcceptsRow method to make an initial filtering
     * for the data corresponding to the FinalRole of the current index. This value should be above 5 to return true
     * @param source_row is the row number within the source model of a data entry to check.
     * @param source_parent is the parent of the data entry (used if the source model is a tree)
     * @return Returns true if the passed condition is fulfilled
     */
    bool verifyPassedCondition(const QModelIndex &index) const;

    /**
     * @brief m_filter is used to filter by group the current data set
     */
    Proxy_Filter m_filter;

    /**
     * @brief m_passed is used to filter the students who have the final grade above 5
     */
    bool m_passed;
};

#endif // PROXYMODEL_H
