import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        color: "antiquewhite"
        width: childrenRect.width
        height: childrenRect.height

        Column {
            Repeater {
                id: list
                clip: true

                model: ListModel {
                    id: model

                    ListElement {
                        name: "Bill Smith"
                        number: "555 3264"
                    }
                    ListElement {
                        name: "John Brown"
                        number: "555 8426"
                    }
                    ListElement {
                        name: "Sam Wise"
                        number: "555 0473"
                    }
                }
                delegate: Text {
                    text: name + ": " + number
                }
            }
        }
    }
}
