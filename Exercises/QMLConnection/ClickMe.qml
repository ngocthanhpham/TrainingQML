import QtQuick 2.0

Item {
    signal mouseClick()
    property alias mouseEvent: mouseArea
    width: 100
    height: 30
    Rectangle{
        anchors.fill: parent
        Text {
            id: name
            text: qsTr("Click Me")
        }
        MouseArea
        {
            id: mouseArea
            anchors.fill: parent
            onClicked:
            {
                console.log("click me")
                mouseClick()
            }
        }
    }
}
