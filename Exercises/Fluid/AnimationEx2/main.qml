import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int duration: 2000
//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }
    Image {
        id: bg
        source: "qrc:/Image/background-21717_640.jpg"
        Ball
        {

            property int moveYValue: parent.height - height
            x:40
            y: moveYValue
//            height: parent.height - height
            onMove: moveYValue = 60
            NumberAnimation on y {
                to: 300; duration: 2000
            }
            RotationAnimation on rotation
            {
                to: 360
                duration: 2000
            }

        }

        Ball
        {

            property int moveYValue: parent.height - height
            x:180
            y: moveYValue
//            height: parent.height - height
            onMove: moveYValue = 60

            Behavior on y
            {
                NumberAnimation {
                    duration: 2000
                }
            }

        }

        Ball
        {
            id: ball3
            property int moveYValue: parent.height - height
            x:320
            y: moveYValue
//            height: parent.height - height
            onMove:
            {
//                ball3Animation.start()
//                ball3Rotation.start()
                anim.start()
            }

//            NumberAnimation
//            {
//                id: ball3Animation
//                target: ball3
//                properties: "y"
//                to: 80
//                duration: 2000
//            }

//            RotationAnimation
//            {
//                id: ball3Rotation
//                target: ball3
//                properties: "rotation"
//                to: 80
//                duration: 2000

//            }

            ParallelAnimation {
                  id: anim
                  SequentialAnimation {
                      NumberAnimation {
                          target: ball3
                          properties: "y"
                          to: 20
                          duration: root.duration * 0.4
                          easing.type: Easing.OutCirc
                      }
                      NumberAnimation {
                          target: ball3
                          properties: "y"
                          to: root.height - ball3.height
                          duration: root.duration * 0.6
                          easing.type: Easing.OutBounce
                      }
                  }
                  NumberAnimation {
                      target: ball3
                      properties: "x"
                      to: root.width - ball3.width
                      duration: root.duration
                  }
                  RotationAnimation {
                      target: ball3
                      properties: "rotation"
                      to: 720
                      duration: root.duration
                  }
              }


        }

    }

}
