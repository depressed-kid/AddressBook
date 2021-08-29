import QtQuick 2.12
import QtQuick.Window 2.12
import StyleModule 1.0
import ContactsModule.Impl 1.0
import ComponentsModule.Buttons 1.0
import ComponentsModule.SearchBar 1.0

Window {
	visible: true 
    width: 500
    height: 700
    title: "Address Book"

    Item {
        id: _pageName
        width: parent.width
        height: parent.height / 30
        anchors.topMargin: 50000000


        Text {
            text: qsTr("Conatcst")
            color: "white"
            font.pointSize: 15
            anchors.fill: parent
        }
    }


    SearchBar {
        id: _searchBar
        width: parent.width
        height: parent.height / 10
        anchors.top: _pageName.bottom
    }

    ContactsView {
        id: _view
        anchors.fill: parent
        anchors.topMargin: _searchBar.height + _pageName.height
    }

    AddButton {
        id: _addButton
        width: parent.width / 10
        height:  parent.width / 10
        anchors {
            right: parent.right
            bottom: parent.bottom
            rightMargin: Style.defaultOffset
            bottomMargin: Style.defaultOffset
        }
    }

    Rectangle {
        id: _bg
        z: -100
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }
}
