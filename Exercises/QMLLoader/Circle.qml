import QtQuick 2.0

Shape {
    width: childrenRect.width
    height: childrenRect.height
    type: shape.circle
    signal mouseClicked()
    Rectangle
    {
        width: 100
        height: width
        radius: 50
        color: shapeColor
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: mouseClicked()
    }
}
