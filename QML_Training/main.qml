import QtQuick 2.12
import QtQuick.Controls 2.12

Window
{
    id: root
    width: 640
    height: 480
    visible: true
    flags: Qt.Window
    title: qsTr("asdsa")

    Menu {
        id: menu
        MenuItem {
            text: qsTr("New...")
        }
        MenuItem {
            text: qsTr("Open...")
        }
        MenuItem {
            text: qsTr("Save")
        }

        MenuSeparator {
            padding: 0
            topPadding: 12
            bottomPadding: 12
            contentItem: Rectangle {
                implicitWidth: 200
                implicitHeight: 1
                color: "#1E000000"
            }
        }

        MenuItem {
            text: qsTr("Exit")
        }
    }
}



