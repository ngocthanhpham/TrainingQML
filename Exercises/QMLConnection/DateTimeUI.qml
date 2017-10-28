import QtQuick 2.0

Item {
    width: childrenRect.width
    height: childrenRect.height
    Column
    {
        Text {
            id: idTime
        }

//        Text {
//            id: idDate
//        }
    }
    Timer
    {
        interval: 500
        running: true
        repeat: true
        onTriggered: idTime.text = Date().toString()
    }
}
