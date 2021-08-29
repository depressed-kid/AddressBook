#ifndef DBMAPPER_H
#define DBMAPPER_H


#include "dbtypes.h"

namespace db
{
static const std::map<dbtypes::DBTables, std::string> tableMapper {
    {dbtypes::DBTables::Contacts, "Contacts"}
};

static const std::map<std::string, std::string> tablesMapping = {
    {"Contacts", "Name, Surname, PhoneNumber"},
};
}








#endif // DBMAPPER_H














