import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "chat" as Chat
ApplicationWindow {
    id: window
    visible: true
    width: 540
    height: 960
    title: qsTr("Hello World")
    Chat.ConversationPage
    {
        id: conversationPage
        objectName: "conversationPage"
        anchors.fill: parent
    }
}
