import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    spacing: 0

    Item { height: 25 }

    HomeHeader { }

    Item { height: 30 }

    Splitter { }

    Item { height: 10 }

    HomeContent {
        Layout.fillWidth: true
        Layout.fillHeight: true
    }

    Item { height: 25 }
}
