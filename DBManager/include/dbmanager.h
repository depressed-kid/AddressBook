#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <dbtypes.h>

// https://github.com/Nintersoft/DBManager/blob/master/sample%20program/v2.0.5.6/DBTest/dbmanager/dbmanager.h

class DBManager
{

public:
    DBManager();
private:

    QString databaseHostName;
    QString databaseNameS;
    QString databaseUserame;
    QString databasePassword;
    QString databaseConnectionName;
    QString databaseConnectionOptions;
    QString databaseTablePrefix;
    db::dbtypes::DBConnectionType databaseConnectionTypeS;
    int databasePort;
};




#endif // DBMANAGER_H
