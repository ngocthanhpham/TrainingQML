import QtQuick 2.6
import QtQuick.Window 2.2
import test.api 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }

    Loader
    {

        id: idLoader
        anchors.centerIn: parent
        source: "qrc:/Square.qml"
    }

    Connections
    {
        target: idLoader.item
        onMouseClicked:
        {
            console.log("mouse clicked: ", idLoader.item.type)
            if(idLoader.item.type === ShapeUtil.square)
            {
                idLoader.source = "Circle.qml"
            }else
            {
                idLoader.source = "Square.qml"
            }
        }

    }
}
