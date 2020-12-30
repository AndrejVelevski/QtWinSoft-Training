import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

SplitView {
    orientation: Qt.Horizontal

    Rectangle {
        SplitView.preferredWidth: 150
        color: root.colorInvisible

        MyContainer {
            anchors.fill: parent
            anchors.margins: 8

            ListView {
                id: userslistview
                anchors.fill: parent

                clip: true
                model: ListModel { id: userModel }
                delegate: MyUserDelegate { }

                Connections {
                    target: client

                    function onGetUsers(users) {
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

    }

    Rectangle {
        SplitView.fillWidth: true
        color: root.colorInvisible

        SplitView {
            anchors.fill: parent
            orientation: Qt.Vertical

            Rectangle {
                SplitView.fillHeight: true
                SplitView.minimumHeight: 90
                color: root.colorInvisible

                MyContainer {
                    anchors.fill: parent
                    border.width: 0

                    ListView {
                        id: chatlistview
                        anchors.fill: parent
                        clip: true
                        model: ListModel { id: chatModel }
                        delegate: MyChatMessageDelegate { width: chatlistview.width }
                    }
                }

                onWidthChanged: {
                    chatModel.modelReset();
                    //chatlistview.positionViewAtEnd();
                }

                onHeightChanged: {
                    chatlistview.positionViewAtEnd();
                }
            }

            Rectangle {
                color: root.colorInvisible
                SplitView.minimumHeight: 100

                MyTextInput {
                    anchors.fill: parent

                    Keys.onPressed: {
                        if (!(event.modifiers & Qt.ShiftModifier) && (event.key === Qt.Key_Enter || event.key === Qt.Key_Return))
                        {
                            client.sendMessage(text);
                            text = "";
                            event.accepted = true;
                        }
                    }

                    Connections {
                        target: client

                        function onChatMessage(dateTime, username, message) {
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
