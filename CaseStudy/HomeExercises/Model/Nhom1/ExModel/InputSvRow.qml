import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

Rectangle {
    id: rowInfo
    width: 200 ; height: 80
    border.color: "black"
    property alias placehodertext: txtName.placeholderText
    Rectangle {
        id: rectName
        width: 0.8*rowInfo.width
        height: 0.8*rowInfo.height
        border.color: "black"
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 5
        anchors.topMargin: 5

        TextField {
            width: parent.width
            height: parent.height
            focus: true
            id: txtName
            placeholderText: "..."
        }
    }

    Button {
        width: 0.17*rowInfo.width
        height: rectName.height
        anchors.left: rectName.right
        anchors.top: rectName.top
        anchors.leftMargin: 5

        text: "Nhập"
        onClicked: {
            sinhVien
            {
                id: sendingSv
                name: txtName.text
                phoneNumber: txtNumberPhone.text
                sex: txtSex.text
            }
        }
    }
