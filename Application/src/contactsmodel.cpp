#include "contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{
        const bool updateResult {updateContacts()};
        if (!updateResult) {
            qWarning() << "Update contacts failed!";
        }
}

bool ContactsModel::updateContacts()
{
    bool requestResult {false};
    std::vector<Contact> contactsResult;
    std::tie(requestResult, contactsResult) = reader.requestContactsBrowse();

    if (requestResult) {
        contacts.swap(contactsResult);
        emit dataChanged(createIndex(0, 0), createIndex(contacts.size(), 0));
    }

    return requestResult;
}




int ContactsModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(contacts.size());
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneRole] = "phone";
    return roles;
}

QVariant ContactsModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index)) {
        return {};
    }

    const Contact& contact = contacts.at(index.row());

    switch (role) {
        case ContactRoles::NameRole: {
            return QVariant::fromValue(contact.getName());
        }
        case ContactRoles::SurnameRole: {
            return QVariant::fromValue(contact.getSurname());
        }
        case ContactRoles::PhoneRole: {
            return QVariant::fromValue(contact.getPhone());
        }
        default: {
            return {};
        }
    }
}

void ContactsModel::registerMe(const std::string& moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}
