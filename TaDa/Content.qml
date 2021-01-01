import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 0

    ListView {
        model: ListModel { id: modelIncomplete }
        delegate: ListDelegateIncomplete { }
        clip: true
        Layout.fillWidth: true
        Layout.fillHeight: true

        ScrollBar.vertical: ScrollBar { }
    }

    Flow {
        id: flow
        Layout.fillWidth: true

        Rectangle {
            width: childrenRect.width
            height: childrenRect.height
            color: "transparent"
            visible: modelIncomplete.count > 0

            TextEdit {
                text: "Completed Lists: "
                font.family: "lucia grande"
                font.pixelSize: 10
                font.bold: true
                color: "#666"

                readOnly: true
                selectByMouse: true
            }
        }

        Repeater {
            model: ListModel { id: modelComplete }

            delegate: ListDelegateComplete { }
        }
    }

    Component.onCompleted: {
        server.requestCompleteLists();
        server.requestIncompleteLists();
    }

    Connections {
        target: server

        function onGetCompleteLists(lists) {
            for (let i=0;i<lists.length;++i)
            {
                let l = lists[i];

                modelComplete.append({
                    id: l.id,
                    name: l.name,
                    last: i === lists.length-1
                });

            }
        }

        function onGetIncompleteLists(lists) {
            for (let l of lists)
            {
                modelIncomplete.append({
                    id: l.id,
                    name: l.name,
                    numTasks: l.numTasks,
                    sharing: l.sharing
                });
            }
        }
    }
}



