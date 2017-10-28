import QtQuick 2.0

Item {
    width: 200
    height: 100
    visible: true
    property string greeting
    Rectangle
    {
        anchors.fill: parent
        border.color: "red"
        Text {
            id: idGreeting
            anchors.centerIn: parent
            text: greeting
        }
    }
    MouseArea
    {
        anchors.fill: parent
    }
}
