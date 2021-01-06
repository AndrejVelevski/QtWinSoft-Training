import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Window {
    id: root
    visible: true
    title: qsTr("Ta-da")
    width: 1024
    height: 768
    property int listid: -1

    StackView {
        id: stack
        initialItem: homePage
        anchors.fill: parent
    }

    Component {
        id: homePage

        HomePage { }
    }

    Component {
        id: newListPage

        NewListPage { }
    }

    Component {
        id: tasksPage

        TasksPage { }
    }

    Component {
        id: editListPage

        EditListPage { }
    }
}
