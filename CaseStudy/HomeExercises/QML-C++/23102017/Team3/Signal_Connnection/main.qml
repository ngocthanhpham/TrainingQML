import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    signal testsignal(string text)
    Rectangle
    {
        width: 50
        height: 50
        anchors.centerIn: parent
        color: "red"

        MouseArea
        {
            anchors.fill:parent
            onClicked:
            {
                testsignal("thanh cong")

            }
        }
    }


    Qconnection{id:idconnection}

    Connections
    {
        target: idconnection
        onTestconnection:
        msgconnection.connection1("thanh cong roi");
    }


}
