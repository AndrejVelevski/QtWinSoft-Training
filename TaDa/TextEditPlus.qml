import QtQuick 2.12

Rectangle {
    width: 640
    height: 100
    border.width: 1
    radius: 3
    property alias text: text.text
    property alias font: text.font
    property alias padding: text.padding

    Flickable {
        id: flick
        anchors.fill: parent
        contentWidth: text.paintedWidth
        contentHeight: text.paintedHeight
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
            id: text
            width: flick.width
            height: flick.height
            padding: 5
            wrapMode: TextEdit.Wrap
            font.family: "arial"
            font.pixelSize: 14
            selectionColor: "#3390ff"
            selectByMouse: true
            onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
        }
    }
}
