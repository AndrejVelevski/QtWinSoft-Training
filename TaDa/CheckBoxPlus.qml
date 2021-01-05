import QtQuick 2.0

Rectangle {
    width: img.width
    height: img.height
    signal clicked()
    property bool checked: false
    border.width: 1
    radius: 3

    Image {
        id: img
        source: "qrc:/res/checkbox.png"
        visible: parent.checked
    }

    Rectangle {
        anchors.fill: parent
        id: overlay
        color: Qt.rgba(1, 1, 1, 0.5)
        visible: false
    }

    MouseArea {
        z: -1
        hoverEnabled: true
        anchors.fill: parent

        onPressed: {
            overlay.visible = true;
        }

        onReleased: {
            overlay.visible = false;
            parent.checked = !parent.checked;
            parent.clicked();
        }

        onExited: {
            overlay.visible = false;
        }
    }
}
