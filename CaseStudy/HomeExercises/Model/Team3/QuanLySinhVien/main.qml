import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import mySinhvien 1.0
import mySinhvienModel 1.0
import QtQuick.Controls 1.4
ApplicationWindow
{
    visible: true
    width: 470
    height:700
    title: qsTr("Hello World")
    signal sendMessage(var message)
    signal sendindex (int index)
    signal sendindextable (int index)
    property int  temp: 0
    Rectangle
    {

        width: parent.width
        height: parent.height
        border.color: "red"

        Row
        {
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top:parent.top
            anchors.topMargin: 20
            spacing: 20

            Column
            {
                spacing: 10
                TextField
                {
                    id: idname
                    height: 40
                    width: 200
                    placeholderText: "Nhập họ tên "
                }
                TextField
                {
                    id: idtuoi
                    height: 40
                    width: 200
                    placeholderText: "Nhập tuổi"


                }
                TextField
                {
                    id: idvitrixoa
                    height: 40
                    width: 200
                    placeholderText: "Nhập vị trí cần xóa"


                }
            }
            Column
            {
                spacing: 10
                TextField
                {
                    id: iddiachi
                    height: 40
                    width: 200
                    placeholderText: "Nhập địa chỉ"
                }
                TextField
                {
                    id: idemail
                    height: 40
                    width: 200
                    placeholderText: "Nhập email"
                }
                TextField
                {
                    id: idsodienthoai
                    height: 40
                    width: 200
                    placeholderText: "Nhập số điện thoại"
                }

            }
        }

        Sinhvien
        {
            id:sendingMsg
            name:idname.text
            tuoi:idtuoi.text
            diachi:iddiachi.text
            email:idemail.text
            sodienthoai:idsodienthoai.text

        }

        Row
        {

            anchors.left: parent.left
            anchors.leftMargin: 120
            anchors.top:parent.top
            anchors.topMargin: 200
            spacing: 20
            Rectangle
            {
                height: 40
                width: 60
                border.color: "green"

                Text
                {
                    id: idtext
                    anchors.centerIn: parent
                    text: "Thêm"
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        console.log(temp)
                        sendMessage(sendingMsg)
                        cleartext();
                    }
                }

            }
            Rectangle
            {
                height: 40
                width: 60
                border.color: "green"

                Text
                {
                    id: idtext1
                    anchors.centerIn: parent
                    text: "Sửa"
                }

            }

            Rectangle
            {
                height: 40
                width: 60
                border.color: "green"


                Text
                {
                    id: idtext2
                    anchors.centerIn: parent
                    text: "Xóa"
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {

                        sendindex(temp)


                    }

                }

            }
        }

        //        ListView
        //        {
        //            anchors.left: parent.left
        //            anchors.leftMargin: 20
        //            anchors.top:parent.top
        //            anchors.topMargin: 340
        //            anchors.fill: parent
        //            //  anchors.margins: 20
        //            spacing: 20
        //            clip: true
        //            model: svmodel
        //            //  orientation: ListView.Horizontal
        //            delegate: numberDelegate
        //        }

        //        Component
        //        {
        //            id: numberDelegate

        //            Column
        //            {
        //                spacing: 5
        //                Text
        //                {
        //                    text:"Tên: " + name
        //                }

        //                Text
        //                {
        //                    text: "Tuổi: " + tuoi

        //                }
        //                Text
        //                {
        //                    text: "Địa chỉ: " + diachi
        //                }
        //                Text
        //                {
        //                    text: "Email: " + email
        //                }
        //                Text
        //                {
        //                    text: "Số điện thoại: " + sodienthoai
        //                }

        //            }

        //        }

        TableView
        {
            id:idtableview

            height: 150
            width: 190
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.top:parent.top
            anchors.topMargin: 340
            anchors.fill: parent

            TableViewColumn{
                role: "name"
                title: "Họ và tên"
                width: 100
            }
            TableViewColumn{
                role: "tuoi"
                title: "Tuổi"
                width: 50
            }
            TableViewColumn{
                role: "diachi"
                title: "Địa chỉ"
                width: 100
            }
            TableViewColumn{
                role: "email"
                title: "EMail"
                width: 100
            }
            TableViewColumn{
                role: "sodienthoai"
                title: "Số điện thoại"
                width: 100
            }

            model: svmodel

            onClicked:
            {
                temp = row
                sendindextable(row)

  //              console.log(row)
             }

        }

    }


    Connections
    {
        target: svmodel
        ignoreUnknownSignals: true

        onSendData:
        {
            idname.text = name
            idtuoi.text = tuoi
            idsodienthoai.text = sodienthoai
            iddiachi.text = diachi
            idemail.text = email
        }
    }
    function cleartext()
    {
        idname.text=""
        idtuoi.text=""
        iddiachi.text=""
        idemail.text=""
        idsodienthoai.text=""
        idvitrixoa.text=""
        idname.forceActiveFocus()
    }
}











