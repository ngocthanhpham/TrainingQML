import QtQuick 2.0

Item {
    signal testconnection()
    Rectangle{

        width: 50
        height: 50
        color: "green"
        MouseArea{
            anchors.fill: parent
            onClicked:
            {
                testconnection()
            }
        }
    }

}
