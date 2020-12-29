import QtQuick 2.9
import QtQuick.Layouts 1.3

MyContainer
{
    border.width: 0

    RowLayout
    {
        Item
        {
            width: 5
        }

        MyContainer
        {
            width: 10
            height: 10
            radius: 5
            border.width: 0
            color:
            {
                let r = 1 - root.colorBackground.r;
                let g = 1 - root.colorBackground.g;
                let b = 1 - root.colorBackground.b;

                return Qt.rgba(r, g, b, 1);
            }
        }

        MyLabel
        {
            text: username
        }
    }
}
