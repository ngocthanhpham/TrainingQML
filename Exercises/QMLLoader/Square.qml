import QtQuick 2.0

Shape {

    width: 100
    height: width
    type: shape.square


    signal mouseClicked()

    Rectangle
    {
        anchors.fill: parent
        color: shapeColor
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked:
        {
            mouseClicked()
        }
    }
}

