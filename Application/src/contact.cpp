#include "contact.h"

Contact::Contact(QString name, QString surname, QString phone, db::dbtypes::DBIndex id)
    : name {std::move(name)}, surname {std::move(surname)}, phone {std::move(phone)}, id {std::move(id)}
{

}

QString Contact::getName() const
{
    return name;
}

QString Contact::getSurname() const
{
    return surname;
}

QString Contact::getPhone() const
{
    return phone;
}
