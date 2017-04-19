#ifndef MODELMGR_H
#include <QObject>

//#include "gradebookmodel.h"
//#include "proxymodel.h"
//#include "datahandler.h"

#define MODELMGR_H

class MainViewMgr;
class GradebookModel;
class DataHandler;
class ProxyModel;

class ModelMgr : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief ModelMgr constructor
     * @param handler takes a pointer to the datahandler
     * @param parent
     */
    explicit ModelMgr(DataHandler *handler, MainViewMgr *viewmgr, QObject *parent=0);

    /**
      *
      */
    ~ModelMgr();

    /**
     * @brief setModelSource sets the source data structure of the Model
     * usually it is a pointer to the datahandler studentcollection
     */
    void setModelSource();

    /**
     * @brief setProxySource sets the modelsource of the proxy to the
     * m_pmodel pointer
     */
    void setProxySource();

    /**
     * @brief getModel
     * @return
     */
    GradebookModel *getModel();

    /**
     * @brief getProxy
     * @return
     */
    ProxyModel *getProxy();


signals:

    /**
     * @brief sgnRowAdded emited after a row has been added to inform the datahandler
     * @param st
     */
    void sgnRowAdded(const StudentTerm &st);

    /**
     * @brief sgnRowRemoved emited after a row has been removed to inform the datahandler
     * @param row
     */
    void sgnRowRemoved(int row);

    /**
     * @brief sgnStudentInfoChanged emited after a row has been changed to inform the datahandler
     * @param index
     * @param value
     * @param role
     */
    void sgnStudentInfoChanged(const QModelIndex &index, const QVariant &value, int role);

public slots:

    /**
     * @brief sltAddRow received from the viewmanager in order to add a row in the model
     * @param st
     */
    void sltAddRow(const StudentTerm &st);

    /**
     * @brief sltRemoveRow received from the viewmanager in order to remove a row in the model
     * @param row
     */
    void sltRemoveRow(int row);

    /**
     * @brief sltChangeStudentInfo received from the viewmanager in update to add a row in the model
     * @param index
     * @param value
     * @param role
     */
    void sltChangeStudentInfo(const QModelIndex &index, const QVariant &value, int role);

    /**
     * @brief sltPassedConditionChanged received from the viewmanager in order to change the ProxyModel
     * passed condition
     * @param cond ProxyModel passed contidion
     */
    void sltPassedConditionChanged(bool cond);

    /**
     * @brief sltFilterChanged received from the viewmanager in order to update the active filter
     * @param filter should be corellated to ProxyModel::Proxy_Filter
     */
    void sltFilterChanged(int filter);

private:

    /**
     * @brief connectSignals used to wire up the signal and slot connections with the datahandler
     * and the viewmanager
     */
    void connectSignals();

   GradebookModel *m_pmodel;
   ProxyModel *m_pproxymodel;
   DataHandler *m_phandler;
   MainViewMgr *m_pviewManager;

#endif // MODELMGR_H
