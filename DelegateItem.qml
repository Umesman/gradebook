import QtQuick 2.2
import QtQuick.Controls 2.0


Rectangle {
    property alias delegateFontSize : delegateTextId.font.pointSize
    property alias textData : delegateTextId.text
    property alias isBold : delegateTextId.font.bold
    property alias delegateFontColor : delegateTextId.color
    property alias delimiterVisible : delegateRectId.visible

    color: "transparent"
    width : 96
    height: 20

    Text{
        id : delegateTextId
        anchors.centerIn: parent
        text: modelData
        font.pointSize: 10
        font.bold: false
        color: "white"
    }

    Rectangle{
        id : delegateRectId
        anchors.right : parent.right
        width: 1
        height : 20
        visible: false
    }
}

