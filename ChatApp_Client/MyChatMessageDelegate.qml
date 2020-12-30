import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

MyContainer {
    border.width: 0

    ColumnLayout {
        Component.onCompleted: {
            if (myMessage)
                anchors.right = parent.right;
        }

        RowLayout {
            Layout.alignment: myMessage ? Qt.AlignRight : Qt.AlignLeft

            MyLabel {
                Layout.alignment: myMessage ? Qt.AlignRight : Qt.AlignLeft
                padding: 0
                text: username
                fontbold: true
            }

            MyLabel {
                Layout.alignment: myMessage ? Qt.AlignRight : Qt.AlignLeft
                padding: 0
                text: dateTime
            }
        }

        MyLabel {
            id: lbl
            color: root.colorAccent
            text: message
            textWidth: {
                if (textWidth > 3*chatlistview.width/4)
                    textWidth = 3*chatlistview.width/4;
            }
            Layout.alignment: myMessage ? Qt.AlignRight : Qt.AlignLeft
        }
    }
}
