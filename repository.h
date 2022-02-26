#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QDate>

class repository
{
public:
    repository();
    ~repository();
    bool CheckUniqLogin(const QString &login);
    bool Authorization(const QString &login, const QString &pass);
private:
    QSqlDatabase db;
    bool connectDB();
};

#endif // REPOSITORY_H
