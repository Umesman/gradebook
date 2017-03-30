import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Gradebook demo")

    ColumnLayout{
        id: columnId

        RowLayout{
            id : firstRowId

            spacing: 30
            anchors {
                top : parent.top
                horizontalCenter: parent.horizontalCenter
                topMargin: 15
            }

            ComboBox{
                height: 20
                Layout.preferredWidth: 125
                model: [ "All Groups", "Group A", "Group B", "Group C", "Group D"]
                currentIndex : 0
            }

            CheckBox{
                text: qsTr("Passed")
            }

            Label {
                id : dateLabelId
                text: qsTr("currentDate")
            }

        }

        RowLayout{
            id: secondRowId
            anchors.top : firstRowId.bottom
            anchors.topMargin: 25

            Rectangle{
                id : listBoxId
                color : "lightgreen"
                width: 400
                height: 300

                Component{
                    id : itemDelegate
                    Text { text: "I am item number "  + index}
                }

                ListView{
                    id : stubListViewId
                    anchors.fill: parent
                    model : 14
                    delegate: itemDelegate
                }

            }

            Rectangle{
                height : 200
                width: 200
                id: statisticsBoxId
                Label{
                    anchors.centerIn: parent
                    text : qsTr("Statistics go here")
                }
            }
        }
    }

}



