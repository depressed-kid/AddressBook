import QtQuick 2.12
import StyleModule 1.0

Item {

    Rectangle {
        color: "gray"
        radius: 10

        anchors {
            margins: Style.defaultOffset
            fill: parent
        }

        Rectangle {
            id: _searchIcon
            width: parent.width * 0.08
            height: parent.height
            color: "gray"
            radius: 10

            Rectangle {
                color:  Style.secondaryColor
                width: 10
                height: 10
                anchors.centerIn: parent
            }
        }


        Rectangle {
            id: _searchText
            width: parent.width - _searchIcon.width
            height: parent.height
            anchors.left: _searchIcon.right
            color: "gray"
            radius: 10

            TextInput {
                text: qsTr("Search")
                color:  Style.secondaryColor
                anchors.fill: parent
                maximumLength: 20
                onTextEdited: console.log(text)

//                MouseArea {
//                    id: _area
//                    anchors.fill: parent
//                    onTextEdited: console.log("Clicked");
//                    hoverEnabled: true
//                    cursorShape: Qt. IBeamCursor
//                }


            }



        }

    }




}




