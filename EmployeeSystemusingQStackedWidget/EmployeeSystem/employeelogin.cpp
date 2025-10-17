#include "employeelogin.h"
#include "ui_employeelogin.h"
#include "employeedashboard.h"
#include<QMessageBox>
#include<QTimer>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>

EmployeeLogin::EmployeeLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeLogin)
{
    ui->setupUi(this);
    connect(ui->btn , &QPushButton::clicked, this , &EmployeeLogin::Mybtn);
    connect(ui->backtowelcome ,&QPushButton::clicked,this ,[this](){
        emit backToWelcome();
    });

    timer=new QTimer(this);
    connect(timer, &QTimer::timeout , this ,  &EmployeeLogin::Updater);
    timer->start(1000);
    // qDebug("1");
}

EmployeeLogin::~EmployeeLogin()
{
    // qDebug("2");
    delete ui;
}

void EmployeeLogin::Mybtn()
{
       qDebug() << "Available drivers:" << QSqlDatabase::drivers();
    QString uname=ui->username->text();
    QString pass=ui->lineEdit_2->text();

    if(uname.isEmpty() || pass.isEmpty()){
        QMessageBox::warning(this , "login" ,"userid or password is not found");
        return;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("pixelwisedb");
    db.setPassword("Pwtech@999");
    db.setPort(3306);
    db.setConnectOptions("MYSQL_OPT_SSL_MODE=DISABLED");

    if(!db.open()){
        qDebug()<<"Connection failed"<<db.lastError().text();

    }
    else{
        qDebug()<<"Connection Done";
    }

    QSqlQuery query;
    query.prepare("INSERT INTO emplogin(username , passowrd) VALUES(:username , :passowrd)");
    query.bindValue(":username",uname);
    query.bindValue(":passowrd",pass);

    if(query.exec()){
        QMessageBox::information(this,"success","data stored in database successfully");
    }
    else{
        qDebug()<<"data not stored"<<query.lastError().text();
    }

    QRegularExpression usernameRegex("^[a-zA-Z0-9_]{3,20}$");
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");


    if(uname.isEmpty() || pass.isEmpty()){
        QMessageBox::warning(this,"Input Error","Fields are Empty");
        return;
    }

    if (!usernameRegex.match(uname).hasMatch()) {
        QMessageBox::warning(this, "Error", "Invalid username! (only letters, numbers, underscore, min 3 chars)");
        return;
    }

    if (!passwordRegex.match(pass).hasMatch()) {
        QMessageBox::warning(this, "Error", "Password must be at least 8 chars with uppercase, lowercase, digit, special char.");
        return;
    }

   // EmployeeDashboard *empdashboard=new EmployeeDashboard(this);
   // connect(this, &EmployeeLogin::timerupdated, empdashboard, &EmployeeDashboard::updateTimerLabel);
   // empdashboard->show();

   emit loginSuccessful();
}

void EmployeeLogin::Updater()
{
    QTime time = QTime::currentTime();
    QString TimeText = time.toString("hh::mm::ss");
    ui->timer_label->setText(TimeText);

    emit timerupdated(TimeText);
}

// void EmployeeLogin::backtowelcome(){

// }
