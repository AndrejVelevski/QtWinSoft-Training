import QtQuick 2.12

Column {
    Row {
        CheckBoxPlus {
            y: 2
            checked: completed

            onClicked: {
                server.setTaskCompleted(id, checked);
                modelComplete.append({
                    id: id,
                    completed: true,
                    name: name
                });
                modelIncomplete.remove(index);
            }
        }

        TextPlus {
            text: name
            font.family: "lucida grande"
            font.pixelSize: 16
            leftPadding: 8
        }
    }

    Item {
        width: 1
        height: 8
    }
}
