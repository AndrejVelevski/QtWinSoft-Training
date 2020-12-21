import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        width: 300
        height: 200
        color: "red"
        border.width: 4
        border.color: "black"

        Rectangle {
            anchors.centerIn: parent
            width: 50
            height: 50
            color: "yellow"
            radius: width / 2
        }

        Rectangle {
            anchors.centerIn: parent
            width: parent.width - 2 * parent.border.width
            height: 10
            color: "yellow"
        }

        Rectangle {
            anchors.centerIn: parent
            width: 10
            height: parent.height - 2 * parent.border.width
            color: "yellow"
        }
    }
}
