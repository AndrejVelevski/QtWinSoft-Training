import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

RowLayout
{
    FontLoader
    {
        id: loader
        source: "qrc:/res/Brush Script MT.ttf"
    }

    MyLabel
    {
        text: "ChatApp"
        fontfamily: loader.name
        fontpointSize: 36
        padding: 0
    }

    Item
    {
        Layout.fillWidth: true
    }

    MyButton
    {
        width: 48
        height: 48

        Image
        {
            id: themeIcon
            property bool theme: true
            width: 32
            height: 32
            anchors.centerIn: parent
            source: "qrc:/res/sun.png"
        }

        onClicked:
        {
            root.colorBackground.r = 1 - root.colorBackground.r;
            root.colorBackground.g = 1 - root.colorBackground.g;
            root.colorBackground.b = 1 - root.colorBackground.b;

            root.colorAccent.r = 1 - root.colorAccent.r;
            root.colorAccent.g = 1 - root.colorAccent.g;
            root.colorAccent.b = 1 - root.colorAccent.b;

            root.colorTextBorder.r = 1 - root.colorTextBorder.r;
            root.colorTextBorder.g = 1 - root.colorTextBorder.g;
            root.colorTextBorder.b = 1 - root.colorTextBorder.b;

            if (themeIcon.theme)
            {
                themeIcon.source = "qrc:/res/moon.png";
                cover.color = Qt.rgba(0, 0, 0, 0.8);
            }
            else
            {
                themeIcon.source = "qrc:/res/sun.png";
                cover.color = Qt.rgba(1, 1, 1, 0.2);
            }
            themeIcon.theme = !themeIcon.theme;


        }
    }

    MyButton
    {
        width: 48
        height: 48

        text: "X"
        pointSize: 24

        Timer
        {
            id: timer
            interval: 500
            running: false
            repeat: false
            onTriggered:
            {
                status.visible = true;
            }
        }

        onClicked:
        {
            if (stack.depth > 1)
            {
                client.disconnectFromServer();
            }
            else
            {
                //close();
                Qt.quit();
            }
        }

        function delay(delayTime, cb)
        {
            let timer = Qt.createQmlObject("import QtQuick 2.9; Timer {}");
            timer.interval = delayTime;
            timer.repeat = false;
            timer.triggered.connect(cb);
            timer.start();
        }
    }
}
