#ifndef EXECUTOR_H
#define EXECUTOR_H
#include <QMap>
#include <QDebug>
#include <QSqlQuery>
#include "connector.h"

namespace db {

class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<db::dbtypes::DBResult, QSqlQuery> execute(const std::string& queryText, const QVariantList& args = {});

private:
    Connector& connection;

};


}



#endif // EXECUTOR_H
