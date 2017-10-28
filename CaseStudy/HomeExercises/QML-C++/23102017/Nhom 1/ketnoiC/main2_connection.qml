import QtQuick 2.0

Item {
    width: 500
    height: 350

//    ListView{
//        anchors.fill: parent
//        model: messageBoard.listMsg
//        delegate:
//            Row{
//                spacing: 10
//                Text{ text: modelData.body.content}
//                Text{ text: modelData.author.name}
//                Text{ text: modelData.author.eMail}
//            }

//    }
//    MouseArea{
//        anchors.fill: parent
//        onClicked: {
//            console.log("mouse click")
//            messageBoard.onButtonClick()
//        }
//    }

    Text{
        text:messageBody.content
    }
    CTextInput{
        id:txtinput
        x:10; y:100
        width: 250
        height: 25
//        onInputTextChanged: {
//            messageBody.content = txtinput.text
//        }
    }
    Binding {
        target: messageBody
        property: "content"
        value:txtinput.text
    }
}
