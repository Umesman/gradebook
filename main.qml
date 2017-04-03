import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: rootId
    visible: true
    width: 820
    height: 560
    title: qsTr("Gradebook demo")

    property date currentDate: new Date()
    property string dateString
    property int minimumRectWidth: 50
    property int preferredRectWidth: 100
    property int maximumRectWidth: 300
    property int minimumRectHeight: 50

    menuBar: MenuBar{
        Menu {
            title : "File"
            MenuItem { text : "Open.." }
            MenuItem { text : "Save As.." }
            MenuItem { text : "Exit"
                onTriggered: Qt.quit()}
        }

        Menu {
            title: "Tools"
            MenuItem { text : "Add Entry.." }
            MenuItem { text : "Edit Entry.." }
            MenuItem { text : "Remove Entry.." }
        }

    }

    ColumnLayout{
        id: columnId
        spacing: 50

        RowLayout{
            id : firstRowId
            anchors {
                top : parent.top
                horizontalCenter: parent.horizontalCenter
                topMargin: 20
            }
            spacing: 50


            Rectangle{
                color : "transparent"
                Layout.fillWidth: true
                Layout.minimumWidth: minimumRectWidth
                Layout.preferredWidth: preferredRectWidth
                Layout.maximumWidth: maximumRectWidth
                Layout.minimumHeight: minimumRectHeight
                ComboBox {
                    id : comboBoxId
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    anchors.verticalCenter: parent.verticalCenter
                    width: 120
                    height: 40
                    //Layout.preferredWidth: 125
                    model: [ "All Groups", "Group A", "Group B", "Group C", "Group D"]
                    currentIndex : 0
                }

            }

            Rectangle {
                color : "transparent"
                Layout.fillWidth: true
                Layout.minimumWidth: minimumRectWidth
                Layout.preferredWidth: preferredRectWidth
                Layout.maximumWidth: maximumRectWidth
                Layout.minimumHeight: minimumRectHeight


                CheckBox{
                    id: checkBoxId
                    //anchors.left: comboBoxId.right
                    //anchors.leftMargin: 20
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Passed")
                    //Layout.fillWidth: true
                    Layout.alignment: Qt.AlignRight
                }

            }

            Rectangle {
                color : "transparent"
                Layout.fillWidth: true
                Layout.minimumWidth: minimumRectWidth
                Layout.preferredWidth: preferredRectWidth
                Layout.maximumWidth: maximumRectWidth
                Layout.minimumHeight: minimumRectHeight

                Text {
                    //color : "white"
                    anchors.left: parent.left
                    anchors.leftMargin: 100
                    anchors.verticalCenter: parent.verticalCenter
                    id : dateLabelId
                    text: dateString
                }

            }

        }

        RowLayout{
            id: secondRowId

            Rectangle{
                id : listBoxId

                color : "transparent"
                width: 400
                height: 300

                Rectangle {
                    id : listViewWrapper
                    color : "teal"
                    border.color: "black"
                    border.width: 1.4

                    anchors {
                        fill : parent
                        left : parent
                        leftMargin : 20  }

                    Component {
                        id: studentDelegate
                        Item {
                            id: wrapper
                            width: parent.width
                            height: 55
                            Row {
                                Text { text : name + " " }
                                Text { text : median + " " }
                                Text { text : email + " " }
                                Text { text : grade1 + " " }
                                Text { text : grade2 + " " }
                                Text { text : homework + " " }
                                Text { text : project }
                            }

                            states: State {
                                name: "Current"
                                when: wrapper.ListView.isCurrentItem
                                PropertyChanges { target: wrapper; x: 20 }
                            }
                            transitions: Transition {
                                NumberAnimation { properties: "x"; duration: 200 }
                            }
                            MouseArea{
                                anchors.fill: parent
                                onClicked: wrapper.ListView.view.currentIndex = index
                            }
                        }
                    }

                    Component {
                        id: highlightBar
                        Rectangle {
                            width: parent.width
                            height: 55
                            color : "#FFFF88"
                            y : stubListViewId.currentItem.y
                        }
                    }

                    ListView{
                        id : stubListViewId
                        anchors.fill: parent
                        model : StubModel {}
                        delegate: studentDelegate
                        focus: true

                        highlight: highlightBar
                        highlightFollowsCurrentItem: false
                    }
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

        RowLayout{
            id: thirdRowId
            Button {
                text : qsTr("Previous")
            }

            Button {
                text : qsTr("Next")
            }
        }
    }

    Component.onCompleted: {
        dateString = currentDate.toLocaleDateString();
    }

}
