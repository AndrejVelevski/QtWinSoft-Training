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

            TextPlus {
                text: "This list:  "
                font.family: "lucida grande"
                font.pixelSize: 12
                font.bold: true
                textColor: "#333"
            }

            HyperlinkRed {
                text: "Edit"

                onClicked: {
                    stack.replace(editListPage);
                }
            }

            TextPlus {
                text: "  |  "
                font.family: "lucida grande"
                font.pixelSize: 10
                textColor: "#666"
                visible: linkReorder.visible
            }

            Row {
                HyperlinkRed {
                    id: linkReorder
                    text : reordering?"I'm done reordering":"Reorder"
                    backgroundColor: reordering?"yellow":"transparent"
                    property bool reordering: false

                    visible: content.modelIncomplete.model.count > 1

                    onClicked: {
                        reordering = !reordering;
                        scrollTasksPage.reorder(reordering);
                    }
                }

                TextPlus {
                    text: "  |  "
                    font.family: "lucida grande"
                    font.pixelSize: 10
                    textColor: "#666"
                }

                HyperlinkRed {
                    id: sharing
                    property bool shared: false
                    text: shared?"Sharing":"Not Sharing"

                    onClicked: {
                        shared = !shared;
                        server.setSharing(root.listid, shared);
                    }
                }

                Connections {
                    target: server

                    function onGetTasks(list, tasks) {
                        sharing.shared = list.sharing;
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

            onClicked: {
                stack.replace(homePage);
            }
        }
    }
}
