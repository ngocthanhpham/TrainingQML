import QtQuick 2.0
Item {
    width: childrenRect.width
    height: childrenRect.height
    id: name
     property alias color: rec.color
     property alias ddw: rec.width
     property alias ddh: rec.height
    Rectangle
    {
        id :rec
        width: 80
        height: 80
        color: "green"


    }
}
