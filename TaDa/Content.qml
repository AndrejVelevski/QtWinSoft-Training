import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: list
    model: ListModel { id: model }
    delegate: ListDelegate { }
    clip: true

    ScrollBar.vertical: ScrollBar { }

    Component.onCompleted: {
        server.requestLists();
    }

    Connections {
        target: server

        function onGetLists(list) {

            for (let l of list)
            {
                console.log(l.id + " " + l.name + " " + l.description + " " + l.numTasks)
                model.append({
                    id: l.id,
                    name: l.name,
                    description: l.description,
                    numTasks: l.numTasks,
                    sharing: false
                });
            }
        }
    }
}
