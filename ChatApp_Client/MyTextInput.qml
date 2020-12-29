import QtQuick 2.9
import QtQuick.Controls 2.5

MyContainer
{
    property alias text: textedit.text
    width: parent.width
    color: root.colorAccent
    signal accepted()

    TextInput
    {
        id: textedit
        width: parent.width
        font.pointSize: 12
        padding: 8
        selectByMouse: true
        color: root.colorTextBorder
        selectionColor: {
            let r = 1 - color.r;
            let g = 1 - color.g;
            let b = 1 - color.b;

            return Qt.rgba(r, g, b, 0.5);
        }
        clip: true

        onAccepted:
        {
            parent.accepted();
        }
    }
}


