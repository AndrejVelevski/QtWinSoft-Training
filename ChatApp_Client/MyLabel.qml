import QtQuick 2.9
import QtQuick.Controls 2.5

MyContainer
{
    property string text: ""
    property int padding: 8
    property int pointSize: 12
    border.width: 0
    color: Qt.rgba(0, 0, 0, 0)

    Label
    {
        text: parent.text
        font.pointSize: parent.pointSize
        padding: parent.padding
    }
}


