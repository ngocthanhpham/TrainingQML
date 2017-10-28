import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property int backgroundNumber: 1

    //    MainForm {
    //        anchors.fill: parent
    //        mouseArea.onClicked: {
    //            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
    //        }
    //    }


    // -------------------------------------------------------------------------------------------

        Item {
            id: main
            width: 200
            height: 200
            anchors.centerIn: parent

            Loader {
                id: loader

                anchors.fill: parent
                source: "Red.qml"

                Connections {
                    target: loader.item
                    onMessage: {
                        loader.source = msg
                    }
                }
            }


        }
    // ------------------------------------------------------------------------------------------

//    Item {
//        id: root
//        width: 200; height: 200
//        anchors.centerIn: parent

//        Loader {
//            id: loader
//            anchors.fill: parent
//            anchors.centerIn: parent
//            sourceComponent: rectRed
//        }

//        Component {
//            id: rectRed
//            Red {
//                anchors.centerIn: parent
//            }
//        }

//        Component {
//            id: rectBlue
//            Blue {
//                anchors.centerIn: parent
//            }
//        }

//        MouseArea {
//            anchors.fill: parent

//            onClicked: {
//                loader.sourceComponent = (backgroundNumber == 1 ? rectBlue : rectRed)
//                backgroundNumber = (backgroundNumber == 1 ? 2 : 1)
//            }
//        }

//    }

}
