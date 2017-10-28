import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//    property variant myModel
//    MainForm {
//        anchors.fill: parent
////        mouseArea.onClicked: {
////            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
////        }


//    }

    Rectangle
    {
        width: 36
        height: 36
        color: "red"
        MouseArea
        {
            anchors.fill: parent
            onClicked: {
                console.log(myModel[2])
            }
        }
    }

//    ListView
//    {
//        anchors.fill: parent
//        model: myModel
//        delegate: Item
//        {
//            width: childrenRect.width
//            height: childrenRect.height
//            Row
//            {
//                spacing: 5
//                Text
//                {
//                    text: modelData
//                    color: "black"
//                }
//                Text {
//                    id: idIndex
//                    text: index
//                }
//                Rectangle
//                {
//                    width: 36
//                    height: 36
//                    color: "blue"
//                    MouseArea
//                    {
//                        anchors.fill: parent
//                        onClicked: {
//                            console.log(myModel[2])
//                        }
//                    }
//                }
//            }
////            Rectangle
////            {
////                width: 100
////                height: 100
////                color: "red"
////            }
//        }
//    }
}
