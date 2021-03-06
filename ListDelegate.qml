import QtQuick 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

Component {

    Item {
        id: wrapper
        width: parent.width
        height: 25
        RowLayout {
            id : delegateRowLayout
            anchors.verticalCenter: parent.verticalCenter
            spacing : 20
            x: 10
            //Text {text : name}
            DelegateItem { textData : firstName }
            DelegateItem { textData : lastName }
            DelegateItem { textData : finalgrade.toFixed(2)}
            DelegateItem { textData : email }
            DelegateItem { textData : homework1.toFixed(2) }
            DelegateItem { textData : homework2.toFixed(2) }
            DelegateItem { textData : labgrade.toFixed(2) }
            DelegateItem { textData : testgrade.toFixed(2)
                delimiterVisible: false}
            Rectangle{
                color : "transparent"
                height: 25
                width: 106
            }//Rectangle

            MouseArea{
                objectName: "MouseArea"
                anchors.fill: parent
                onClicked: {
                    if (!viewMgr.editMode) {
                    wrapper.ListView.view.currentIndex = index
                    console.log("Current index changed: " + index)
                    console.log("Current id " + model.id)
                    }
                }
                onDoubleClicked:  informStudentDetails(index)
            }//MouseArea

        }// RowLayout

        CheckBox{
            id: editCheckBox
            objectName: "CheckBox"

            anchors.left: parent.left
            anchors.leftMargin: (parent.width - (editCheckBox.width*2 + 16))
            height: 25
            width: 40
            style : CheckBoxStyle {
                background: Rectangle{
                    color : "transparent"
                    implicitWidth : 40
                    implicitHeight : 25
                    Rectangle{
                        anchors.left: parent.left
                        implicitHeight: parent.implicitHeight / 3
                        implicitWidth: 1
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    Rectangle{
                        anchors.right: parent.right
                        anchors.rightMargin: 1
                        implicitHeight: parent.implicitHeight / 3
                        implicitWidth: 1
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                indicator: Rectangle {
                    id: indicatorRect
                    color : "transparent"
                    implicitHeight: 16
                    implicitWidth: 16
                    radius: 16
                    Image{
                        id : editImage
                        anchors.left: parent.right
                        anchors.leftMargin: -9
                        anchors.verticalCenter: parent.verticalCenter
                        source: (viewMgr.editMode && wrapper.ListView.view.currentIndex === index) ?
                                    "qrc:/Images/Images/edit.png" : "qrc:/Images/Images/edit_checked.png"
//                        source: "qrc:/Images/Images/edit.png"
//                        Binding{
//                            target: editImage
//                            property: "source"
//                            value : "qrc:/Images/Images/edit_checked.png"
//                             when : editCheckBox.checked
//                        }
                    }
                }
            }

            //http://stackoverflow.com/questions/38798450/qt-5-7-qml-why-are-my-checkbox-property-bindings-disappearing

            onClicked: {
                wrapper.ListView.view.currentIndex = index
                //viewMgr.editMode = !viewMgr.editMode
                viewMgr.editStudentInfo(model.id);
            }
            enabled: viewMgr.editMode ? false : true
        }
        Button{
            id: deleteButton
            anchors.left: editCheckBox.right
            anchors.leftMargin: 2
            style: ButtonStyle{
                background: Rectangle {
                    color : "transparent"//deleteButton.hovered ? "lightsteelblue" : "lightslategrey"
                    implicitWidth : 40
                    implicitHeight : 25
                    Rectangle{
                        anchors.right: parent.right
                        implicitHeight: parent.implicitHeight / 3
                        implicitWidth: 1
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    Image {
                        anchors.centerIn: parent
                        source : deleteButton.pressed ? "qrc:/Images/Images/delete.png"
                                                      : "qrc:/Images/Images/delete_checked.png"
                    }
                }
            }

            onClicked:{
                informDeleteEntry()
                console.log("deleteButton clicked")
            }

            action: Action{
                enabled: viewMgr.editMode ? false : true
            }


        }

        Rectangle{
            id : delimiter
            anchors.top: delegateRowLayout.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width - 40
            height : 1
            color: "teal"
        }
        transitions: Transition {
            NumberAnimation { properties: "x"; duration: 200 }
        }
    }
}
