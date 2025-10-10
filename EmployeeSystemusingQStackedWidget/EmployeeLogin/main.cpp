#include "employeelogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmployeeLogin w;
    w.show();
    return a.exec();
}
