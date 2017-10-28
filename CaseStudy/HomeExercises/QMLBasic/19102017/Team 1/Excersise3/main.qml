import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    //    MainForm {
    //        anchors.fill: parent
    //        mouseArea.onClicked: {
    //            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
    //        }
    //    }

    ListModel {
        id: listmodelId
        ListElement {name: "Mr.Hung"; city: "London"; age: "35"; image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Dung"; city: "Pari"; age: "30";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Son"; city: "Berlin"; age: "30";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Canh"; city: "Seoul"; age: "27";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Hung"; city: "Taipei"; age: "26";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Thinh"; city: "Washington"; age: "26";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Thanh"; city: "Los Angeles"; age: "24";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Dung"; city: "Manhester"; age: "22";image:"qrc:/Images/D:/img.png"}
        ListElement {name: "Mr.Hanh"; city: "Liverpool"; age: "22";image:"qrc:/Images/D:/img.png"}
    }

    ListView {
        id: listviewId
        model: listmodelId
        property int  fontSize: 20
        anchors.fill: parent
        delegate: delegateId
        highlight:
            Rectangle {
            width: parent.width
            color: "lightgray"
        }
        header:
            Rectangle {
            width: parent.width; height: 30
            gradient: appColorsId
            border
            {
                color: borderColor
                width: borderWidth
            }

            Text {
                text: "Danh sach"
                font.pixelSize: 32
                anchors.centerIn: parent
            }
        }
        footer:
            Rectangle {
            width: parent.width; height: 30
            color: "dodgerblue"
        }

        section {
            property: "age"
            criteria: ViewSection.FullString
            labelPositioning: ViewSection.InlineLabels
            delegate: Rectangle {
                width: listviewId.width
                height: 30
                color: "yellow"
                Text
                {
                    text: section; font.pixelSize: listviewId.fontSize
                }
            }
        }

    }

    Component {
        id: delegateId

        Item {
            id: rowId
            height: datarowId.implicitHeight
            width: datarowId.implicitWidth

            Row {
                id: datarowId
                spacing: 30

                Text {
                    text: index + 1 + ". " + model.name
                    font.pixelSize: rowId.ListView.view.fontSize
                }

                Text {
                    text: city
                    font.pixelSize: listviewId.fontSize
                }

                Text {
                    text: age
                    font.pixelSize: listviewId.fontSize
                }

                Image {
                    height: 40; width: 40
                    source: model.image
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: rowId.ListView.view.currentIndex = index
            }
        }
    }
}
