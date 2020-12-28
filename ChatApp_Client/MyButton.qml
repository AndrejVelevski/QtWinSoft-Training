import QtQuick 2.9

MyContainer
{
    property string text: ""
    property int padding: 8
    property int pointSize: 12
    color: Qt.rgba(0, 0, 0, 0)

    MouseArea
    {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor;

        onEntered:
        {
            parent.color = Qt.rgba(0.7, 0.7, 0.7, 1);
        }
        onExited:
        {
            parent.color = Qt.rgba(0, 0, 0, 0);
        }
    }

    MyLabel
    {
        text: parent.text
        padding: parent.padding
        pointSize: parent.pointSize
        anchors.centerIn: parent
    }
}
