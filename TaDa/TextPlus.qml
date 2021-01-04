import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: textbox
    width: childrenRect.width
    height: childrenRect.height
    color: backgroundColor
    signal clicked()

    property alias text: text.text
    property alias font: text.font
    property color textColor: "black"
    property color backgroundColor: "transparent"
    property color textHoverColor: textColor
    property color backgroundHoverColor: backgroundColor
    property alias cursorShape: area.cursorShape
    property bool clickable: false
    property alias textFormat: text.textFormat
    property alias padding: text.padding
    property alias leftPadding: text.leftPadding
    property alias rightPadding: text.rightPadding
    property alias topPadding: text.topPadding
    property alias bottomPadding: text.bottomPadding
    property alias textWidth: text.width
    property alias textHeight: text.height

    TextEdit {
        id: text
        color: textColor
        readOnly: true
        selectByMouse: true
        selectionColor: "#3390ff"
        wrapMode: TextEdit.Wrap

        MouseArea {
            id: area
            z: -(!clickable)
            anchors.fill: parent
            cursorShape: (clickable?Qt.PointingHandCursor:Qt.IBeamCursor)
            hoverEnabled: true

            onEntered: {
                text.color = textHoverColor;
                textbox.color = backgroundHoverColor;
            }
            onExited: {
                text.color = textColor;
                textbox.color = backgroundColor;
            }
            onClicked: {
                textbox.clicked();
            }
        }
    }
}
