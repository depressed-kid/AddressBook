#include "connector.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>


namespace db {

using namespace dbtypes;

namespace
{
    class DBCloser {
    public:
        void operator() (QSqlDatabase* db) {
            db->close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        }
    };
}

// может в этом и есть разница на котороую я на толкнулся между d-pointer и bridge паатерном. В первом случае у нас есть два класса, и мы внутри одного закрывает указатель на другой
// а в этом случае мы внутри класса также содержим указатель но указатель указывает на класс который мы определим внутри этого класса. у нас 1 класс внутри себя прячет другой класс
// типо это одно и тоже просто по разному реализовано?
// вот сейчас я использую d-pointer реализацию. но если я вынесу создание базы данных в отедьльный файл то реализация чуть изменится и будет bridge???
// по факту тут просто название хуевое, DBManagerPrivate это просто класс который представляет собой класс отвечающий за соединение.
// так как соединение может быть разным мы скрываем имплементацю за поинтером?
class Connector::DBManagerPrivate {
public:
    std::unique_ptr<QSqlDatabase, DBCloser> m_database;
    std::string m_dbPath;
    DBState m_state {DBState::OK};
    bool m_isValid {true};

    bool setUp();
    bool setUpWorkspace();
    bool setUpTables();

    void setIsValid(bool isValid);
};

// constructor
Connector::Connector()
    : m_d {new DBManagerPrivate {}}
{
    const bool setupResult {m_d->setUp()};
    m_d->setIsValid(setupResult);
}

// destructor
Connector::~Connector()
{
}

// singleton init
Connector& Connector::instance()
{
    static Connector instance {};
    return instance;
}

std::string Connector::databasePath() const
{
    return m_d->m_dbPath;
}

DBState Connector::state() const
{
    return m_d->m_state;
}

bool Connector::isValid() const
{
    return m_d->m_isValid && m_d->m_database->isValid();
}



// set up connection to database
bool Connector::DBManagerPrivate::setUp()
{
    // set up driver which will be used to connection to db
    const QString driver {"QSQLITE"};

    // check is driver abailiable
    if (!QSqlDatabase::isDriverAvailable(driver))
    {
        m_state = DBState::ERROR_NO_DRIVER;
        qWarning() << "Driver " << driver << " is not available.";
        return false;
    }

    // set up the directory for stroing databse files
    if (!setUpWorkspace())
    {
        m_state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed!";
        return false;
    }

    // add new db to the list of dbs connectios
    auto* db = new QSqlDatabase {QSqlDatabase::addDatabase(driver)};
    // give unuqie ptr new resourse
    m_database.reset(db);
    m_database->setDatabaseName(QString::fromStdString(m_dbPath));

    qDebug() << "Database name: " << m_database->databaseName();

    // new db connection
    if (!m_database->open())
    {
        m_state = DBState::ERROR_OPENING;
        qCritical() << "Error in opening DB " << m_database->databaseName()
                   << " reason: " <<  m_database->lastError().text();
        return false;
    }

    return setUpTables();
}

// вот это я вижу смысл вынести в отдельный класс.
// потому что как понял этот класс содержит connection к базе данных.
// но почему то у  этого класса есть функция для настройки конекта к базе данных, мне кажется это не совсем гуд
// на мой взгляд, должен быть класс который содержит все необходимые настройки для создания базы данных, которые он берет или из аргументов командой строки
// или из файла.
// далее должен быть класс connector который содержит методы для установления соединения, с уже приконфигурированными настройками, а не делать их тут
bool Connector::DBManagerPrivate::setUpWorkspace()
{
    const QString databaseName {"ContactsDB"};
    // location where we can write files
    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    // get full path where we can store our database
    m_dbPath = fullPath.toStdString();

    QDir dbDirectory {location};
    if (!dbDirectory.exists())
    {
        const bool creationResult {dbDirectory.mkpath(location)};
        qWarning() << "DB directory not exist, creating result: "
                   << creationResult;
    }

    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}


bool Connector::DBManagerPrivate::setUpTables()
{
    bool result {true};

    std::vector<QSqlQuery> creationQueries = {
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS Contacts"
            "("
            "Name TEXT,"
            "Surname INTEGER,"
            "PhoneNumber TEXT,"
            "UNIQUE(Name, Surname)"
            ")"
        }
    };

    for (auto& query : creationQueries)
    {
        if (!query.exec())
        {
            result = false;
            m_state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason: "
                       << query.lastError();
        }
        else
        {
            qWarning() << "Table successfully created! Query: \n" << query.lastQuery();
        }
    }

    return result;
}

void Connector::DBManagerPrivate::setIsValid(bool isValid)
{
    m_isValid = isValid;
}









}

