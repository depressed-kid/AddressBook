#include "contactsreader.h"
#include "processor.h"
#include "dbtypes.h"
#include <iterator>


ContactsReader::ContactsReader()
    : m_dbProcessor {new db::Processor{}}
{
}

ContactsReader::~ContactsReader()
{
}

std::vector<Contact> transform(const std::vector<db::dbtypes::DBEntry>& source)
{
    std::vector<Contact> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const db::dbtypes::DBEntry& entry) {
        return Contact {entry[1].toString(), entry[2].toString(), entry[3].toString(), entry[0].toInt()};
    });
    return target;
}

std::pair<bool, std::vector<Contact>> ContactsReader::requestContactsBrowse()
{
    db::dbtypes::DBResult result;
    std::vector<db::dbtypes::DBEntry> entries;
    std::tie(result, entries) = m_dbProcessor->requestTableData (db::dbtypes::DBTables::Contacts);

    return std::make_pair(result == db::dbtypes::DBResult::OK,
                          transform(entries));
}


