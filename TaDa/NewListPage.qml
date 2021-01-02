import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 0

    Item { height: 25 }

    NewListHeader { }

    Item { height: 30 }

    NewListContent { Layout.fillWidth: true }

    Item { Layout.fillHeight: true }
}
