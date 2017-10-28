import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }

    Rectangle
    {
        id: idRec
        x: 50
        y: 50
        width:  50
        height: 50
//        color: "red"
//        radius: 50
        border.color: "blue"
        border.width: 1
        gradient: Gradient
        {
            GradientStop {position: 0.0; color: "aqua"}
            GradientStop {position: 1.0; color: "yellow"}
        }
    }

    Rectangle{
        id: lgImage
        width: childrenRect.width
        height:  childrenRect.height
        border.color: "blue"

        anchors
        {
            left: idRec.right
            top: idRec.top
            leftMargin: 50
        }

        Image {
            source: "qrc:/Image/Image/logo-lg-horizontal-full-color-v2.png"
        }
    }

    SearchBox
    {
        id: searchBox
        height: 100
        anchors{
            left: lgImage.right
            top: lgImage.top
            leftMargin: 10
        }
    }

}
