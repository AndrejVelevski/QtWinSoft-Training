import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ColumnLayout {
    spacing: 0

    RowLayout {
        spacing: 0

        TextPlus {
            text: "Name your new list"
            font.family: "helvetica"
            font.pixelSize: 16
            font.bold: true
            Layout.bottomMargin: 5

        }

        TextPlus {
            text: " (Ex: \"Things I need to do today\")"
            font.family: "helvetica"
            font.pixelSize: 10
            Layout.leftMargin: 3
            textColor: "#666"
        }
    }

    Rectangle {
        Layout.fillWidth: true
        Layout.bottomMargin: 10
        height: childrenRect.height
        border.width: 1
        radius: 3

        TextInput {
            id: textbox
            width: parent.width
            font.family: "arial"
            font.pixelSize: 20
            font.bold: true
            color: "black"
            selectionColor: "#3390ff"
            padding: 5
            selectByMouse: true

            onAccepted: createNewList(text)
        }
    }

    function createNewList(name) {
        name = name.trim();
        if (name.length > 0)
            server.createNewList(name);
    }

    RowLayout {

        Image {
            source: "qrc:/res/create-list.png"

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: createNewList(textbox.text)

                Connections {
                    target: server

                    function onNewListCreated() {
                        stack.replace(homePage);
                    }
                }
            }
        }

        TextPlus {
            text: "or"
            font.pixelSize: 11
            font.family: "lucida grande"
        }

        HyperlinkRed {
            text: "Cancel"
            onClicked: stack.replace(homePage)
        }
    }
}
