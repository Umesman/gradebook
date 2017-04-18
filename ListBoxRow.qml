import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2


Rectangle{
    // informStudentDetails should inform the dialog for the student info is to be displayed
    signal informStudentDetails(int index)

    // should sort the listview by the different roles
    signal sortBy(int role)


    color : "transparent"
    width: 948
    height: 320

    Rectangle {
        id : listViewWrapper
        color : "#190033"
        border.color: "black"
        border.width: 2.4

        anchors {
            fill : parent
            left : parent.left
            leftMargin : 20
        }

        ListDelegate{
            id: studentDelegate
        }

        Component{
            //id : studentDelegate
            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                height: 25
                color: "gray"

                Text {
                    text : name
                    anchors.centerIn: parent
                }
            }
        }


        ListHeader{
            id : headerId
        }

        Component {
            id: highlightBar
            Rectangle {
                width: parent.width
                height: 25
                color : "#FF3333"
                y : stubListViewId.currentItem.y
            }
        }


        ListView{
            id : stubListViewId
            anchors.bottomMargin: 0
            anchors.fill: parent
            //model : myModel
            model : myProxyModel
            delegate: studentDelegate
            focus: true

            //header : myModel.headerData(1, 1, 0)
            header: headerId
            highlight: highlightBar
            highlightFollowsCurrentItem: false
        }
    }
}


