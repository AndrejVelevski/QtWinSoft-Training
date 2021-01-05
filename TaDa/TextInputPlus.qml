import QtQuick 2.12

Rectangle {
    width: 640
    height: childrenRect.height
    border.width: 1
    radius: 3
    property alias text: text.text
    property alias font: text.font
    property alias padding: text.padding
    signal accepted()

    TextInput {
        id: text
        width: parent.width
        font.family: "arial"
        font.pixelSize: 14
        selectionColor: "#3390ff"
        padding: 5
        selectByMouse: true
        clip: true

        onAccepted: parent.accepted()

        onTextChanged: parent.textChanged()

        MouseArea {
            z: -1
            anchors.fill: parent
            cursorShape: Qt.IBeamCursor
        }
    }
}
