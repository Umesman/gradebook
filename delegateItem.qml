import QtQuick 2.2

property int headerFontSize : 14

Rectangle {
    property alias textData : delegateTextId.text

    color: "red"
    width : 96
    height: 20
    Text{
        id : delegateTextId
        anchors.centerIn: parent
        text: modelData
        font.pointSize: headerFontSize}
}
