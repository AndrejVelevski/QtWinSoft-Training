import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    width: childrenRect.width
    height: childrenRect.height

    Rectangle {
        width: childrenRect.width + 40
        height: logo.height - 10
        x: logo.width
        y: 8
        color: "#efefef"
        radius: height/2

        Rectangle {
            width: parent.radius
            height: parent.height
            color: parent.color
        }

        RowLayout {
            spacing: 0
            anchors.top: parent.top
            anchors.bottom: parent.bottom

            TextPlus {
                Layout.alignment: Qt.AlignVCenter
                text: "My Lists"
                font.family: "helvetica"
                font.pixelSize: 24
                font.bold: true
                Layout.leftMargin: 12
                Layout.rightMargin: 12
            }

            HyperlinkRed {
                text: "Create a new list"

                onClicked: {
                    stack.replace(newListPage);
                }
            }
        }
    }

    Image {
        id: logo
        source: "qrc:/res/tada.png"

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor

            onClicked: {
                stack.replace(homePage);
            }
        }
    }
}
