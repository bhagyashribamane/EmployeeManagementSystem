#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString& path) {
    m_db=QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName("empdata");
    m_db.setUserName("root");
    m_db.setPassword("Pwtech@999");
    m_db.setPort(3306);


    if(!m_db.open()){
        qDebug()<<"Error:: database connection failed"<<m_db.lastError().text();
    }
    else{
        qDebug()<<"Connection . ok";
    }


    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXIST Employee("
               " id int PRIMARY KEY,"
               "name VARCHAR(200) NOT NULL,"
               "age INT,"
               "salary DOUBLE)");
}

bool DatabaseManager::isOpen() const
{
return m_db.isOpen();
}


bool DatabaseManager::addEmployee(const QString &name, int age, double salary)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Employee(name,age,salary) VALUES(:name, :age, :salary)");
    query.bindValue(":name",name);
    query.bindValue(":age",age);
    query.bindValue(":salary",salary);

    if(!query.exec()){
        qDebug()<<"Add Employee Error"<<query.lastError().text();
        return false;
    }
    return true;
}
void DatabaseManager::listEmployee()
{
    QSqlQuery query("select id ,name , age , salary from Employee");
    while(query.next()){
        int id = query.value(0).toInt();
        QString name=query.value(1).toString();
        int age=query.value(2).toInt();
        double salary=query.value(3).toDouble();
        qDebug()<<id<<name<<age<<salary;
    }
}

bool DatabaseManager::updateEmployee(int id, const QString &name, int age, double salary)
{
    QSqlQuery query;
    query.prepare("UPDATE employee SET name=:name, age=:age, salary=:salary WHERE id=:id");
    query.bindValue(":name", name);
    query.bindValue(":age", age);
    query.bindValue(":salary", salary);
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "updateEmployee error:" << query.lastError().text();
        return false;
    }
    return true;
}
// bool DatabaseManager::updateEmployee(int id, QString &name, int age, double salary){

// }

bool DatabaseManager::deleteEmployee(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Employee WHERE id=:id");
    query.bindValue(":id",id);
    if(!query.exec()){
        qDebug()<<"updateEmployee"<<query.lastError().text();
        return false;
    }
    return true;
}



