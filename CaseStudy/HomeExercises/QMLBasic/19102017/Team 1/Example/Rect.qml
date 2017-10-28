import QtQuick 2.4

Item {
    id: root
    width: 50
    height: 50
     property alias text: label.text
     property alias color: rect.color

        Rectangle {
            id: rect
            width: 50; height: 50
            anchors.fill: parent
            anchors.margins: 2
            color: "red"
            radius: 5

            Text {
                id: label
                text: "1"
                anchors.centerIn: parent
            }
        }

}
