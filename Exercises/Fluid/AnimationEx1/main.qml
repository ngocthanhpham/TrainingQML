import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property bool running: false
    Image
    {
        source: "qrc:/Image/ford-2705402_1280.jpg"
        Image {
            id: ballImage
            x: 40
            y: (parent.height - height)/2
            source: "qrc:/Image/soccer_ball.png"
            NumberAnimation on x {
                to: root.width - ballImage.width - 40
                duration: 2000
                running: root.running
            }
            RotationAnimation on rotation
            {
                to: 360
                duration: 2000
                running: root.running
            }
        }
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: root.running = true
    }
}
