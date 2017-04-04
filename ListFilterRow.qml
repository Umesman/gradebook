import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

RowLayout {
    //id : firstRowId
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
            style: ComboBoxStyle{
                background :
                    Rectangle{
                    width: 120
                    height: 40
                    color : comboBoxId.hovered ? "lightsteelblue" : "lightslategrey"
                }
                //selectedTextColor : "red"
                renderType: Text.NativeRendering
            }
            model: [ "All Groups", "Group A", "Group B", "Group C", "Group D"]
            //currentIndex :
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
                    Text{ text: qsTr("Passed")
                        anchors.centerIn: parent}

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

