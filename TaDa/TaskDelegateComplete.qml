import QtQuick 2.12

Column {
    Row {
        CheckBoxPlus {
            y: 2
            checked: completed

            onClicked: {
                server.setTaskCompleted(id, checked);

                let i;

                for (i=0;i<modelIncomplete.model.count;++i)
                {
                    let item = modelIncomplete.model.get(i);

                    if (item.id > id)
                        break;
                }

                modelIncomplete.model.insert(i, {
                    id: id,
                    completed: false,
                    name: name,
                    reordering: false
                });
                modelComplete.remove(index);
            }
        }

        TextPlus {
            text: name
            font.family: "lucida grande"
            font.pixelSize: 10
            textColor: "#999"
            leftPadding: 8
            topPadding: 6

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
