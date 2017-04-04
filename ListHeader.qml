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
        RowLayout{
            anchors.verticalCenter: parent.verticalCenter
            spacing : 20
            x: 10
            Repeater {
                id : headerRepeater
                model : ["Name", "Median", "Email", "Grade1", "Grade2", "Grade2",
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

                        onClicked: {
                            sortBy(headerRepeater.model.index)
                            console.log(headerRepeater.model.index)

                        }
                    }
                }
            }
        }
    }
}
