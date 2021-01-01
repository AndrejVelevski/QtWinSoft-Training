import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    title: qsTr("Ta-da")
    width: 640
    height: 480
    minimumWidth: 410
    minimumHeight: 300

    Item {
        width: 3*parent.width/4
        height: parent.height
        anchors.centerIn: parent

        ColumnLayout {
            spacing: 0
            anchors.fill: parent

            Item { height: 25 }

            Header { }

            Item { height: 30 }

            Splitter { }

            Item { height: 10 }

            Content {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            Item { height: 25 }
        }
    }
}
