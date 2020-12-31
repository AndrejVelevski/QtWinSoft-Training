import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    width: childrenRect.width
    height: childrenRect.height

    Rectangle {
        width: childrenRect.width + 40
        height: parent.height - 10
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

            TextEdit {
                Layout.alignment: Qt.AlignVCenter
                text: "My Lists"
                font.family: "helvetica"
                font.pixelSize: 24
                font.bold: true
                Layout.leftMargin: 8
                Layout.rightMargin: 8
                bottomPadding: 2

                readOnly: true
                selectByMouse: true
            }

            Rectangle {
                width: childrenRect.width
                height: childrenRect.height
                color: "transparent"

                TextEdit {
                    text: "Create a new list"
                    font.family: "verdana"
                    font.pixelSize: 11
                    font.underline: true
                    color: "red"

                    readOnly: true
                    selectByMouse: true

                    MouseArea {
                        z: -1
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true

                        onEntered: {
                            parent.color = "white";
                            parent.parent.color = "red";
                        }
                        onExited: {
                            parent.color = "red";
                            parent.parent.color = "transparent";
                        }
                    }
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
        }
    }
}
