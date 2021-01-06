import QtQuick 2.12
import QtQuick.Controls 2.12

ScrollView {
    id: scrollTasksPage
    signal reorder(bool value)

    onReorder: {
        for (let i=0;i<content.modelIncomplete.model.count;++i)
        {
            content.modelIncomplete.model.get(i).reordering = value;
        }

        content.newTask.visible = !value;
        content.completedTasks.visible = !value;
    }

    Row {
        Item {
            width: 150
            height: 1
        }

        Column {
            width: childrenRect.width
            height: childrenRect.height

            Item {
                width: 1
                height: 25
            }

            TasksHeader { }

            Item {
                width: 1
                height: 30
            }

            TasksContent { id: content }

            Item {
                width: 1
                height: 25
            }
        }
    }
}
