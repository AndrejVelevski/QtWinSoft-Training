import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

GridLayout
{
    columns: 2

    MyLabel
    {
        text: "Username"
        Layout.alignment: Qt.AlignRight
    }

    MyTextEdit
    {
        Layout.fillWidth: true
    }

    MyLabel
    {
        text: "Address"
        Layout.alignment: Qt.AlignRight
    }

    MyTextEdit
    {
        Layout.fillWidth: true
        text: "127.0.0.1"
    }

    MyLabel
    {
        text: "Port"
        Layout.alignment: Qt.AlignRight
    }

    MyTextEdit
    {
        Layout.fillWidth: true
        text: "12345"
    }
}
