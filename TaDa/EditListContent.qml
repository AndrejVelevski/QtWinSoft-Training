import QtQuick 2.12

Column {
    width: childrenRect.width
    height: childrenRect.height

    function acceptChanges() {

        let tasks = [];

        for (let i=0;i<modelTasks.count;++i)
        {
            let t = modelTasks.get(i);

            tasks.push({
                id: t.id,
                name: t.name.trim(),
                shouldDelete: t.shouldDelete
            });
        }

        server.editList(root.listid, title.text.trim(), description.text.trim(), tasks);
    }

    Connections {
        target: server

        function onListEdited() {
            stack.replace(tasksPage);
        }
    }

    Component.onCompleted: {
        server.requestTasks(root.listid);
    }

    TextPlus {
        text: "Edit this list"
        font.family: "helvetica"
        font.pixelSize: 24
        font.bold: true
    }

    Rectangle {
        width: root.width - 300
        height: 1
        color: "black"
    }

    Item {
        width: 1
        height: 5
    }

    Row {
        HyperlinkRed {
            text: "Cancel"

            onClicked: {
                stack.replace(tasksPage)
            }
        }

        TextPlus {
            text: "  |  "
            font.family: "lucida grande"
            font.pixelSize: 10
            textColor: "#666"
        }

        HyperlinkRed {
            text: "Delete this list"

            onClicked: {
                server.deleteList(root.listid);
            }

            Connections {
                target: server

                function onListDeleted() {
                    stack.replace(homePage);
                }
            }
        }
    }

    Item {
        width: 1
        height: 20
    }

    TextPlus {
        text: "TITLE"
        font.family: "lucida grande"
        font.pixelSize: 10
        textColor: "#630"
        bottomPadding: 2
    }

    TextInputPlus {
        id: title
        font.pixelSize: 20
        font.bold: true

        onAccepted: acceptChanges()
    }

    Item {
        width: 1
        height: 15
    }

    TextPlus {
        text: "ITEMS"
        font.family: "lucida grande"
        font.pixelSize: 10
        textColor: "#630"
        bottomPadding: 2
        visible: tasks.visible
    }

    Column {
        id: tasks
        visible: modelTasks.count > 0
        Repeater {
            model: ListModel { id: modelTasks }
            delegate: TaskEditDelegate { }

            clip: true
        }
    }

    TextPlus {
        text: "DESCRIPTION/NOTES (optional)"
        font.family: "lucida grande"
        font.pixelSize: 10
        textColor: "#630"
        bottomPadding: 2
    }

    TextEditPlus {
        id: description
    }

    Item {
        width: 1
        height: 20
    }

    Rectangle {
        width: root.width - 300
        height: childrenRect.height
        color: "#efefef"

        Row {
            anchors.left: parent.left
            anchors.top: parent.top
            padding: 4

            ButtonPlus {
                text: "Save this list"

                onClicked: acceptChanges()
            }

            TextPlus {
                text: "  or  "
                font.family: "lucida grande"
                font.pixelSize: 11
                textColor: "#666"
                topPadding: 7
            }

            HyperlinkRed {
                text: "Cancel"
                topPadding: 6

                onClicked: {
                    stack.replace(tasksPage)
                }
            }
        }
    }

    Connections {
        target: server

        function onGetTasks(list, tasks) {
            title.text = list.name;
            description.text = list.description;

            for (let t of tasks)
            {
                if (!t.completed)
                {
                    modelTasks.append({
                        id: t.id,
                        name: t.name,
                        shouldDelete: false
                    });
                }
            }
        }
    }
}
