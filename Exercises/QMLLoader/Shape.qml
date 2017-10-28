import QtQuick 2.0

Item {
    QtObject {
        id: shape
        property int square: 0
        property int circle: 1
        property int rectangle: 2
    }
    property alias shape: shape
    property int type: shape.rectangle
    property color shapeColor: "red"
}
