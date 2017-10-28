import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Exercises 2 : 19-10-2017")

    Red {
        id: myRect
        width: 100
        height: 100
        anchors.centerIn: parent

        Loader
        {
            id: idLoader
        }

        MouseArea
        {
            id: mouseArea
            anchors.fill: parent
            onClicked:
            {
                myRect.state == 'red' ? myRect.state = "blue" : myRect.state = 'red';
                idLoader.source =  myRect.state == 'red' ? "qrc:/Blue.qml" : "qrc:/Red.qml"
            }
        }

        states: State
        {
            name: "red"
            PropertyChanges
            {
                target: myRect
            }
        }
    }
}
