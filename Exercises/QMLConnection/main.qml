import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480

    property bool hello: false


    title: qsTr("Hello World")

    ClickMe
    {
        id: idClickMe
        anchors.centerIn: parent
    }

//    Row{
//        anchors.centerIn: parent
//        spacing: 5
//        Hello
//        {
//            id: idGreeting1
////            anchors.centerIn: parent
//            visible: false
//            Connections
//            {
//                target: idClickMe
//                onMouseClick:
//                {
//                    idGreeting1.visible = true
//                    idGreeting1.greeting = "Hello"
//                }
//            }

//        }

//        Hello
//        {
//            id: idGreeting2
////            anchors.centerIn: parent
//            visible: false
//            Connections
//            {
//                target: idClickMe
//                onMouseClick:
//                {
//                    idGreeting2.visible = true
//                    idGreeting2.greeting = "Hi"
//                }
//            }
//        }
//    }

    Connections
    {
        target: idClickMe.mouseEvent
        onClicked:
        {
            hello = true
        }
    }

    DateTimeUI
    {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
    }
}
