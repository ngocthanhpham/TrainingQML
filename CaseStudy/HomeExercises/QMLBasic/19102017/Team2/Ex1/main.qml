import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Exercise 1 - 19/10/2017")


    Item
    {
        id: root
        property real nOpacity: 1.0

        CusRec
        {
            id: idBackground
            width: 400
            height: 60

            color: "yellow"
            border.color: "black"
            border.width: 1

            LayoutMirroring.enabled: true
            LayoutMirroring.childrenInherit: true

            Row
            {
                spacing: 5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: idBackground.left
                padding: 5

                Repeater
                {
                    model: 5
                    delegate: CusRec
                    {
                        opacity: root.nOpacity - 0.15 * (/*4 - */index)

                        Text
                        {
                            anchors.centerIn: parent
                            text: index + 1
                            font.family: "Time New Roman"
                            font.pixelSize: 15
                        }
                    }
                }
            }
        }
    }
}
