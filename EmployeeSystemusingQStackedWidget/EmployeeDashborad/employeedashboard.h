#ifndef EMPLOYEEDASHBOARD_H
#define EMPLOYEEDASHBOARD_H

#include <QMainWindow>
#include<QDate>
#include <QMainWindow>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class EmployeeDashboard;
}
QT_END_NAMESPACE

class EmployeeDashboard : public QMainWindow
{
    Q_OBJECT

public:
    EmployeeDashboard(QWidget *parent = nullptr);
    ~EmployeeDashboard();

public slots:
    void addEmployee();
    void showCurrentEmployee( const QString &id, const QString &ename);
    void updateTimerLabel(const QString &timeText);

private:
    Ui::EmployeeDashboard *ui;
      void clearAll();
};
#endif // EMPLOYEEDASHBOARD_H
