import QtQuick 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    MyInputForm {
        id: form
    }

    MyButton {
        Layout.alignment: Qt.AlignHCenter
        text: "Connect"
        pointSize: 24

        onClicked: {
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

    Connections {
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
            stack.push(pageChat);
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
