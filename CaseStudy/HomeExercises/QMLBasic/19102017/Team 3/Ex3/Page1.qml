import QtQuick 2.0
import QtQuick.Controls 2.0

Page {
    width: 640
    height: 420
    Text {
        id: name
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 100
        text: qsTr("First page")
    }

    BaseRectange {
        width: 300
        height: 50
        color: "brown"
        border.color: "gray"
        border.width: 1
        anchors.centerIn: parent

        Row {
            id: row
            anchors.centerIn: parent
            spacing: 5

            Repeater {
                model: 5
                BaseRectange {
                    width: 40
                    height: 40
                    color: "yellow"
                    opacity: (index + 1) * 0.2
                }
            }
        }
    }
}
