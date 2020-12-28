import QtQuick 2.9
import QtQuick.Controls 2.5

MyContainer
{
    property string text: ""
    width: parent.width
    color: Qt.rgba(0.7, 0.7, 0.7, 1)

    TextEdit
    {
        width: parent.width
        text: parent.text
        font.pointSize: 12
        padding: 8
    }
}


