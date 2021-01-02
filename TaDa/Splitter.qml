import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

ColumnLayout {
    spacing: 0

    TextPlus {
        text: "MY LISTS"
        font.family: "lucia grande"
        font.pixelSize: 10
        textColor: "#630"
    }

    Rectangle {
        Layout.fillWidth: true
        height: 1
        color: "#ccc"
    }
}


