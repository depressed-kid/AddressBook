import QtQuick 2.12
import StyleModule 1.0

Rectangle {
    color: Style.secondaryColor
    radius: 180
    opacity: _area.containsMouse ? Style.emphasisOpacity : Style.secondaryOpacity


    Text {
        anchors.centerIn: parent
        text: "+"
        color: "white"
        font {
            bold: true
            pointSize: 40

        }
    }

    MouseArea {
        id: _area
        anchors.fill: parent
        onClicked: console.log("Clicked");
        hoverEnabled: true
        cursorShape: Qt.OpenHandCursor
    }
}



