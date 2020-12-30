import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    flags: Qt.Window
    title: qsTr("ChatApp")
    minimumWidth: 300
    minimumHeight: 400
    property color colorBackground: Qt.rgba(0.9, 0.9, 0.9, 1)
    property color colorAccent: Qt.rgba(0.7, 0.7, 0.7, 0.5)
    property color colorTextBorder: Qt.rgba(0, 0, 0, 1)
    property color colorInvisible: Qt.rgba(0, 0, 0, 0)
    property string username: "Default"

    color: colorBackground

    Image {
        width: parent.width
        height: parent.height
        fillMode: Image.Tile
        source: "qrc:/res/nebula.jpg"

        Rectangle {
            id: cover
            anchors.fill: parent
            color: Qt.rgba(1, 1, 1, 0.2)
        }

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 8

            MyTaskbar {
                Layout.fillHeight: true
            }

            StackView {
                id: stack
                initialItem: pageHome
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            MyLabel {
                id: status
                objectName: "status"
                border.width: 2
                padding: 16
                text: ""
                width: 0
                color: root.colorAccent
                Layout.fillWidth: true
            }
        }
    }

    Component {
        id: pageHome

        MyPageHome {}
    }

    Component {
        id: pageChat

        MyPageChat {}
    }
}
