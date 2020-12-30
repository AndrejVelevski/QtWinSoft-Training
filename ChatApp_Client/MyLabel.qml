import QtQuick 2.12
import QtQuick.Controls 2.12


MyContainer {
    property alias text: textedit.text
    property alias padding: textedit.padding
    property alias leftPadding: textedit.leftPadding
    property alias rightPadding: textedit.rightPadding
    property alias topPadding: textedit.topPadding
    property alias bottomPadding: textedit.bottomPadding
    property alias fontfamily: textedit.font.family
    property alias fontpointSize: textedit.font.pointSize
    property alias fontbold: textedit.font.bold
    property alias textColor: textedit.color
    property alias textWidth: textedit.width
    property alias textHeight: textedit.height
    border.width: 0

    TextEdit {
        id: textedit
        font.pointSize: 12
        padding: 8
        readOnly: true
        selectByMouse: true
        color: root.colorTextBorder
        wrapMode: TextEdit.Wrap
        selectionColor: {
            let r = 1 - color.r;
            let g = 1 - color.g;
            let b = 1 - color.b;

            return Qt.rgba(r, g, b, 0.5);
        }
    }
}


