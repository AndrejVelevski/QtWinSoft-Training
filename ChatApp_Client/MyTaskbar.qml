import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

RowLayout
{
    Label
    {
        text: "ChatApp"
        font.family: "Brush Script MT"
        font.pointSize: 36
    }

    Item
    {
        Layout.fillWidth: true
    }

    MyButton
    {
        width: 48
        height: 48
        z: 10

        Image
        {
           width: 32
           height: 32
           anchors.centerIn: parent
           source: "qrc:/res/sun.png"
        }
    }

    MyButton
    {
        id: buttonClose
        width: 48
        height: 48
        z: 10

        Label
        {
           anchors.centerIn: parent
           text: "X"
           font.pointSize: 24
        }

        MouseArea
        {
            anchors.fill: parent;
            cursorShape: Qt.PointingHandCursor;

            onClicked:
            {
                close();
            }
        }
    }
}
