#include <QCoreApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseManager dbmanager("empdata");

    if (dbmanager.isOpen()) {
        dbmanager.addEmployee("Aaae", 25, 45000.0);
        dbmanager.addEmployee("Bbbbbbb", 30, 52000.0);

        qDebug() << "\n--- Employee List ---";
        dbmanager.listEmployee();

        qDebug() << "\n--- Update Employee ID 1 ---";
        dbmanager.updateEmployee( 1, QString("Alic"), 26, 48000.0);
        dbmanager.listEmployee();

        qDebug() << "\n--- Delete Employee ID 2 ---";
        dbmanager.deleteEmployee(2);
        dbmanager.listEmployee();

    }
    return a.exec();
}
