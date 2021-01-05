import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    width: childrenRect.width
    height: childrenRect.height

    function createNewTask(name) {
        name = name.trim();
        if (name.length > 0)
            server.createNewTask(root.listid, name);
    }

    Connections {
        target: server

        function onNewTaskCreated(id, name) {
            modelIncomplete.append({
                id: id,
                completed: false,
                name: name
            });
        }
    }

    Component.onCompleted: {
        server.requestTasks(root.listid);
    }

    TextPlus {
        id: listName
        text: ""
        font.family: "helvetica"
        font.pixelSize: 24
        font.bold: true
        bottomPadding: 5
    }

    TextPlus {
        id: listDescription
        text: ""
        font.family: "lucida grande"
        font.pixelSize: 12
        bottomPadding: 5
        textColor: "#333"
    }

    Item {
        width: 1
        height: 15
    }

    Column {
        Repeater {
            id: sadsa
            model: ListModel { id: modelIncomplete }
            delegate: TaskDelegateIncomplete { }

            clip: true
        }
    }

    Column {
        Item {
            width: 1
            height: 8
        }

        Column {
            id: c1
            visible: false

            Rectangle {
                width: 440
                height: childrenRect.height
                border.width: 1
                radius: 3

                TextInput {
                    id: textbox
                    width: parent.width
                    font.family: "arial"
                    font.pixelSize: 14
                    selectionColor: "#3390ff"
                    selectByMouse: true
                    padding: 2

                    onAccepted: {
                        createNewTask(text);
                        text = "";
                    }

                    MouseArea {
                        z: -1
                        anchors.fill: parent
                        cursorShape: Qt.IBeamCursor
                    }
                }
            }

            Item {
                width: 1
                height: 16
            }

            Row {
                Image {
                    source: "qrc:/res/create-task.png"

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor

                        onClicked: {
                            createNewTask(textbox.text);
                            textbox.text = "";
                        }
                    }
                }

                HyperlinkRed {
                    text: "Close"
                    leftPadding: 8
                    topPadding: 4

                    onClicked: {
                        c1.visible = false;
                        c2.visible = true;
                    }
                }
            }
        }

        Row {
            id: c2
            Item {
                width: 20
                height: 1
            }

            HyperlinkRed {
                text: "Add another item"

                onClicked: {
                    c1.visible = true;
                    c2.visible = false;
                }
            }

            TextPlus {
                text: "  or  "
                font.family: "lucida grande"
                font.pixelSize: 11
                textColor: "#999"
                visible: hlDelete.visible
            }

            HyperlinkRed {
                id: hlDelete
                text: "Delete this list"
                visible: modelIncomplete.count === 0

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
            height: 16
        }
    }

    Column {
        Repeater {
            model: ListModel { id: modelComplete }
            delegate: TaskDelegateComplete { }

            clip: true
        }
    }

    Connections {
        target: server

        function onGetTasks(list, tasks) {
            listName.text = list.name;
            listDescription.text = list.description;

            for (let t of tasks)
            {
                if (t.completed)
                {
                    modelComplete.append({
                        id: t.id,
                        completed: t.completed,
                        name: t.name
                    });
                }
                else
                {
                    modelIncomplete.append({
                        id: t.id,
                        completed: t.completed,
                        name: t.name
                    });
                }
            }
        }
    }
}
