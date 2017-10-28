import QtQuick 2.0

Item
{
    width: 100
    height: 100

    Component
    {
        id: idRed
        Rectangle
        {
            color: "red"
            width: 100
            height: 100
        }
    }

    Loader { sourceComponent: idRed }
}
