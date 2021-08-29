#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include "dbtypes.h"

class Contact
{
public:
    Contact() = default;
    Contact(QString name,  QString surname, QString phone, db::dbtypes::DBIndex id);
    QString getName() const;
    QString getSurname() const;
    QString getPhone() const;

private:
    QString name;
    QString surname;
    QString phone;
    db::dbtypes::DBIndex id;
};



#endif // CONTACT_H
