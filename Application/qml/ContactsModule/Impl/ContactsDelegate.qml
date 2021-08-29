import QtQuick 2.0
import ContactsModule.Base 1.0
import StyleModule 1.0

BaseListDelegate {
    id: root
	Column {
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        Row {
            spacing: Style.smallSpacing
            BaseText {
                font.pointSize: (root.width / 2 + root.height * 5) / 50 || 15
                text: name
            }
            BaseText {
                font.pointSize: (root.width / 2 + root.height * 5) / 50 || 15
                text: surname
            }
        }
        BaseText {
            font.pointSize: (root.width / 2+ root.height * 5) / 50 || 15
            text: "+" + phone
            color: Style.primaryColor
        }
    }

}




