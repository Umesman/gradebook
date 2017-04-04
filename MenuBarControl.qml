import QtQuick 2.2
import QtQuick.Controls 1.1

MenuBar{
        Menu {
            title : "File"
            MenuItem { text : "Open.." }
            MenuItem { text : "Save As.." }
            MenuItem { text : "Exit"
                onTriggered: Qt.quit()}
        }

        Menu {
            title: "Tools"
            MenuItem { text : "Add Entry.." }
            MenuItem { text : "Edit Entry.." }
            MenuItem { text : "Remove Entry.." }
        }

    }
