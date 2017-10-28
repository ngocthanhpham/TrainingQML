import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Chat.message 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

//    CMessageBoard{
//        id:messBoard
//        listMsg: [
//            CMessage{
//                body:CMessageBody{
//                    content: "Hello from CMessage\n"
//                }
//                author:CMessageAuthor{
//                    name: "Hung\n"
//                    eMail: "hung3.nguyen@lge.com\n"
//                }
//            },
//            CMessage{
//                body:CMessageBody{
//                    content: "Hello from CMessage1\n"
//                }
//                author:CMessageAuthor{
//                    name: "Hung1\n"
//                    eMail: "hung3.nguyen@lge.com1\n"
//                }
//            }

//        ]
//    }



    Rectangle{
        id:rect
        x:50; y:100
//        height: 200
//        width: 200
        anchors.fill: parent
        color: "linen"

        ListView{
            anchors.fill: parent
            model: 2//messBoard.listMsg
            delegate:
                Row{
                    spacing: 10
                    Text{ text: "modelData.body.content"}
                    Text{ text: "modelData.author.name"}
                    Text{ text: "modelData.author.eMail"}
                }

        }
        Rectangle{
            id:subrect
            width: 70
            height: 50
            anchors.centerIn: parent
            color: "red"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //messBoard.listMsg[0].body.content = "test"
                    console.log("button click")
//                    messBoard.onButtonClick()
                }
            }
        }

    }

//    MouseArea{
//        anchors.fill: subrect
//        onClicked: {
//            messBoard.msg.body.content = "content was changed by clicking\n"
//            console.log("Button clicked")}
//    }

}
