import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4

Rectangle{
    property int minimumRectLabelHeight: 24
    property int preferedRectLabelWidth: 80
    property int minimumRectLabelWidth: 40
    property int textFieldImplicitWidth: 195
    property int textFieldImplicitHeight: 24
    property string backgroundRectColor: "transparent"

    border.color: "#333"
    border.width: 2

    Component{
        id: upperTextFieldStyle
        TextFieldStyle {
            textColor: "black"
            background: Rectangle {
                radius: 2
                implicitWidth: textFieldImplicitWidth
                implicitHeight: textFieldImplicitHeight
                border.color: "#333"
                border.width: 1
            }
            placeholderTextColor: "grey"
        }
    }

    Component{
        id: lowerTextFieldStyle
        TextFieldStyle {
            textColor: "black"
            background: Rectangle {
                radius: 2
                implicitWidth: 120
                implicitHeight: textFieldImplicitHeight
                border.color: "#333"
                border.width: 1
            }
            placeholderTextColor: "grey"
        }
    }

    id: root
    height : 320
    width: 300
    ColumnLayout{
        anchors.top: root.top
        anchors.topMargin: 10
        anchors.left: root.left
        anchors.leftMargin: 10
        spacing: 10
        RowLayout{
            Rectangle{
                color: backgroundRectColor
                Layout.fillWidth: false
                Layout.minimumWidth: minimumRectLabelWidth
                Layout.preferredWidth: preferedRectLabelWidth
                Layout.minimumHeight: minimumRectLabelHeight

                Label{
                    id: firstNameLabel
                    anchors.verticalCenter: parent.verticalCenter
                    text: "First Name"
                }
            }

            TextField{
                id: firstNameField
                style: upperTextFieldStyle
                text: editForm.firstName

                Binding{
                    target: editForm
                    property: "firstName"
                    value : firstNameField.text
                }
            }
        }
        RowLayout{
            Rectangle{
                color: backgroundRectColor
                Layout.fillWidth: false
                Layout.minimumWidth: minimumRectLabelWidth
                Layout.preferredWidth: preferedRectLabelWidth
                Layout.minimumHeight: minimumRectLabelHeight

                Label{
                    id : lastNameLabel
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Last Name"
                }
            }
            TextField{
                id : lastNameField
                style: upperTextFieldStyle
                text: editForm.lastName

                Binding{
                    target: editForm
                    property: "lastName"
                    value : lastNameField.text
                }
            }
        }
        RowLayout{
            Rectangle{
                color: backgroundRectColor
                Layout.fillWidth: false
                Layout.minimumWidth: minimumRectLabelWidth
                Layout.preferredWidth: preferedRectLabelWidth
                Layout.minimumHeight: minimumRectLabelHeight

                Label{
                    id : emailLabel
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Email"
                }
            }

            TextField{
                id : emailField
                style: upperTextFieldStyle
                text: editForm.email

                Binding{
                    target: editForm
                    property: "email"
                    value : emailField.text
                }
            }
        }
        Rectangle{
            height: 1
            width: 280
            color: "black"
        }

        GridLayout{
            columns: 2
            columnSpacing: 40
            rowSpacing: 4
            Rectangle{
                Layout.fillWidth: false
                Layout.preferredWidth: 120
                Layout.minimumHeight: 40
                color : backgroundRectColor
                Label{
                    id : hmk1Label
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Homework#1"
                }
                TextField{
                    focus: true
                    id : hmk1TextField
                    anchors.top: hmk1Label.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    style: lowerTextFieldStyle
                    text: editForm.homework1.toFixed(2)

                    Binding{
                        target: editForm
                        property: "homework1"
                        value : hmk1TextField.text
                    }
                }
            }
            Rectangle{
                Layout.fillWidth: false
                Layout.preferredWidth: 120
                Layout.minimumHeight: 40
                color : backgroundRectColor
                Label{
                    id : hmk2Label
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Homework#2"
                }
                TextField{
                    id : hmk2TextField
                    anchors.top: hmk2Label.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    style : lowerTextFieldStyle
                    text: editForm.homework2.toFixed(2)

                    Binding{
                        target: editForm
                        property: "homework2"
                        value : hmk2TextField.text
                    }
                }
            }
            Rectangle{
                Layout.fillWidth: false
                Layout.preferredWidth: 120
                Layout.minimumHeight: 40
                color : backgroundRectColor
                Label{
                    id : labGradeLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Lab Grade"
                }
                TextField{
                    id : labTextField
                    anchors.top: labGradeLabel.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    style : lowerTextFieldStyle
                    text: editForm.labGrade.toFixed(2)

                    Binding{
                        target: editForm
                        property: "labGrade"
                        value : labTextField.text
                    }

                }
            }
            Rectangle{
                Layout.fillWidth: false
                Layout.preferredWidth: 120
                Layout.minimumHeight: 40
                color : backgroundRectColor
                Label{
                    id : testGradeLabel
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Test Grade"
                }
                TextField{
                    id : testTextField
                    anchors.top: testGradeLabel.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    style : lowerTextFieldStyle
                    text : editForm.testGrade.toFixed(2)
                }

                Binding{
                    target: editForm
                    property: "testGrade"
                    value : testTextField.text
                }

            }
        }

        Rectangle{
            height: 1
            width: 280
            color: "black"
        }

        Rectangle {
            color: backgroundRectColor
            Layout.fillWidth: false
            Layout.minimumWidth: 280
            Layout.preferredWidth: preferedRectLabelWidth
            Layout.minimumHeight: minimumRectLabelHeight

            Button{
                id : resetButton
                anchors.right: parent.right
                anchors.rightMargin: 5
                Label{
                    text: "Reset"
                    anchors.centerIn: parent
                }
            }
        }

        Rectangle{
            height: 1
            width: 280
            color: "black"
        }

        Rectangle {
            color: backgroundRectColor
            Layout.fillWidth: false
            Layout.minimumWidth: 280
            Layout.preferredWidth: preferedRectLabelWidth
            Layout.minimumHeight: minimumRectLabelHeight

            Button{
                id : confirmButton
                anchors.right: cancelButton.left
                anchors.rightMargin: 5
                Label{
                    anchors.centerIn: parent
                    text: "Confirm"
                }
                onClicked:{
                    //updateFormData()
                    editForm.confirmStudentInfo()
                }
            }

            Button{
                id : cancelButton
                anchors.right: parent.right
                anchors.margins: 5
                Label{
                    anchors.centerIn: parent
                    text: "Cancel"
                }
                onClicked: editForm.cancelStudentInfo()
            }

        }

    }
}
