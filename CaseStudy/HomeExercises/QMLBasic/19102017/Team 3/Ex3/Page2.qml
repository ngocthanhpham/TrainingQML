import QtQuick 2.0
import QtQuick.Controls 2.0

Page {
    width: 640
    height: 420
    property int mode: 1

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(mode === 1)
                mode = 0
            else
                mode = 1
        }
    }

    BaseRectange {
        width: 100
        height: 100
        anchors.centerIn: parent
        color: mode === 1 ? "red":"blue"
    }

}
