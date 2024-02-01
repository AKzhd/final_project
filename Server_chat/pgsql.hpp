#ifndef PGSQL_H
#define PGSQL_H

#include <QMessageBox>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


inline bool createConnection()
{ QSqlDatabase    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);
    db.setHostName("127.0.0.1");
    if (!db.open()){
        QMessageBox::warning(0,"Error",db.lastError().text());
        return false;
            }
    else
    {
        QMessageBox::information(0,"Success","The connection to the database is established");
                return true;
    }
}

inline bool createTables()
{
QSqlQuery query;
query.exec("CREATE TABLE users("
           "id serial PRIMARY KEY,"
           "login VARCHAR(255) NOT NULL UNIQUE,"
           "name VARCHAR(255),"
           "password VARCHAR(255))");


query.exec("CREATE TABLE messages("
           "id serial PRIMARY KEY,"
           "sender VARCHAR(255),"
           "name VARCHAR(255),"
           "recipient VARCHAR(255),"
           "message TEXT)");


return (1);

}

#endif // PGSQL_H
