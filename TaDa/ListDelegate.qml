import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    width: childrenRect.width
    height: childrenRect.height + 9

    RowLayout {
        spacing: 0

        Rectangle {
            width: text.height + 8
            height: text.height
            color: "transparent"

            Rectangle {
                width: calculateSize()
                height: calculateSize()
                anchors.centerIn: parent
                radius: width/2
                color: "#333"

                function calculateSize() {
                    return Math.max(4, Math.min(12, numItems+4));
                }
            }
        }

        Rectangle {
            width: childrenRect.width
            height: childrenRect.height
            color: "transparent"

            TextEdit {
                id: text
                text: name
                font.family: "lucia grande"
                font.pixelSize: 16
                font.underline: true
                font.bold: true
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

        Rectangle {
            width: childrenRect.width
            height: childrenRect.height
            color: "transparent"

            TextEdit {
                text: `— <b>${numItems} left</b>${sharing?" (Sharing)":""}`
                textFormat: Text.MarkdownText
                font.family: "lucia grande"
                font.pixelSize: 10
                color: "#666"
                leftPadding: 4

                readOnly: true
                selectByMouse: true
            }
        }
    }
}
