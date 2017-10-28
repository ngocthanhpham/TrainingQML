import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQml.Models 2.2
ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle
    {
        width: 300
        height: 80
        color: "yellow"
        border.color: "black"
       // anchors.centerIn: parent

        LayoutMirroring.enabled: true  //bi anh huong dau tien
       // LayoutMirroring.childrenInherit: true
        anchors.left: parent.left

        ListView{
            anchors.fill: parent
            anchors.margins: 20
            clip:true
            model:5
            delegate: idcomponent
            orientation: ListView.Horizontal
            spacing : 5
        }
        Component{
            id:idcomponent
            Rectangle{
                color: "red"
                width: 40
                height: 40
               // ddw : 40
               // ddh : 40

                Text {
                    anchors.centerIn: parent
                    id: idtext
                    text: index +1
                }
                opacity: 1-0.2*index

            }

        }

    }

}
