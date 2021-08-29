#ifndef SELECTOR_H
#define SELECTOR_H

#include <QVariantList>
#include "dbtypes.h"
#include "executor.h"

namespace db
{
class Selector
{
public:
   db::dbtypes::DBResult selectAll(const std::string& tableName,
                                std::vector<QVariantList>& returnData);

private:
    Executor executor;
    std::string generateQuery(const std::string& tableName) const;
};
}

#endif // SELECTOR_H
