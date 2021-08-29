#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "executor.h"
#include "dbtypes.h"

namespace db
{
class Manipulator
{
public:
    std::pair<dbtypes::DBResult,
                int> insertRow(const std::string& tableName, const QVariantList& rowData);

private:
    Executor m_executor;
    std::string generateBindString(size_t paramCount) const;
    std::string generateInsertQuery(const std::string& tableName, size_t paramCount) const;
    std::string generateSetString(const QVector<QString>& columns, const QVariantList& values) const;
};
}

#endif // MANIPULATOR_H






