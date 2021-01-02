import QtQuick 2.12

Row {

    HyperlinkBlue {
        text: name
    }

    TextPlus {
        y: -4
        text: ", "
        textColor: "#333"
        leftPadding: 1
        visible: !last
    }
}
