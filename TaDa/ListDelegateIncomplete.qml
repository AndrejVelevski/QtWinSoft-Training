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
                color: "#666"

                function calculateSize() {
                    return Math.max(4, Math.min(12, numTasks+4));
                }
            }
        }

        HyperlinkBlue {
            id: text
            text: name
            font.pixelSize: 16
            font.bold: true
        }

        TextPlus {
            visible: numTasks > 0

            text: `— <b>${numTasks-numCompletedTasks} left</b>${sharing?" (Sharing)":""}`
            textFormat: Text.MarkdownText
            font.family: "lucia grande"
            font.pixelSize: 10
            textColor: "#666"
            anchors.leftMargin: 4
        }
    }
}
