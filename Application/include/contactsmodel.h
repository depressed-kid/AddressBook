#ifndef CONTACTSMODEL_H
#define CONTACTSMODEL_H
#include <QAbstractListModel>
#include <QObject>
#include <vector>
#include <contact.h>
#include <QHash>
#include <QByteArray>
#include <QString>
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();
    static void registerMe(const std::string& moduleName);
    int rowCount(const QModelIndex& parent = {}) const override;
    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    std::vector<Contact> contacts;
    ContactsReader reader;


    enum ContactRoles {
        NameRole = Qt::UserRole,
        SurnameRole,
        PhoneRole
    };


    bool updateContacts();

};

// классный проект будет сериализация и десериализация с графическим интерфейсом. Можно открывать файл будет определяться тип и разметки определенная
// так же можно как консольной утилитой пользоваться.
// Можно сделать разбиение на два экрана и посмотреть как из json-> преобразуется в бинарник например
// кстати возможно не все получится реализовать потому что чувствуется тут нужно парралельное программирование




#endif // CONTACTSMODEL_H
