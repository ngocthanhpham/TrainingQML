import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Sample 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Message Board")

    property var msgBoard

    signal simpleSignalCount()

    signal signalExposeObject(var msg)

    CMessageBoard
    {
        id: idBoard
        messages:
        [
            CMessage
            {
                id: idMes1
                author: CMessageAuthor
                {
                     name: "name 1"
                     email: "mail 1"
                }

                body: CMessageBody
                {
                    content: "Content 1"
                }
            },

            CMessage
            {
                id: idMes2
                author: CMessageAuthor
                {
                     name: "name 2"
                     email: "email 2"
                }

                body: CMessageBody
                {
                    content: "Content 2"
                }
            }
        ]
    }

    Rectangle
    {
        id: idRect
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        border.color: "gray"
        border.width: 1

        ListView
        {
            id: idView

            width: parent.width
            height: parent.height
            model: idBoard.messages

            delegate: Rectangle
            {
                // id: item
                height: 25
                width: 400
                color: "gray"

                Text
                {
                    text: modelData.author.name + " - " + modelData.author.email + " - " +modelData.body.content
                }
            }
        }
    }

    // Add
    Button
    {
        id: idAdd
        width: 100
        height: 50
        text: "Add"
        anchors
        {
            right: idRect.right
            bottom: idRect.bottom
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                idBoard.addNew();
            }
        }
    }

    // Find for ex1
    Button
    {
        id: idFind
        width: 100
        height: 50
        text: "Find"
        anchors
        {
            right: idAdd.left
            rightMargin: 5
            bottom: idAdd.bottom
        }

        MouseArea
        {
            id: idFindArea
            anchors.fill: parent
        }
    }

    Connections
    {
        target: idFindArea
        onClicked:
        {
            msgBoard.find("name", "email", "content")
        }
    }

    // Count for ex2
    Button
    {
        id: idCount
        width: 100
        height: 50
        text: "Count"
        objectName: "btnCount"

        anchors
        {
            right: idFind.left
            rightMargin: 5
            bottom: idFind.bottom
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                simpleSignalCount()
            }
        }
    }

    // Clear
    Button
    {
        id: idClear
        width: 100
        height: 50
        text: "Find Object"
        anchors
        {
            right: idCount.left
            rightMargin: 5
            bottom: idCount.bottom
        }

        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                signalExposeObject(idBoard.messages[0])
            }
        }
    }
}
