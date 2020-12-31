import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    title: qsTr("Hello World")
    width: 640
    height: 480

    Rectangle {
        anchors.fill: parent
        color: "antiquewhite"

        ColumnLayout {
            anchors.fill: parent
            spacing: 0

            Header { }

            Splitter { }

            Content {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
