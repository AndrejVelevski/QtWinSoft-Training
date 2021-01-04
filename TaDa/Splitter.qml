import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Column {
    height: childrenRect.height
    width: root.width - 300

    TextPlus {
        text: "MY LISTS"
        font.family: "lucia grande"
        font.pixelSize: 10
        textColor: "#630"
    }

    Rectangle {
        width: parent.width
        height: 1
        color: "#ccc"
    }
}


