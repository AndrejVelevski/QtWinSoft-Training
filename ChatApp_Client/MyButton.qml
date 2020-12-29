import QtQuick 2.9

MyContainer
{
    property string text: ""
    property int padding: 8
    property int pointSize: 12
    property alias textWidth: text.width
    property alias textHeight: text.height
    signal clicked()
    width: text.width
    height: text.height

    MouseArea
    {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor;

        onEntered:
        {
            parent.color = root.colorAccent;
        }
        onExited:
        {
            parent.color = Qt.rgba(0, 0, 0, 0);
        }
        onClicked:
        {
            parent.clicked();
        }
    }

    Text
    {
        id: text
        text: parent.text
        padding: parent.padding
        font.pointSize: parent.pointSize
        anchors.centerIn: parent
        color: root.colorTextBorder
    }
}
