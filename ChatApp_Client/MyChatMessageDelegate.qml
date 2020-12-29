import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

MyContainer
{
    border.width: 0

    ColumnLayout
    {
        Component.onCompleted:
        {
            if (myMessage)
                anchors.right = parent.right;
        }

        RowLayout
        {
            Layout.alignment:
            {
                myMessage ? Qt.AlignRight : Qt.AlignLeft;
            }

            MyLabel
            {
                Layout.alignment:
                {
                    myMessage ? Qt.AlignRight : Qt.AlignLeft;
                }
                padding: 0
                text: username
                fontbold: true
            }

            MyLabel
            {
                Layout.alignment:
                {
                    myMessage ? Qt.AlignRight : Qt.AlignLeft;
                }
                padding: 0
                text: dateTime
            }
        }

        MyLabel
        {
            id: lbl
            color: root.colorAccent
            text: message
            textWidth: {
                if (textWidth > chatlistview.width)
                    textWidth = chatlistview.width;
            }

            Layout.alignment:
            {
                myMessage ? Qt.AlignRight : Qt.AlignLeft;
            }
        }
    }
}
