import QtQuick 2.0
import QtQuick.Controls 2.0

Page {
    width: 640
    height: 420
//    Text {
//        id: name
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.centerIn: parent
//        text: qsTr("Third page")
//    }

//    ListModel {
//        id: listModeId
//        ListElement {
//          name: "Bill Smith"
//          number: "555 3264"
//        }
//        ListElement {
//          name: "John Brown"
//          number: "555 8426"
//        }
//        ListElement {
//          name: "Sam Wise"
//          number: "555 0473"
//        }
//   }

//    ListView {
//        width: 180; height: 200
//        anchors.centerIn: parent

//        model: listModeId
//        delegate: Text {
//          text: name + ": " + number
//        }
//      }


    Rectangle{
        id: rect
        width: 340
        height: 200
        border.width: 1
        border.color: "gray"
        anchors.centerIn: parent
        Grid {
            anchors.fill: rect
            columns: 1
            spacing: 1
            Repeater {
                model: ListModel {
                    ListElement {stt: ""; name: "Name"; DateOfBird: "Date of bird"; Department: "Department"}
                    ListElement {stt: "1"; name: "Dam Minh Dung"; DateOfBird: "25-11-1989"; Department: "SD3"}
                    ListElement {stt: "2"; name: "Le Huu Quan"; DateOfBird: "2-8-1989"; Department: "SD3"}
                    ListElement {stt: "3"; name: "Do Van Tuan"; DateOfBird: "14-11-1989"; Department: "SD2"}
                    ListElement {stt: "4"; name: "Pham Van Son"; DateOfBird: "6-8-1989"; Department: "SD3"}
                    ListElement {stt: "5"; name: "Nguyen Thi Minh Thu"; DateOfBird: "19-6-1992"; Department: "VT1"}
                    ListElement {stt: "6"; name: "Nguyen Thi Hong Nhan"; DateOfBird: "31-3-1994"; Department: "VT2"}
                    ListElement {stt: "7"; name: "Tran Mong Dung"; DateOfBird: "11-6-1994"; Department: "SD3"}
                    ListElement {stt: "8"; name: "Le Kim Lien"; DateOfBird: "24-3-1995"; Department: "VT1"}
                    ListElement {stt: "9"; name: "Le Thi Hang"; DateOfBird: "21-8-1989"; Department: "SD3"}
                }

                BaseRectange {
                    width: 340
                    height: index === 0 ? 20:30
                    //border.color: "gray"
                    //border.width: 1

                    Row {
                        width: 340
                        height: parent.height
                        id: row
                        anchors.top: parent.top
                        anchors.left: parent.left
                        spacing: 1

                        BaseRectange {
                            width: 20
                            height: parent.height
                            x: 0
                            y: 0
                            color: "#A0A0A0"
                            border.color: "gray"
                            border.width: 1
                            Text {
                                anchors.centerIn: parent
                                text: stt
                            }
                        }
                        BaseRectange {
                            width: 150
                            height: parent.height
                            x: 20
                            y: 0
                            color: index === 0 ? "#A0A0A0":"#FFFFFF"
                            border.color: "gray"
                            border.width: 1
                            Text {
                                anchors.centerIn: parent
                                text: name
                            }
                        }
                        BaseRectange {
                            width: 100
                            height: parent.height
                            x: 170
                            y: 0
                            color: index === 0 ? "#A0A0A0":"#FFFFFF"
                            border.color: "gray"
                            border.width: 1
                            Text {
                                anchors.centerIn: parent
                                text: DateOfBird
                            }
                        }
                        BaseRectange {
                            width: 70
                            height: parent.height
                            x: 270
                            y: 0
                            color: index === 0 ? "#A0A0A0":"#FFFFFF"
                            border.color: "gray"
                            border.width: 1
                            Text {
                                anchors.centerIn: parent
                                text: Department
                            }
                        }

                    }


                }
            }

        }
    }




}
