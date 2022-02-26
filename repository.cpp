#include "repository.h"

repository::repository()
{

}

repository::~repository()
{
    QString connection;
    connection=db.connectionName();
    db.close();
    db=QSqlDatabase();
    db.removeDatabase(connection);
    //db.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug()<<("Disc.....");
}

bool repository::CheckUniqLogin(const QString &login)
{
    if(!connectDB())
    {qDebug()<<"Cannot open database";}
    QSqlQuery query;

    QString db_input = "SELECT COUNT(*) FROM server.people WHERE login='%1'";
    db_input=db_input.arg(login);

    if(!query.exec(db_input))
    {
        qDebug() << "Unable to create a table" << query.lastError();
    }
    int res=0;
    while (query.next())
    {
            res = query.value(0).toInt();
            break;
    }

    if (res>1)
        return false;

    return true;
}

bool repository::Authorization(const QString &login, const QString &pass)
{

}

bool repository::connectDB()
{
    db = QSqlDatabase::addDatabase("QPSQL");

    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");
    if(!db.open())
    {
        qDebug() << "Cannot open database: " << db.lastError();
        return false;
    }
    return true;
}
