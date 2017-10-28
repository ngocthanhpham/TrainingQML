import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import "Util.js" as Util
Item {
    id: root
    width: 200
    height: 200
    property int count: 1
    Loader{
        id:recloader
        source: "RedRectangle.qml"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            Util.clicked123()
        }
    }

}
