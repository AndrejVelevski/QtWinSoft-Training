import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window
{
    id: root
    width: 640
    height: 480
    visible: true
    flags: Qt.Window | Qt.CustomizeWindowHint
    //flags: Qt.FramelessWindowHint
    title: qsTr("ChatApp")
    minimumWidth: 274
    minimumHeight: 336
    color: Qt.rgba(0.9, 0.9, 0.9, 9)

    /*MouseArea
    {
        property variant clickPos: "0, 0";

        width: 4
        height: parent.height

        anchors.right: parent.right;

        cursorShape: Qt.SizeHorCursor

        onPressed:
        {
            clickPos = Qt.point(mouse.x, mouse.y);
        }

        onMouseXChanged:
        {
            let delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y);
            root.setWidth(parent.width + delta.x);
            if (root.width < root.minimumWidth)
                root.setWidth(root.minimumWidth);
        }
    }*/

    ColumnLayout
    {
        width: root.width - 16
        height: root.height - 16
        anchors.centerIn: parent

        MyTaskbar
        {
            MouseArea
            {
                anchors.fill: parent
                property variant clickPos: "0, 0";

                onPressed:
                {
                    clickPos = Qt.point(mouse.x,mouse.y);
                }

                onPositionChanged:
                {
                    let delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y);
                    root.x += delta.x;
                    root.y += delta.y;
                }
            }
        }

        MyInputForm
        {

        }

        Item
        {
            Layout.fillHeight: true
        }

        MyButton
        {
            Layout.alignment: Qt.AlignHCenter
            text: "Connect"
            pointSize: 24
        }

        Item
        {
            Layout.fillHeight: true
        }

        MyLabel
        {
            Layout.fillWidth: true
            border.width: 2
            padding: 16
            text: "Status:"
        }
    }
}
