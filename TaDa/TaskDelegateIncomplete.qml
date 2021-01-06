import QtQuick 2.12

MouseArea {
    id: dragArea

    property bool held: false

    width: content.width
    height: content.height

    drag.target: held ? content : undefined
    drag.axis: Drag.YAxis

    onPressed: {
        if (reordering)
            held = true;
    }

    onReleased: held = false

    cursorShape: {
        if (reordering)
            return Qt.SizeAllCursor;
    }

    Column {
        id: content

        Drag.active: dragArea.held
        Drag.source: dragArea
        Drag.hotSpot.x: width / 2
        Drag.hotSpot.y: height / 2

        states: State {
            when: dragArea.held

            AnchorChanges {
                target: content
                anchors { horizontalCenter: undefined; verticalCenter: undefined }
            }
        }

        Row {
            Rectangle {
                visible: reordering
                width: 50
                height: 16

                Image {
                    source: "qrc:/res/drag.png"
                    anchors.centerIn: parent
                }
            }

            CheckBoxPlus {
                y: 2
                checked: completed

                onClicked: {
                    server.setTaskCompleted(id, checked);

                    let i;

                    for (i=0;i<modelComplete.count;++i)
                    {
                        let item = modelComplete.get(i);

                        if (item.id > id)
                            break;
                    }

                    modelComplete.insert(i, {
                        id: id,
                        completed: true,
                        name: name
                    });
                    modelIncomplete.model.remove(index);
                }
            }

            TextPlus {
                text: name
                font.family: "lucida grande"
                font.pixelSize: 16
                leftPadding: 8

                textWidth: {
                    if (textWidth > root.width-300)
                        return root.width - 300;
                }
            }
        }

        Item {
            width: 1
            height: 8
        }
    }

    DropArea {
        anchors.fill: parent

        onEntered: {
            let from = dragArea.DelegateModel.itemsIndex;
            let to = drag.source.DelegateModel.itemsIndex;

            if (Math.abs(from-to) === 1)
            {
                modelIncomplete.model.move(from, to, 1)

                let fromItem = modelIncomplete.model.get(from);
                let toItem = modelIncomplete.model.get(to);

                server.swapTasks(fromItem.id, toItem.id);

                let tmp = fromItem.id;
                fromItem.id = toItem.id;
                toItem.id = tmp;
            }
        }
    }
}


