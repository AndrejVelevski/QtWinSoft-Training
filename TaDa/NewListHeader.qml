import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    width: childrenRect.width
    height: childrenRect.height

    Rectangle {
        width: childrenRect.width + 15
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

            HyperlinkBlue {
                text: "My Lists"
                font.pixelSize: 14
                Layout.leftMargin: 12
                Layout.rightMargin: 12

                onClicked: {
                    stack.replace(homePage);
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
