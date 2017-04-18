import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.2

Component {

    //objectName: "listDelegate"

    Item {
        id: wrapper
        width: parent.width
        height: 25
        RowLayout {
            anchors.verticalCenter: parent.verticalCenter
            spacing : 20
            x: 10
            //Text {text : name}
            DelegateItem { textData : name }
            DelegateItem { textData : finalgrade.toFixed(2)}
            DelegateItem { textData : email }
            DelegateItem { textData : homework1.toFixed(2) }
            DelegateItem { textData : homework2.toFixed(2) }
            DelegateItem { textData : labgrade.toFixed(2) }
            DelegateItem { textData : testgrade.toFixed(2)
                           delimiterVisible: false}

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
            onClicked: {
                wrapper.ListView.view.currentIndex = index
                console.log("Current index changed: " + index)
            }
            onDoubleClicked:  informStudentDetails(index)
        }
    }
}
