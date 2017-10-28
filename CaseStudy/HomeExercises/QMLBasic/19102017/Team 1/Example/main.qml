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

//    Rectangle {
//        id: rect
//        x: 10; y: 10; z:1000
//        width: 100; height: 100
//        //color: "red"
//        radius: 50
//        border.color: "blue"
//        border.width: 1
//        gradient: Gradient {
//            GradientStop {
//                position: 0.00;
//                color: "aqua";
//            }
//            GradientStop {
//                position: 1.00;
//                color: "yellow"
//            }
//        }
//    }

//    Rectangle {
//        id: img
//        anchors {
//            left: rect.right
//            top: rect. top
//            leftMargin: 50
//        }

//        width: childrenRect.width
//        height: childrenRect.height
//        border.color: "black"

//        Image {
//            source: "qrc:/Images/D:/Download/logo-lg-horizontal-full-color-v2.png"
//        }
//    }

//    Item {
//        id: root
//        x: 10; y: 10; z:1000
//        width: 500; height: 500
//        LayoutMirroring.enabled: true
//        LayoutMirroring.childrenInherit: true
//        anchors.left: parent.left

//        Column {
//            id: column
//            spacing: 3

//            Rectangle {
//                id: rect1
//                width: 200; height: 50
//                border.color: "black"
//                color: "red"
//                radius: 5

//                Text {
//                    id: text1
//                    text: "Books"
//                    anchors.centerIn: parent
//                }
//            }

//            Rectangle {
//                id: rect2
//                width: 200; height: 50
//                border.color: "black"
//                color: "yellow"

//                radius: 5

//                Text {
//                    id: text2
//                    text: "Music"
//                    anchors.centerIn: parent
//                }
//            }

//            Rectangle {
//                id: rect3
//                width: 200; height: 50
//                border.color: "black"
//                color: "blue"
//                radius: 5

//                Text {
//                    id: text3
//                    text: "Movies"
//                    anchors.centerIn: parent
//                }
//            }
//        }

    Item {
        id: root
        x: 10; y: 10; z:1000
        width: 500; height: 500
        LayoutMirroring.enabled: true  // enabled thang cha include LayoutMirroring
        LayoutMirroring.childrenInherit: true // item con cua layout bi anh  huong
        anchors.centerIn: parent
        anchors.left: parent.left

        Rectangle {
            id: rect
            x:15
            y:20
            width: 300
            height: 50
            color: "yellow"
            radius: 5
            border.color: "gray"

            Row {
                anchors.left: parent.left
                spacing: 1
                Repeater {
                    model: 5
                    delegate: Rect {
                        text: index + 1
                        opacity: 1 - 0.2 * index
                    }
                }
            }
        }

//        Rect {
//            id: r1
//            x: 10; y:10
//        }

//        Rect {
//            id: r2
//            anchors {
//                left: r1.right
//                leftMargin: 3
//                top: r1.top
//            }
//            color: "red"
//            text: "2"
//        }

//        Rect {
//            id: r3
//            anchors {
//                left: r2.right
//                leftMargin: 3
//                top: r2.top
//            }
//            color: "blue"
//            text: "3"
//        }
    }
}
