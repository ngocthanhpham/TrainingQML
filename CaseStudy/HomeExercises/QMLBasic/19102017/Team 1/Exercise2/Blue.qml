import QtQuick 2.4

Rectangle {
    id: rectBlue
    width: 70; height: 70
    signal message(string msg)
    color: "blue"

    MouseArea {
        anchors.fill: parent
        onClicked: rectBlue.message("Red.qml")
    }
}

