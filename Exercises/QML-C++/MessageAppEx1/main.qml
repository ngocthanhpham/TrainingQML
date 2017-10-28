import QtQuick 2.6
import QtQuick.Window 2.2

import QtQuick.Controls 2.1
import chat.message 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property var msgBoard
    signal postMessage(string msg)
//    Rectangle
//    {
//        objectName: "test"
////        property var msgBoard1
//    }

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }

    MessageBoard
    {
        id:messageBoard
        messages: [
            Message{
                messageBody: MessageBody
                {
                    content: "Hello"
                }
                messageAuthor: MessageAuthor
                {
                    name: "A"
                    email: "a@email.com"
                }
            },
            Message{
                messageBody: MessageBody
                {
                    content: "Hello"
                }
                messageAuthor: MessageAuthor
                {
                    name: "B"
                    email: "b@email.com"
                }
            },
            Message{
                messageBody: MessageBody
                {
                    content: "Hello"
                }
                messageAuthor: MessageAuthor
                {
                    name: "C"
                    email: "c@email.com"
                }
            }

        ]
        onMessageChanged:
        {

        }
    }

    Message
    {
        id: idMessage
        messageBody: MessageBody
        {
            content: "Hello"
        }
        messageAuthor: MessageAuthor
        {
            name: "A"
            email: "a@email.com"
        }
    }

    Column{
        anchors.fill: parent
        spacing: 5
        ListView {
            id: listViewDrawer
            width: parent.width
            height: childrenRect.height
            focus: true
            currentIndex: 1

//            model: messageBoard.messages
              model: msgBoard.messages
//            highlight: highlightComponent

            delegate: Rectangle
            {
                width: parent.width
                height: 35

                Column{
                    spacing: 5
                    Label
                    {
    //                    anchors.centerIn: parent
                        text: modelData.messageBody.content
                    }
                    Row{
                        spacing: 5
                        Label
                        {
                            text: modelData.messageAuthor.name
                        }
                        Label
                        {
                            text: modelData.messageAuthor.email
                        }
                    }
                }
                color: index%2 === 0 ? "grey" : "silver"
            }

        }

        Rectangle
        {
            width: 100
            height: 30

//            anchors.top: listViewDrawer.bottom
//            anchors.left: listViewDrawer.left
//            anchors.topMargin: 15

            color: "red"

            MouseArea{
                anchors.fill: parent
                onClicked:
                {
//                    messageBoard.postMessage("B")
                    console.log("hehe")
                    postMessage("B")
                }
            }
        }
    }

    Component
    {
        id: highlightComponent
        Item{
//            z: 1000
            width: ListView.view.width
            height: ListView.view.currentItem.height
            y: ListView.view.currentItem.y
            Behavior on y {
                SequentialAnimation{
                    PropertyAnimation{
                        target: highlightRect; property: "opacity"; to: 0; duration: 200
                    }

                    NumberAnimation{
                        duration: 1

                    }

                    PropertyAnimation{
                        target: highlightRect; property: "opacity"; to: 1; duration: 200
                    }
                }
            }

            Rectangle
            {
               id: highlightRect
               anchors.fill: parent
               color: "#157efb"
            }
        }
    }

//    Row
//    {
//        spacing: 5
//        Text{
//            text: idMessage.messageBody.content
//        }

//        Column
//        {
//            spacing: 5
//            Text {
//                id: name
//                text: idMessage.messageAuthor.name
//            }
//            Text {
//                id: email
//                text: idMessage.messageAuthor.email
//            }
//        }
//    }

}
