import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import message_test 1.0
import MessageBody_test 1.0
import MessageAuthor_test 1.0
import MessageBoard_test 1.0

import QtQuick.Controls 1.2

ApplicationWindow {

    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    signal add_element(string body)

    Item {
        width: parent.width
        height: parent.height
        ListView {
            anchors.fill: parent

            model: msgBoard.list_msgs

            delegate: show_message

        }
    }
    Component{
        id: show_message
        ScrollView{
            Column{
                Rectangle{
                    width: 200
                    height: 20
                    color: "blue"
                    Text {
                        text: modelData.author.mName + "(" + modelData.author.mEmail +")"
                    }
                }

                Rectangle{
                    width: 200
                    height: 20
                    Text {
                        text: modelData.body.mContent
                    }
                }
            }

        }


    }

    Rectangle {
        width: parent.width
        height: 70
        anchors.bottom: parent.bottom

        // border.color: "black"
        Column{
            spacing: 2
            width: 500
            height: parent.height
            Rectangle{
                width: parent.width
                height: 20

                Rectangle{
                    id: body
                    width: 40
                    height: parent.height
                    anchors.left: parent.left
                    color: "orange"

                    Text{
                        anchors.fill: parent
                        text: "Body:"
                    }

                }
                Rectangle{
                    width: parent.width -40
                    height: parent.height
                    anchors.right: parent.right
                    color: "white"
                    border.color: "gray"
                    TextEdit{
                        id: textbody
                        anchors.centerIn: parent
                        text: "Edit body"
                    }
                }
            }
            Rectangle{
                width: parent.width
                height: 20
                Rectangle{
                    width: 40
                    height: parent.height
                    anchors.left: parent.left
                    color: "orange"
                    Text{
                        anchors.fill: parent
                        text: "Name:"
                    }
                }
                Rectangle{
                    width: parent.width -40
                    height: parent.height
                    anchors.right: parent.right
                    color: "white"
                    border.color: "gray"
                    TextEdit{
                        id: textName
                        anchors.centerIn: parent
                        text: "Edit Name"
                    }
                }
            }
            Rectangle{
                width: parent.width
                height: 20
                Rectangle{
                    width: 40
                    height: parent.height
                    anchors.left: parent.left
                    color: "orange"
                    Text{
                        id: textemail
                        anchors.fill: parent
                        text: "Email:"
                    }
                }
                Rectangle{
                    width: parent.width -40
                    height: parent.height
                    anchors.right: parent.right
                    color: "white"
                    border.color: "gray"
                    TextEdit{
                        id: textEmail
                        anchors.centerIn: parent
                        text: "Edit Email"
                    }
                }
            }
        }
        Rectangle{
            anchors.right: parent.right
            width: parent.height
            height: parent.height
            color: "red"
            Text {

                anchors.centerIn: parent
                id: add_buttom
                text: qsTr("Add")
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                   root.add_element("aaaaa")

                }
            }
        }



    }

}
