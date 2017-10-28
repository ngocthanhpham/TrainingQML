import QtQuick 2.6
import QtQuick.Window 2.2
import sample 1.0

Item {
    id: itemId
    width: 640
    height: 480

    property var msgBoard

    signal postSignal(string content, string name, string email)
    signal postSignalObject(var aObject, int mode)
    signal postSignalText(string text)

    property string textInput: textId.text


    MessageBoard {
        id: messageBoard
        message: [
        Message {
                messageBody: MessageBody {
                    content: "Hello"
                }
                messageAuthor: MessageAuthor {
                    name: "Đàm Minh Dũng"
                    email: "dung2.dam@lge.com"
                }
            },
            Message {
                    messageBody: MessageBody {
                        content: "Hello"
                    }
                    messageAuthor: MessageAuthor {
                        name: "Phạm Văn Sơn"
                        email: "son.pham@lge.com"
                    }
                },
            Message {
                    messageBody: MessageBody {
                        content: "Hello"
                    }
                    messageAuthor: MessageAuthor {
                        name: "Nguyễn Trung Dũng"
                        email: "dung3.nguyen@lge.com"
                    }
                }
        ]
    }

    ListView {
        width: 300
        height: 300
        anchors.centerIn: parent
        model: msgBoard.message

        delegate: Text {
            text: modelData.messageBody.content + " " + modelData.messageAuthor.name + " " + modelData.messageAuthor.email
        }
    }

    Rectangle {
        width: 100
        height: 100
        x: 0
        y: 0
        border.width: 1
        border.color: "gray"
        anchors.centerIn: parent
        MouseArea{
            id: area
            anchors.fill: parent
//            onClicked: {
//                var result = false;
//                result = messageBoard.setData("Content", "Dam Minh Dung", "dung2.dam@lge.com");

//                postSignal("Content", "Minh Dung", "dung2.dam@lge.com")
//            }
        }

        Connections {
            target: area
            onClicked:{
                console.log("setData")
//                postSignal("Content", "Minh Dung", "dung2.dam@lge.com")
                msgBoard.setData("Content", "Dam Minh Dung", "dung2.dam@lge.com");
            }
        }
    }

    Rectangle {
        id: rectId
        width: 200
        height: 30
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        border.width: 1
        border.color: "gray"

        TextInput {
            id: textId
            width: parent.width
            height: parent.height
            anchors.centerIn: parent

            onTextChanged: {
                postSignalText(text)
                //postSignalObject(itemId, 0)
            }

        }
    }

    Rectangle {
        width: 150
        height: 50
        anchors.right: parent.right
        anchors.top: parent.top
        border.width: 1
        border.color: "gray"

        Text {
            anchors.centerIn: parent
            text: "Send Object"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                postSignalObject(itemId, 1)
            }
        }
    }
    Binding {
        target: msgBoard
        property: "strText"
        value: textId.text
    }





}
