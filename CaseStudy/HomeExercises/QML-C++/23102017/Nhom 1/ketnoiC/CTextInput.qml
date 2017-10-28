import QtQuick 2.0

Rectangle {
    property alias text: txt.text
    width: 200
    height: 50
    border.width: 2
    border.color: "blue"
    signal inputTextChanged()
    TextInput{
        id: txt
        anchors.fill: parent
        focus: true
        wrapMode: TextInput.Wrap
        onTextChanged: inputTextChanged()
    }
}
