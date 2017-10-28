import QtQuick 2.0

Item
{
    width: 100
    height: 100

    Component
    {
        id: idBlue
        Rectangle
        {
            color: "blue"
            width: 100
            height: 100
        }
    }

    Loader { sourceComponent: idBlue }
}
