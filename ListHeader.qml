import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

Component {
    Rectangle {
        id : headerRectId
        color : "darkturquoise"
        border.color: "grey"
        width : stubListViewId.width
        height : 30
        clip: true
        z: 2
        RowLayout{
            anchors.verticalCenter: parent.verticalCenter
            spacing : 20
            x: 10
            Repeater {
                id : headerRepeater
                model : 9
                delegate: DelegateItem {
                    delegateFontSize  : 10
                    delegateFontColor : "black"
                    textData: viewMgr.model.headerData(index, 1, 0)
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

                        onClicked: if (index != 8){
                            viewMgr.sortRole = index
                            console.log("Sort By" + index)
                            }

                    }
                }
            }
        }
    }
}
