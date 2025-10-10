#include "employeedashboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmployeeDashboard w;
    w.show();
    return a.exec();
}
