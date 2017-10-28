import QtQuick 2.4


    Rectangle {
        id: rectRed
        signal message(string msg)

        width: 70; height: 70
        color: "red"

        MouseArea {
            anchors.fill: parent
            onClicked: rectRed.message("Blue.qml")
        }
    }

