#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <QObject>
#include <dbtypes.h>
#include <memory>

namespace db {

// 1. нужно расписать процесс
// 2. напистаь библеотку.
// P.S такая сложность возникает из-за того, что мы пишем целую библеотеку для работы с базой данных

// мы можем вынести насйтроки базы данных в отдельный класс например dbmanager
// он будет брать необходимые настройки конфигурации из файла
// создавать запросы для создания таблиц и так далее

// наверное его будет нужно сделать singleton
// а например класс снизу и класс creeator они как раз будут содержать методыв
// которые соотвествуют их названию

// он просто в connectionmanager сделал функциональность создания, открытия и настройки соединения к базе данных.
// также создание таблиц
// мне нужно просто этот процесс расписать чтобы понять как он работает
// я думаю нужно разделить настройку базы данных, создание соединения. короче запутался.

class Connector
{
public:
    Q_DISABLE_COPY(Connector);
    ~Connector();

    static Connector& instance();
    std::string databasePath() const;
    db::dbtypes::DBState state() const;
    bool isValid() const;

private:
    Connector();

    class DBManagerPrivate;
    std::unique_ptr<DBManagerPrivate> m_d;

};

#endif // CONNECTOR_H


}

