import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

ApplicationWindow {
    id: rootId
    visible: true
    width: 1200
    height: 536
    title: qsTr("Gradebook demo")

    property date currentDate: new Date()
    property string dateString
    property int minimumRectWidth: 50
    property int preferredRectWidth: 100
    property int maximumRectWidth: 300
    property int minimumRectHeight: 50
    property int delegateFontSize : 12

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
        spacing: 40

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

            spacing: 20
            Rectangle{
                id : listBoxId

                color : "transparent"
                width: 840
                height: 320

                Rectangle {
                    id : listViewWrapper
                    color : "teal"
                    border.color: "black"
                    border.width: 1.4

                    anchors {
                        fill : parent
                        left : parent.left
                        leftMargin : 20
                    }

                    Component {
                        id: studentDelegate
                        Item {
                            id: wrapper
                            width: parent.width
                            height: 25
                            RowLayout {
                                spacing : 10
                                delegateItem {
                                    textData : name
                                }

                               /* Rectangle {
                                    color : "red"
                                    width : 96
                                    height: 25
                                    Text {
                                        anchors.centerIn: parent
                                        text : name
                                        font.pointSize: delegateFontSize }
                                } */
                                Text { text : median + " "
                                    font.pointSize: delegateFontSize}
                                Text { text : email + " "
                                    font.pointSize: delegateFontSize}
                                Text { text : grade1 + " "
                                    font.pointSize: delegateFontSize}
                                Text { text : grade2 + " "
                                    font.pointSize: delegateFontSize}
                                Text { text : homework + " "
                                    font.pointSize: delegateFontSize}
                                Text { text : project
                                    font.pointSize: delegateFontSize}
                            }

                            states: State {
                                name: "Current"
                                when: wrapper.ListView.isCurrentItem
                                PropertyChanges { target: wrapper; x: 10 }
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
                            height: 25
                            color : "#FFFF88"
                            y : stubListViewId.currentItem.y
                        }
                    }

                    Component {
                        id : headerId
                        Rectangle {
                            id : headerRectId
                            color : "darkturquoise"
                            width : stubListViewId.width
                            height : 30
                            RowLayout{
                                anchors.verticalCenter: parent.verticalCenter
                                spacing : 10
                                Repeater {
                                    model : ["Name", "Median", "  Email  ", "Grade1", "Grade2", "Grade2",
                                        "Homework", "Project"]
                                    // delegate :
                                    Rectangle {
                                        color: "red"
                                        //opacity: (7 - index) / 7
                                        //anchors.verticalCenter: parent.verticalCenter
                                        width : 96
                                        height: 20
                                        Text{
                                            anchors.centerIn: parent
                                            text: modelData
                                            font.pointSize: headerFontSize}
                                    }
                                }
                            }
                        }
                    }

                    ListView{
                        id : stubListViewId
                        anchors.bottomMargin: 0
                        anchors.fill: parent
                        model : StubModel {}
                        delegate: studentDelegate
                        focus: true

                        header: headerId
                        highlight: highlightBar
                        highlightFollowsCurrentItem: false
                    }
                }
            }

            Rectangle{
                height : 320
                width: 260
                id: statisticsBoxId
                Label{
                    anchors.centerIn: parent
                    text : qsTr("Statistics go here")
                }
            }
        }

        RowLayout{
            id: thirdRowId
            spacing : 10
            anchors.top : secondRowId.bottom
            anchors.topMargin : 20
            Button {
                id : prevButton
                text : qsTr("Previous")
                anchors.verticalCenter: parent.verticalCenter
                anchors.right : nextButton.left
                style: ButtonStyle{
                    background: Rectangle {
                        implicitWidth : 100
                        implicitHeight : 30
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                    }
                }
            }
            Button {
                id : nextButton
                text : qsTr("Next")
                anchors.verticalCenter: parent.verticalCenter
                anchors.left : parent.left
                anchors.leftMargin : 20 + listBoxId.width / 2
                style: ButtonStyle{
                    background: Rectangle {
                        implicitWidth : 100
                        implicitHeight : 30
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                    }
                }
            }
            /*Rectangle {
                id: prevRectId
                color : "white"
                Layout.fillWidth: true
                Layout.minimumWidth: minimumRectWidth
                Layout.preferredWidth: preferredRectWidth
                Layout.maximumWidth: maximumRectWidth
                Layout.minimumHeight: minimumRectHeight

                Button {
                    text : qsTr("Previous")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right : parent.right
                    style: ButtonStyle{
                        background: Rectangle {
                            implicitWidth : 100
                            implicitHeight : 30
                            border.width: control.activeFocus ? 2 : 1
                            border.color: "#888"
                            radius: 4
                        }
                    }
                }
            } */

            /*Rectangle {
                id : nextRectId
                color : "black"
                Layout.fillWidth: true
                Layout.minimumWidth: minimumRectWidth
                Layout.preferredWidth: preferredRectWidth
                Layout.maximumWidth: maximumRectWidth
                Layout.minimumHeight: minimumRectHeight

                Button {
                    text : qsTr("Next")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left : parent.left
                    style: ButtonStyle{
                        background: Rectangle {
                            implicitWidth : 100
                            implicitHeight : 30
                            border.width: control.activeFocus ? 2 : 1
                            border.color: "#888"
                            radius: 4
                        }
                    }
                }
            } */
        }
    }

    Component.onCompleted: {
        dateString = currentDate.toLocaleDateString();
    }

}
