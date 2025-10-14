#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
class DatabaseManager
{
public:
    explicit DatabaseManager(const QString& path);
    bool isOpen() const;
    bool addEmployee(const QString& name ,int age , double salary);
    void listEmployee();
    bool updateEmployee(int id, const QString &name, int age, double salary);

    bool deleteEmployee(int id);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
