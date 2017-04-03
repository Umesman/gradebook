import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

ApplicationWindow {
    id: rootId
    visible: true
    width: 1240
    height: 536
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
                    anchors.verticalCenter: parent.verticalCenter
                    text: qsTr("Passed")
                    style : CheckBoxStyle {
                        indicator : Rectangle{
                            implicitHeight: 16
                            implicitWidth: 16
                            radius: 16
                            border.color: checkBoxId.activeFocus ? "red" : "black"
                            border.width: 1

                            Rectangle {
                                visible: checkBoxId.checked
                                color: "#555"
                                border.color: "#333"
                                radius: 16
                                anchors.margins: 4
                                anchors.fill: parent
                            }
                        }

                        background: Rectangle{
                            color : checkBoxId.hovered ? "lightsteelblue" : "lightslategrey"
                            implicitWidth : 100
                            implicitHeight : 30
                            border.width: control.activeFocus ? 2 : 1
                            border.color: "darkslateblue"
                            radius: 4
                        }
                    }
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
                width: 900
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

                    Component {
                        id: studentDelegate
                        Item {
                            id: wrapper
                            width: parent.width
                            height: 25
                            RowLayout {
                                spacing : 20
                                x: 10
                                DelegateItem { textData : name }
                                DelegateItem { textData : median.toFixed(2) }
                                DelegateItem { textData : email }
                                DelegateItem { textData : grade1.toFixed(2) }
                                DelegateItem { textData : grade2.toFixed(2) }
                                DelegateItem { textData : homework.toFixed(2) }
                                DelegateItem { textData : project.toFixed(2) }
                            }

                            states: State {
                                name: "Current"
                                when: wrapper.ListView.isCurrentItem
                                //PropertyChanges { target: wrapper; x: 10 }
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
                            color : "#FF3333"
                            y : stubListViewId.currentItem.y
                        }
                    }

                    Component {
                        id : headerId
                        Rectangle {
                            id : headerRectId
                            color : "darkturquoise"
                            border.color: "grey"
                            width : stubListViewId.width
                            height : 30
                            RowLayout{
                                anchors.verticalCenter: parent.verticalCenter
                                spacing : 20
                                x: 10
                                Repeater {
                                    model : ["Name", "Median", "  Email  ", "Grade1", "Grade2", "Grade2",
                                        "Homework", "Project"]
                                    DelegateItem {
                                        delegateFontSize  : 10
                                        delegateFontColor : "black"
                                        textData: modelData
                                        Button{
                                            id: delegateButton
                                            anchors.centerIn : parent
                                            height : 30
                                            width : 116

                                            style: ButtonStyle{
                                                background: Rectangle {
                                                    color : "transparent"
                                                    border.color : delegateButton.hovered ? "white" : "transparent"
                                                    border.width: 1.2
                                                }
                                            }
                                        }
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
                width: 300
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
                anchors.rightMargin : 10
                style: ButtonStyle{
                    background: Rectangle {
                        color : prevButton.hovered ? "lightsteelblue" : "lightslategrey"
                        implicitWidth : 100
                        implicitHeight : 30
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "darkslateblue"
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
                        color : nextButton.hovered ? "lightsteelblue" : "lightslategrey"
                        implicitWidth : 100
                        implicitHeight : 30
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "darkslateblue"
                        radius: 4
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        dateString = currentDate.toLocaleDateString();
    }

}
