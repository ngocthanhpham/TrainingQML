import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls 2.0
import sinhvien 1.0

ApplicationWindow {
    id: root_window
    visible: true
    width: 640
    height: 600
    title: qsTr("QUẢN LÝ SINH VIÊN")
    property int tblIndex: 0
    signal themSv(var student)
    signal xoaSv(int i)
    signal suaSv(var student,int i)
    signal sendTblIndex(int i)

    Student{
        id: sinhvien
        name: "a"
        age: "a"
        sex: "a"
        email: "a"
        address: "a"
        mobilNumber: "a"

    }

    Rectangle {
        id:root
        width: root_window.width; height: 182
        border.color: "black"
        SvField{
            id:fieldName
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:parent.top
            focus: true
            placeholderText: "Nhập tên sinh viên"
        }
        SvField{
            id:fieldAge
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:fieldName.bottom
            focus: false
            placeholderText: "Nhập tuổi"
        }
        SvField{
            id:fieldSex
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:fieldAge.bottom
            focus: false
            placeholderText: "Giới Tính"
        }
        SvField{
            id:fieldEmail
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:fieldSex.bottom
            focus: false
            placeholderText: "Email"
        }
        SvField{
            id:fieldNumber
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:fieldEmail.bottom
            focus: false
            placeholderText: "Số điện thoại"
        }
        SvField{
            id:fieldAddr
            width: 0.7*root.width
            height: 30
            anchors.left: parent.left
            anchors.top:fieldNumber.bottom
            focus: false
            placeholderText: "Địa Chỉ"
        }
    }

    Button {
        id:bntAdd
         width: 0.2*root.width
         height: 40
         y:10
         anchors.right: parent.right
         anchors.rightMargin: 30
         text: "Nhập"
         onClicked: {
             if( fieldName.text != "")
                   sinhvien.name = fieldName.text
             else sinhvien.name = "NA"

             if( fieldAge.text != "")
                sinhvien.age = fieldAge.text
             else  sinhvien.age = "NA"

             if( fieldSex.text != "")
                sinhvien.sex = fieldSex.text
             else sinhvien.sex = "NA"

             if( fieldEmail.text != "")
                sinhvien.email = fieldEmail.text
             else sinhvien.email="NA"

             if( fieldAddr.text != "")
                sinhvien.address = fieldAddr.text
             else sinhvien.address = "NA"

             if( fieldNumber.text != "")
                sinhvien.mobilNumber = fieldNumber.text
             else sinhvien.mobilNumber = "NA"
             themSv(sinhvien)
             console.log("click them sv: themSv(sinhvien)")
//             inSinhvien()
         }
    }
    Button {
        id:bntDel
         width: 0.2*root.width
         height: 40
         y:60
         anchors.right: parent.right
         anchors.rightMargin: 30
         text: "Xóa"
         onClicked: {
             xoaSv(tblIndex)
         }
    }
    Button {
        id:bntUpdate
         width: 0.2*root.width
         height: 40
         y:110
         anchors.right: parent.right
         anchors.rightMargin: 30
         text: "Sửa"
         onClicked: {
             if( fieldName.text != "")
                   sinhvien.name = fieldName.text
             else sinhvien.name = "NA"

             if( fieldAge.text != "")
                sinhvien.age = fieldAge.text
             else  sinhvien.age = "NA"

             if( fieldSex.text != "")
                sinhvien.sex = fieldSex.text
             else sinhvien.sex = "NA"

             if( fieldEmail.text != "")
                sinhvien.email = fieldEmail.text
             else sinhvien.email="NA"

             if( fieldAddr.text != "")
                sinhvien.address = fieldAddr.text
             else sinhvien.address = "NA"

             if( fieldNumber.text != "")
                sinhvien.mobilNumber = fieldNumber.text
             else sinhvien.mobilNumber = "NA"
            suaSv(sinhvien,tblIndex)
         }
    }

    TableView
    {
        width: root_window.width
        height: root_window.height - root.height
        anchors.left: parent.left
        anchors.top: root.bottom
        TableViewColumn{
            role: "name"
            title: "Họ và Tên"
            width: 100
        }
        TableViewColumn{
            role: "age"
            title: "Tuổi"
            width: 100
        }
        TableViewColumn{
            role: "sex"
            title: "Giới Tính"
            width: 100
        }
        TableViewColumn{
            role: "email"
            title: "EMail"
            width: 100
        }
        TableViewColumn{
            role: "mobilNumber"
            title: "Số điện thoại"
            width: 100
        }
        TableViewColumn{
            role: "address"
            title: "Địa chỉ"
            width: 100
        }
        model: stuModel
        onClicked: {
//            fieldName.text = (String)stuModel.data(row,1)
//            console.log(stuModel.rowCount());
            tblIndex = row;
            sendTblIndex(tblIndex);
//            console.log(sinhvien.name.toString());
//            inSinhvien()
        }
    }
    Connections{
        target: stuModel
        onUpdateUi:{
            fieldName.text = name
            fieldAge.text = age
            fieldSex.text = sex
            fieldEmail.text = email
            fieldAddr.text = address
            fieldNumber.text = mobilNumber
        }
    }

    function inSinhvien()
    {
        console.log(sinhvien.name +"\n")
        console.log(sinhvien.age +"\n")
        console.log(sinhvien.sex +"\n")
        console.log(sinhvien.email +"\n")
        console.log(sinhvien.mobilNumber +"\n")
        console.log(sinhvien.address +"\n")
    }
}
