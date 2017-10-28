import QtQuick 2.0

Item {
    id: rootBall
    width: childrenRect.width
    height:  childrenRect.height
    signal move()
    Image {
        id: ball
        source: "qrc:/Image/football.png"

    }
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            move()
        }
    }
}
