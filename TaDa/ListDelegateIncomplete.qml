import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    width: childrenRect.width
    height: childrenRect.height + 9

    Flow {
        width: root.width - 300

        Rectangle {
            id: dot
            width: 24
            height: 24
            color: "transparent"

            Rectangle {
                width: calculateSize()
                height: calculateSize()
                anchors.centerIn: parent
                radius: width/2
                color: "#666"

                function calculateSize() {
                    return Math.max(4, Math.min(12, numTasks-numCompletedTasks+4));
                }
            }
        }

        HyperlinkBlue {
            id: text
            text: name
            font.pixelSize: 16
            font.bold: true

            textWidth: {
                if (textWidth > parent.width - info.width - dot.width - 8)
                    return parent.width - info.width - dot.width - 8
            }

            onClicked:  {
                root.listid = id;
                stack.replace(tasksPage);
            }
        }

        TextPlus {
            id: info
            visible: numTasks > 0

            text: `— <b>${numTasks-numCompletedTasks} left</b>${sharing?" (Sharing)":""}`
            textFormat: Text.MarkdownText
            font.family: "lucia grande"
            font.pixelSize: 10
            textColor: "#666"
            leftPadding: 8
            topPadding: text.height - 14
        }
    }
}
