#ifndef EMPLOYEELOGIN_H
#define EMPLOYEELOGIN_H

#include <QMainWindow>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class EmployeeLogin;
}
QT_END_NAMESPACE

class EmployeeLogin : public QMainWindow
{
    Q_OBJECT

public:
    EmployeeLogin(QWidget *parent = nullptr);
    ~EmployeeLogin();
public slots:
    void Mybtn();
    void Updater();

signals:
    void timerupdated(const QString &timeText);
    void loginSuccessful();
    void backToWelcome();

private:
    Ui::EmployeeLogin *ui;
    QTimer *timer;
};
#endif // EMPLOYEELOGIN_H
