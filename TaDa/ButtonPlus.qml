import QtQuick 2.12

Rectangle {
    color: Qt.rgba(0, 0, 0, 0)
    border.width: 1
    radius: 3
    width: childrenRect.width + 16
    height: childrenRect.height + 8
    property alias text: text.text
    signal clicked()

    Rectangle {
        anchors.fill: parent
        id: overlay
        color: Qt.rgba(0, 0, 0, 0.1)
        visible: false
    }

    TextPlus {
        id: text
        text: "Button"
        font.pixelSize: 13
        font.family: "arial"
        font.bold: true
        anchors.centerIn: parent
    }

    MouseArea {
        hoverEnabled: true
        anchors.fill: parent

        onPressed: {
            overlay.visible = false;
        }

        onReleased: {
            overlay.visible = true;
            parent.clicked();
        }

        onEntered: {
            overlay.visible = true;
        }

        onExited: {
            overlay.visible = false;
        }
    }
}
