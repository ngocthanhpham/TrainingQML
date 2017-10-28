/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

// plugin for Message type
import chat.message 1.0

Page {
    id: root

    property string inConversationWith
    // c++ model<QAbstractTableModel> for conversion
    property variant conversionModel
    // c++ model<QList<QObject*>> for users
    property variant userList

    // signal for sending message
    signal sendMessage(var message)

    header: ChatToolBar {
        ToolButton {
            contentItem: Image {
                fillMode: Image.Pad
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "qrc:/chat/Image/menu.png"
            }
            text: qsTr("Back")
            anchors.left: parent.left
//            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            onClicked:
            {
                drawer.open()
            }
        }
//        Image
//        {
//            id: userImage
//            source: "qrc:/chat/Image/Hans_Gude@2x.png"
//        }

        Label {
            id: pageTitle
            text: user.name
            font.pixelSize: 20
            anchors.centerIn: parent
        }
    }

    // panel for list of users
    Drawer
    {
        id: drawer
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height

        ListView {
            id: listViewDrawer

            focus: true
            currentIndex: -1
            anchors.fill: parent
            model: userList
            delegate: Rectangle
            {
                width: parent.width
                height: 35
                Label
                {
                    anchors.centerIn: parent
                    text: modelData.name
                }
                color: index%2 === 0 ? "grey" : "silver"
            }
        }

    }

    ColumnLayout {
        anchors.fill: parent

        ListView {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: pane.leftPadding + messageField.leftPadding
            displayMarginBeginning: 40
            displayMarginEnd: 40
            verticalLayoutDirection: ListView.BottomToTop
            spacing: 12

            model: conversionModel
            delegate: Column {
                anchors.right: sentByMe ? parent.right : undefined
                spacing: 6

                readonly property bool sentByMe: model.name === user.name

                Row {
                    id: messageRow
                    spacing: 6
                    anchors.right: sentByMe ? parent.right : undefined

                    Image {
                        id: avatar
//                        source: !sentByMe ? "qrc:/" + model.author.replace(" ", "_") + ".png" : ""
                        source: !sentByMe ? "qrc:/chat/Image/Hans_Gude@2x.png" : "qrc:/chat/Image/Albert_Einstein@2x.png"
                    }

                    Rectangle {
                        width: Math.min(messageText.implicitWidth + 24, listView.width - avatar.width - messageRow.spacing)
                        height: messageText.implicitHeight + 24
                        color: sentByMe ? "lightgrey" : "steelblue"

                        Label {
                            id: messageText
//                            text: model.message
                            text:model.content
                            color: sentByMe ? "black" : "white"
                            anchors.fill: parent
                            anchors.margins: 12
                            wrapMode: Label.Wrap
                        }
                    }
                }

                Label {
                    id: userName
                    text: model.name//Qt.formatDateTime(model.timestamp, "d MMM hh:mm")
                    color: "lightgrey"
                    anchors.right: sentByMe ? parent.right : undefined
                }

                Label {
                    id: timestampText
                    text: model.timestamp//Qt.formatDateTime(model.timestamp, "d MMM hh:mm")
                    color: "lightgrey"
                    anchors.right: sentByMe ? parent.right : undefined
                }
            }

            ScrollBar.vertical: ScrollBar {}
        }

        Pane {
            id: pane
            Layout.fillWidth: true

            // C++ Class that register like QML type
            Message
            {
                id: sendingMsg
                name: user.name
                owner: user.name
                content: messageField.text
                timestamp: ""
                join: true

            }

            RowLayout {
                width: parent.width

                TextArea {
                    id: messageField
                    Layout.fillWidth: true
                    placeholderText: qsTr("Compose message")
                    wrapMode: TextArea.Wrap

                    Keys.onTabPressed: {
                        var currentDate = new Date();
                        sendingMsg.timestamp = currentDate.toLocaleString("en-US")
                        sendMessage(sendingMsg)
                        messageField.text = ""
                        console.log("send")
                    }
                }

                Button {
                    id: sendButton
                    text: qsTr("Send")
                    enabled: messageField.length > 0
                    onClicked: {
//                        listView.model.sendMessage(inConversationWith, messageField.text);
                        var currentDate = new Date();
                        sendingMsg.timestamp = currentDate.toLocaleString("en-US")
                        sendMessage(sendingMsg)
                        messageField.text = ""
                    }
                }
            }
        }
    }
}

