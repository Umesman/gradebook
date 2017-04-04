import QtQuick 2.0
import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

RowLayout{
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
