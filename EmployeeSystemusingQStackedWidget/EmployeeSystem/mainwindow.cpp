#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employeelogin.h"
#include "employeedashboard.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stack = new QStackedWidget(this);
    login = new EmployeeLogin;
    empdashboard = new EmployeeDashboard;

    stack->addWidget(ui->centralwidget);
    stack->addWidget(login);
    stack->addWidget(empdashboard);


    setCentralWidget(stack);

    connect(ui->gotologin, &QPushButton::clicked, this, [this]() {
        stack->setCurrentWidget(login);
    });

    connect(login, &EmployeeLogin::backToWelcome, this, [this]() {
        stack->setCurrentWidget(ui->centralwidget);
    });

    connect(login, &EmployeeLogin::loginSuccessful, this, [=]() {
        stack->setCurrentWidget(empdashboard);
    });
    connect(empdashboard, &EmployeeDashboard::BackToLogin, this, [this](){
        stack->setCurrentWidget(login);
    });

    connect(empdashboard, &EmployeeDashboard::LogoutToWelcome, this, [=](){
        stack->setCurrentWidget(ui->centralwidget);
    });

    stack->setCurrentWidget(ui->centralwidget);




}

MainWindow::~MainWindow()
{
    delete ui;
}
