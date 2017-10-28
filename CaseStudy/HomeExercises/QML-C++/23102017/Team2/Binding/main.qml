import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import Content 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Binding")

    property var contentObj
//    Content
//    {
//        id: idContent
//    }

    TextField
    {
        id: idSource
        width: 300
        height: 50
        font.pixelSize: 12
        anchors.centerIn: parent
        placeholderText: "Please type here..."
    }

    Binding
    {
        target: contentObj
        property: "content"
        value: idSource.text
    }
}
