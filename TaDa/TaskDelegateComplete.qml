import QtQuick 2.12

Column {
    Row {
        CheckBoxPlus {
            y: 2
            checked: completed

            onClicked: {
                server.setTaskCompleted(id, checked);

                modelIncomplete.append({
                    id: id,
                    completed: false,
                    name: name
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
        }
    }

    Item {
        width: 1
        height: 8
    }
}
