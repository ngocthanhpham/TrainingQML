import QtQuick 2.0
import QtQuick 2.7

import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3


Rectangle
{
    id: rectId
    width: 640
    height: 480
    //color: "blue"

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        Page1{

        }
        Page2 {

        }
        Page3 {

        }
    }

    TabBar {
        id: tabBar
        width: 640
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        currentIndex: swipeView.currentIndex
        TabButton {
            width: tabBar.width/3
            height: 50
            anchors.left: tabBar.left
            anchors.top: tabBar.top
            text: qsTr("First")
        }
        TabButton {
            width: tabBar.width/3
            height: 50
            anchors.horizontalCenter: tabBar.horizontalCenter
            anchors.top: tabBar.top
            text: qsTr("Second")
        }


        TabButton {
            width: tabBar.width/3
            height: 50
            anchors.right: tabBar.right
            anchors.top: tabBar.top
            text: qsTr("Third")
        }

    }
}
