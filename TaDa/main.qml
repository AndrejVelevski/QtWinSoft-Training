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

        StackView {
            id: stack
            initialItem: homePage
            anchors.fill: parent
        }
    }

    Component {
        id: homePage

        HomePage { }
    }

    Component {
        id: newListPage

        NewListPage { }
    }
}
