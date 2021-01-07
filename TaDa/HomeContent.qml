import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Column {
    Item {
        width: 1
        height: 35
    }

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

    Item {
        width: 1
        height: 10
    }

    Column {
        Repeater {
            id: list
            model: ListModel { id: modelIncomplete }
            delegate: ListDelegateIncomplete { }
            clip: true
        }
    }

    Flow {
        id: flow
        width: root.width - 300

        TextPlus {
            visible: modelComplete.count > 0
            text: "Completed Lists: "
            font.family: "lucia grande"
            font.pixelSize: 10
            font.bold: true
            textColor: "#666"
        }

        Repeater {
            model: ListModel { id: modelComplete }

            delegate: ListDelegateComplete { }
        }
    }

    Component.onCompleted: {
        server.requestLists();
    }

    Connections {
        target: server

        function onGetLists(lists) {
            for (let l of lists)
            {
                if (l.numTasks !== l.numCompletedTasks || l.numTasks === 0)
                {
                    modelIncomplete.append({
                        id: l.id,
                        name: l.name,
                        numTasks: l.numTasks,
                        numCompletedTasks: l.numCompletedTasks,
                        sharing: l.sharing
                    });
                }
                else
                {
                    modelComplete.append({
                        id: l.id,
                        name: l.name,
                        last: false
                    });
                }
            }

            if (modelComplete.count > 0)
                modelComplete.get(modelComplete.count-1).last = true;
        }
    }
}



