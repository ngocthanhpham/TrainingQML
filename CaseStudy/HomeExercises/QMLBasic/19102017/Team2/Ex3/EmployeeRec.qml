import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle
{
    id: idRoot
    width: 40
    height: 60
    border.color: "gray"
    border.width: 1

    Image {
        id: idImage
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        source: "qrc:/Resource/Resource/employee.png"
        fillMode: Image.PreserveAspectFit
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log("123")
            }
        }
    }
}
