import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Window
{
    id: root
    width: 640
    height: 480
    visible: true
    flags: Qt.Window
    title: qsTr("ChatApp")
    minimumWidth: 274
    minimumHeight: 336
    property color colorBackground: Qt.rgba(0.9, 0.9, 0.9, 1)
    property color colorAccent: Qt.rgba(0.7, 0.7, 0.7, 0.5)
    property color colorTextBorder: Qt.rgba(0, 0, 0, 1)
    property string username: "Default"

    color: colorBackground

    Image
    {
        width: parent.width
        height: parent.height
        fillMode: Image.Tile
        source: "qrc:/res/nebula.jpg"

        Rectangle
        {
            id: cover
            anchors.fill: parent
            color: Qt.rgba(1, 1, 1, 0.2)
        }

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 8

            MyTaskbar
            {
                Layout.fillHeight: true
            }

            StackView
            {
                id: stack
                initialItem: homePage
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            MyLabel
            {
                id: status
                objectName: "status"
                border.width: 2
                padding: 16
                text: ""
                width: 0
                color: root.colorAccent
                Layout.fillWidth: true
            }
        }
    }

    Component
    {
        id: homePage

        ColumnLayout
        {
            MyInputForm
            {
                id: form
            }

            MyButton
            {
                Layout.alignment: Qt.AlignHCenter
                text: "Connect"
                pointSize: 24

                onClicked:
                {
                    if (form.username.length === 0)
                    {
                        status.text = "Username can't be empty";
                        status.textColor = "red";
                        return;
                    }
                    else if (form.username.length > 20)
                    {
                        status.text = "Username is too big, maximum characters are 20";
                        status.textColor = "red";
                        return;
                    }
                    else if (form.username.indexOf(' ') >=0)
                    {
                        status.text = "Username can't contain whitespace characters";
                        status.textColor = "red";
                        return;
                    }

                    root.username = form.username;

                    client.connectToServer(form.address, form.port);
                }
            }

            Connections
            {
                target: client

                function onConnectionSuccess()
                {
                    status.textColor = "green";
                    status.text = "Connected";
                    client.tryLogIn(form.username);
                }

                function onLogInSuccess()
                {
                    status.visible = false;
                    status.textColor = "green";
                    status.text = "Logged in";
                    stack.push(chatPage);
                }

                function onErrorMessage(error)
                {
                    if (stack.depth > 1)
                        stack.pop();
                    status.visible = true;
                    status.text = error;
                    status.textColor = "red";
                }

                function onLogOut()
                {
                    stack.pop();
                    status.visible = true;
                    status.textColor = "green";
                    status.text = "Logged out";
                }
            }
        }
    }

    Component
    {
        id: chatPage

        RowLayout
        {
            MyContainer
            {
                width: 150
                Layout.fillHeight: true

                ListView
                {
                    id: userslistview
                    anchors.fill: parent

                    clip: true
                    model: ListModel
                    {
                        id: userModel
                    }
                    delegate: MyUserDelegate
                    {

                    }

                    Connections
                    {
                        target: client

                        function onGetUsers(users)
                        {
                            userModel.clear();

                            for (let u of users)
                            {
                                userModel.append({
                                    username: u
                                });
                            }

                            userslistview.positionViewAtEnd();
                        }
                    }
                }
            }

            ColumnLayout
            {
                MyContainer
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    border.width: 0

                    ListView
                    {
                        id: chatlistview
                        anchors.fill: parent
                        clip: true

                        model: ListModel
                        {
                            id: chatModel;
                        }

                        delegate: MyChatMessageDelegate
                        {
                            width: chatlistview.width
                        }

                        onWidthChanged:
                        {
                            chatModel.modelReset();
                            //chatlistview.positionViewAtEnd();
                        }
                    }
                }

                MyTextInput
                {
                    Layout.fillWidth: true

                    onAccepted:
                    {
                        client.sendMessage(text);
                        text = ""
                    }

                    Connections
                    {
                        target: client

                        function onChatMessage(dateTime, username, message)
                        {
                            chatModel.append({
                                username: username,
                                dateTime: dateTime,
                                message: message,
                                myMessage: username === root.username
                            });

                            chatlistview.positionViewAtEnd();
                        }
                    }
                }
            }
        }
    }
}
