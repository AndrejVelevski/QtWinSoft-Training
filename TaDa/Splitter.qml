import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    spacing: 0

    Item {
        height: 30
    }

    Rectangle {
        width: childrenRect.width
        height: childrenRect.height
        color: "transparent"

        TextEdit {
            text: "MY LISTS"
            font.family: "lucia grande"
            font.pixelSize: 10
            color: "#630"

            readOnly: true
            selectByMouse: true
        }
    }

    Rectangle {
        Layout.fillWidth: true
        height: 1
        color: "#333"
    }

    Item {
        height: 10
    }
}
