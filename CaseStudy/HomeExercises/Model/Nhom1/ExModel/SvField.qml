import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0

FocusScope {
    id: inputField
    property alias text: txtName.text
    property alias placeholderText: txtName.placeholderText
    width: 300
    height: 100
    Rectangle{
        width: inputField.width -2
        height: inputField.height -2
        anchors.centerIn: parent.Center
        anchors.margins: 1
        border.color: "black"
        border.width: 1
        TextField {
             width: parent.width
             height: parent.height
             anchors.centerIn: parent.Center
             focus: true
             id: txtName
             placeholderText: "Nhập tên sinh viên"
        }
    }

}
