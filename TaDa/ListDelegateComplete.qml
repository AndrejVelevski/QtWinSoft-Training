import QtQuick 2.12

Row {
    Rectangle {
        width: childrenRect.width
        height: childrenRect.height
        color: "transparent"

        TextEdit {
            id: text
            text: name
            font.family: "lucia grande"
            font.pixelSize: 10
            font.underline: true
            color: "#03c"

            readOnly: true
            selectByMouse: true

            MouseArea {
                z: -1
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true

                onEntered: {
                    parent.color = "white";
                    parent.parent.color = "#30c";
                }
                onExited: {
                    parent.color = "#03c";
                    parent.parent.color = "transparent";
                }
            }
        }
    }

    Text {
        y: -4
        text: ", "
        color: "#333"
        leftPadding: 1
        visible: !last
    }
}
