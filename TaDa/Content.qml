import QtQuick 2.12
import QtQuick.Controls 2.12

ListView {
    id: list
    model: ListModel { id: model }
    delegate: ListDelegate { }
    clip: true

    ScrollBar.vertical: ScrollBar { }

    Component.onCompleted: {
        for (let i=0;i<100;++i)
        {
            let n = Math.floor(21*Math.random());
            let s = Math.random()<0.5?true:false;

            model.append({
                name: "Item " + i,
                numItems: n,
                sharing: s
            });
        }
    }
}
