import QtQuick 2.12

Row {
    width: childrenRect.width
    height: childrenRect.height

    HyperlinkBlue {
        text: name

        textWidth: {
            if (textWidth > root.width-300)
                return root.width-300
        }

        onClicked:  {
            root.listid = id;
            stack.replace(tasksPage);
        }
    }

    TextPlus {
        y: -4
        text: ", "
        textColor: "#333"
        leftPadding: 1
        visible: !last
    }
}
