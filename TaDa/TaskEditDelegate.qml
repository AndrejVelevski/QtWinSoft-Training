import QtQuick 2.0

Column {
    id: col
    visible: !shouldDelete

    Row {
        TextInputPlus {
            id: ti
            text: name
            padding: 8

            onTextChanged: {
                name = text;
            }

            onAccepted: acceptChanges()
        }

        Rectangle {
            width: 30
            height: 30
            color: Qt.rgba(0, 0, 0, 0)

            Image {
                source: "qrc:/res/delete.png"
                anchors.centerIn: parent

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        shouldDelete = true
                    }
                }
            }
        }
    }

    Item {
        width: 1
        height: 15
    }
}
