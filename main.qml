import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2
//import proxymodel.test1 1.0

ApplicationWindow {
    id: rootId
    visible: true
    width: 1280 + 116
    height: 536
    title: qsTr("Gradebook demo")

    property date currentDate: new Date()
    property string dateString
    property int minimumRectWidth: 50
    property int preferredRectWidth: 100
    property int maximumRectWidth: 300
    property int minimumRectHeight: 50

    menuBar: MenuBarControl{}

    toolBar: ToolBar{
        TextField{
            id: searchBox

            placeholderText: "Search..."

            width: rootId.width / 10 * 2
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    ColumnLayout{
        id: columnId
        spacing: 40

        ListFilterRow{
            id: firstRowId
        }

        RowLayout{
            id: secondRowId

            spacing: 20

            ListBoxRow {
                id : listBoxId
            }

            Rectangle{
                visible: false
                height : 320
                width: 300
                Loader{
                    source: firstRowId.editActive? "EditForm.qml" : "StatisticsRow.qml"
                    active: true
                }
            }
        }//rowlayout

        ListNavigatorRow{
            id: thirdRowId
        }
    }

    Component.onCompleted: {
        dateString = currentDate.toLocaleDateString();
    }

}
