import QtQuick 2.0
import ContactsModule.Base 1.0
import Contacts 1.0

BaseListView {
    id: root

//    model: 	ListModel {
//        ListElement {
//            firstname: "Bill"
//            surname: "Smith"
//            phoneNumber: "555 3264"
//        }
//        ListElement {
//            firstname: "John Brown"
//            surname: "Smith"
//            phoneNumber: "555 8426"
//        }
//        ListElement {
//            firstname: "Sam Wise"
//            surname: "Smith"
//            phoneNumber: "555 0473"
//        }
//    }
    model: ContactsModel {}

    delegate: ContactsDelegate {
        width: root.width
        height: root.height/8
    }
}
