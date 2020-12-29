import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

GridLayout
{
    columns: 2

    property alias username: username.text
    property alias address: address.text
    property alias port: port.text

    MyLabel
    {
        text: "Username"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput
    {
        id: username
        objectName: "username"
        Layout.fillWidth: true
    }

    MyLabel
    {
        text: "Address"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput
    {
        id: address
        objectName: "address"
        Layout.fillWidth: true
        text: "127.0.0.1"
    }

    MyLabel
    {
        text: "Port"
        Layout.alignment: Qt.AlignRight
    }

    MyTextInput
    {
        id: port
        objectName: "port"
        Layout.fillWidth: true
        text: "12345"
    }
}
