import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 500
    height: 700
    title: qsTr("Exercises 3")

    Rectangle {
        width: 400
        height: 600
        anchors.centerIn: parent
        border.width: 1
        border.color: "gray"

        ListModel {
              id: idListModel

             ListElement {
                  name: "Pham Van Son"
                  birthday: "12/08/1989"
                  mobile: "0975.983.159"
              }
              ListElement {
                  name: "Ngo Cong Canh"
                  birthday: "13/05/1990"
                  mobile: "0979.580.095"
              }
              ListElement {
                  name: "Thoi Xuan Hanh"
                  birthday: "08/08/1995"
                  mobile: "0963.719.220"
              }
          }

        Component
        {
            id: idComp

            Row
            {
                spacing: 10
                EmployeeRec { id: idItem }
                Column
                {
                    spacing: 5
                    // Show name
                    Row
                    {
                        spacing: 10
                        Text { text: ' - Name: ' }
                        Text { text: name }
                    }

                    // Birthday
                    Row
                    {
                        spacing: 10
                        Text { text: ' - Birthday: '}
                        Text { text: birthday}
                    }

                    // Mobile
                    Row
                    {
                        spacing: 10
                        Text { text: ' - Mobile: '}
                        Text { text: mobile}
                    }
                }
            }
        }

        ListView
        {
            anchors.fill: parent
            model: idListModel
            delegate: idComp
        }
    }
}
