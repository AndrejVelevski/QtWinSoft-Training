import QtQuick 2.12
import QtQuick.Controls 2.12

ScrollView {

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

            HomeHeader { }

            Item {
                width: 1
                height: 30
            }

            Splitter { }

            Item {
                width: 1
                height: 10
            }

            HomeContent { }

            Item {
                width: 1
                height: 25
            }
        }
    }
}
