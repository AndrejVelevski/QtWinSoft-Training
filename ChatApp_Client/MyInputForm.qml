import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

GridLayout {
    columns: 2

    property alias username: username.text
    property alias address: address.text
    property alias port: port.text

    MyLabel {
        text: "Username"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput {
        id: username
        objectName: "username"
        Layout.fillWidth: true

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
            {
                event.accepted = true;
            }
        }
    }

    MyLabel {
        text: "Address"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput {
        id: address
        objectName: "address"
        Layout.fillWidth: true
        text: "127.0.0.1"

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
            {
                event.accepted = true;
            }
        }
    }

    MyLabel {
        text: "Port"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput {
        id: port
        objectName: "port"
        Layout.fillWidth: true
        text: "12345"

        Keys.onPressed: {
            if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return)
            {
                event.accepted = true;
            }
        }
    }
}
