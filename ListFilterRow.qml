import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

RowLayout {
    // inform the View Manager about the change of group to update the view
    signal informGroupSelection(int index)

    // inform the View Manager, only the students with the median > 5 should be visible in the view
    signal informFilterChecked()
    signal informFilterUnchecked()

    //property bool editActive : editBoxId.checked

    //id : firstRowId
    anchors {
        top : parent.top
        horizontalCenter: parent.horizontalCenter
        topMargin: 20
    }
    spacing: 50


    Rectangle {
        color : "transparent"
        Layout.fillWidth: true
        Layout.minimumWidth: minimumRectWidth
        Layout.preferredWidth: preferredRectWidth
        Layout.maximumWidth: maximumRectWidth
        Layout.minimumHeight: minimumRectHeight

        ComboBox {
            id : comboBoxId
            //anchors.left: parent.left
            //anchors.leftMargin: 15
            //anchors.verticalCenter: parent.verticalCenter
            anchors.centerIn: parent
            width: 120
            height: 40
            model: [ "All Groups", "Group A", "Group B", "Group C", "Group D"]
            //editable: true

            style: ComboBoxStyle{
                background :
                    Rectangle{
                    width: 120
                    height: 40
                    radius: 4
                    color : comboBoxId.hovered ? "lightsteelblue" : "lightslategrey"
                    Image {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: 5
                        source: comboBoxId.pressed ? "qrc:/Images/Images/dropdown_checked.png"
                                                   : "qrc:/Images/Images/dropdown.png"
                    }

                }
            }

            onActivated:{
                viewMgr.groupFilter = index;
                console.log("InformGroupSelection" + index) }
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
            anchors.centerIn: parent
            onClicked: { checked ? informFilterChecked() : informFilterUnchecked()
                console.log("Filter passed ? " + checked)
                viewMgr.passed = ! viewMgr.passed
            }

            //            Label {
            //                anchors.left: parent.right
            //                text : "Passed" }

            style : CheckBoxStyle {
                //                indicator : Rectangle{
                //                    id : extern
                //                    implicitHeight: 16
                //                    implicitWidth: 16
                //                    radius: 16
                //                    border.color: checkBoxId.activeFocus ? "red" : "black"
                //                    border.width: 1

                //                    Rectangle {
                //                        id : intern
                //                        visible: checkBoxId.checked
                //                        color: "#555"
                //                        border.color: "#333"
                //                        radius: 16
                //                        anchors.margins: 4
                //                        anchors.fill: parent
                //                    } // Rectangle
                //                } // Rectangle

                background: Rectangle{
                    color : "transparent" //checkBoxId.hovered ? "lightsteelblue" : "lightslategrey"
                    implicitWidth : 100
                    implicitHeight : 30
                    //border.width: control.activeFocus ? 2 : 1
                    // border.color: "darkslateblue"
                    radius: 8
                    Text{ text: qsTr("Passed")
                        anchors.centerIn: parent
                        //color: checkBoxId.checked ?  "midnightblue" : BoxId.hovered ? "cadetblue" : "black"
                        //http://stackoverflow.com/questions/38798450/qt-5-7-qml-why-are-my-checkbox-property-bindings-disappearing
                        Binding on color {
                            when: checkBoxId.checked
                            value: "midnightblue"
                        }
                    }

                } // Rectangle
            } //CheckBoxStyle
        } //CheckBox

    } // Rectangle

    Rectangle {
        color : "transparent"
        Layout.fillWidth: true
        Layout.minimumWidth: minimumRectWidth
        Layout.preferredWidth: preferredRectWidth
        Layout.maximumWidth: maximumRectWidth
        Layout.minimumHeight: minimumRectHeight

        Image {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: dateLabelId.left
            //anchors.leftMargin: 75
            source : "qrc:/Images/Images/date.png"
        }

        Text {
            //color : "white"
            anchors.left: parent.left
            anchors.leftMargin: 75
            anchors.verticalCenter: parent.verticalCenter
            id : dateLabelId
            text: dateString
        }

    }

}

