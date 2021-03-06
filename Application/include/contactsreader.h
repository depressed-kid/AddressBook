#ifndef CONTACTSREADER_H
#define CONTACTSREADER_H

#include <vector>
#include <memory>
#include "contact.h"

namespace db
{
class Processor;
}

class ContactsReader
{
public:
    ContactsReader();
    std::pair<bool,
              std::vector<Contact>> requestContactsBrowse();
    ~ContactsReader();

private:
    std::unique_ptr<db::Processor> m_dbProcessor;
};


#endif // CONTACTSREADER_H
