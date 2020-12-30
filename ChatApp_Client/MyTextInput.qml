import QtQuick 2.12
import QtQuick.Controls 2.12

MyContainer
{
    id: cont
    property alias text: textinput.text
    property alias textFocus: textinput.focus

    width: 100
    height: 40

    color: root.colorAccent

    Flickable {
        id: flick

        anchors.fill: parent
        contentWidth: textinput.paintedWidth
        contentHeight: textinput.paintedHeight
        clip: true

        function ensureVisible(r)
        {
            if (contentX >= r.x)
                contentX = r.x;
            else if (contentX+width <= r.x+r.width)
                contentX = r.x+r.width-width;
            if (contentY >= r.y)
                contentY = r.y;
            else if (contentY+height <= r.y+r.height)
                contentY = r.y+r.height-height;
        }

        TextEdit {
            id: textinput
            width: flick.width
            height: flick.height
            focus: true
            wrapMode: TextEdit.Wrap
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
            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

            Keys.forwardTo: [cont]
        }
    }
}


