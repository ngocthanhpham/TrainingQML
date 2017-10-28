import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import Manager.Film.Film 1.0
import Manager.Film.Director 1.0
import Manager.Film.Actor 1.0
import Manager.Film.FilmBoard 1.0

ApplicationWindow {
    visible: true
    width: 700
    height: 480
    title: qsTr("MyListFilm")

    Item{
        id:rootItem
        objectName: "dadItem"
        height: 500; width: 1000
        property int number
        property alias fBoard : filmBoard
        property  alias indexFilm: idListFilm.currentIndex
        signal removeFilmQML(var filmBoard)

        signal sendTextSearch(string msg)

        Rectangle{
            id: toprec
            width: parent.width
            height: 100
            RowLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 35
                anchors.top: parent.top
                TextField {
                    id: txtSearch
                    text: rootItem.number
                    placeholderText: qsTr("Text Field")
                    onTextChanged: {
                        rootItem.sendTextSearch(txtSearch.text)
                    }
                }

                Button {
                    id: btnSearch
                    text: qsTr("Search")
                    onClicked: {
                        console.log("BtnSearch Pressed. Entered text: " + txtSearch.text);
                    }

                }
                Button {
                    id: btnInsertFilm
                    text: qsTr("Insert")
                    onClicked: {
                        filmBoard.insertFilm();
                        console.log("BtnInsert Pressed");
                    }

                }

                Button {
                    id: btnRemoveFilm
                    text: qsTr("Remove")
                    onClicked: {
                        rootItem.removeFilmQML(filmBoard)
                        console.log("BtnRemove Pressed");
                    }

                }

                Button {
                    id: btnRemoveAFilm
                    text: qsTr("RemoveOne")
                    onClicked: {
                        filmBoard.removeFilm(rootItem.indexFilm)
                        console.log("BtnRemove a film Pressed");
                    }

                }
            }

            FilmBoard{
                id: filmBoard
                listFilm:[
                    Film{
                        name: "Spider-Man:Homecoming"
                        mDirector: Director{
                            nameDirector: "Jon Watts"
                            ageDirector: 50
                            nationalityDirector: "England"
                        }
                        mActor: Actor{
                            nameActor: "TomHolland"
                            ageActor: 27
                            nationalityActor: "American"
                        }
                        yom: 2017
                        pb: 1000
                    },
                    Film{
                        name: "Thor:Ragnarok"
                        mDirector: Director{
                            nameDirector: "Taika Waititi"
                            ageDirector: 50
                            nationalityDirector: "VietNam"
                        }
                        mActor: Actor{
                            nameActor: "Chris Hemsworth"
                            ageActor: 27
                            nationalityActor: "Japan"
                        }
                        yom: 2017
                        pb: 1000
                    }
                ]
            }

            Component{
                id: filmDelegate
                Item{
                    width: parent.width
                    height: 40
                    Row{
                        id: row1
                        spacing: 15
                        MyRectangle
                        {
                            color: "transparent"
                            Text {text:"FilmName: " + modelData.name; topPadding: 10}
                        }
                        MyRectangle{
                            color: "transparent"
                            Text {text:"PublishedYear: " + modelData.yom; topPadding: 10}
                        }
                        MyRectangle{
                            color: "transparent"
                            Text {text:"DirectorName: " + modelData.mDirector.nameDirector; topPadding: 10}
                        }
                        MyRectangle{
                            color: "transparent"
                            Text {text: "ActorName: " + modelData.mActor.nameActor; topPadding: 10}
                        }
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: idListFilm.currentIndex = index
                    }
                }
            }
            Rectangle{
                id: recbot
                width: parent.width
                height: 400
                anchors.top: toprec.bottom
                //                color: "red"
                ListView{
                    id: idListFilm
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    anchors.fill: parent
                    model: /*rootItem.fBoard.listFilm*/ filmBoard.listFilm
                    delegate: filmDelegate
                    highlight: Rectangle{
                        color: "grey"
                        Text {
                            anchors.centerIn: parent
                            //text: "Film " + ((filmBoard.listFilm).get(idListFilm.currentIndex)).name + " selected"
                            color: "red"
                        }

                    }
                    focus: true
                    highlightFollowsCurrentItem: true
                    onCurrentItemChanged: {
                        console.log(idListFilm.currentIndex)
                    }

                }

            }
        }
    }
}
