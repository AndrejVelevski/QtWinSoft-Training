import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ColumnLayout {
    spacing: 0

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
        color: "#ccc"
    }
}


