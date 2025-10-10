#include "employeedashboard.h"
#include "ui_employeedashboard.h"
#include<QDebug>
#include<QString>
#include<QTime>
#include<QMessageBox>

EmployeeDashboard::EmployeeDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EmployeeDashboard)
{
    ui->setupUi(this);


    connect(ui->BtnEmployee, &QPushButton::clicked, this , &EmployeeDashboard::addEmployee);
    ui->tableWidget->setColumnCount(5);
    QStringList hLabels;
    hLabels<<" Employee Id"<<"Company Name" <<"Employee name" <<"Joining date" <<"Designation";
    ui->tableWidget->setHorizontalHeaderLabels(hLabels);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

EmployeeDashboard::~EmployeeDashboard()
{
    delete ui;
}

void EmployeeDashboard::addEmployee()
{
    QString id=ui->lineEdit_empid->text();
    QString cname=ui->lineEdit_2Cname->text();
    QString ename=ui->lineEdit_3EName->text();
    QString post=ui->lineEdit_5Designation->text();

    QDate jdate = ui->dateEdit->date();
    QString jdateStr = jdate.toString("yyyy-MM-dd");


    if(id.isEmpty() || cname.isEmpty() || ename.isEmpty() || post.isEmpty()){
        QMessageBox::warning(this, "Input Error" , "Please fill the data");
        return;
    }
    if(!ui->tableWidget->findItems(id, Qt::MatchExactly).isEmpty()){
        QMessageBox::warning(this, "Input error","EMployee id already exists");
        return;
    }

    int row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row , 0, new QTableWidgetItem(id));
    ui->tableWidget->setItem(row, 1,new QTableWidgetItem(cname));
    ui->tableWidget->setItem(row , 2 , new QTableWidgetItem(ename));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(jdateStr));
    ui->tableWidget->setItem(row , 4, new QTableWidgetItem(post));

    clearAll();
    showCurrentEmployee(id,ename);
}

void EmployeeDashboard::showCurrentEmployee(const QString &id, const QString &ename)
{
    QString text="Logged in-\nID-"+ id+"\nName-"+ename;
    ui->labelcurrentemp->setText(text);
}

void EmployeeDashboard::updateTimerLabel(const QString &timeText)
{
 ui->TimerLabel->setText(timeText);
}

void EmployeeDashboard::clearAll()
{
    ui->lineEdit_empid->clear();
    ui->lineEdit_2Cname->clear();
    ui->lineEdit_3EName->clear();
    ui->lineEdit_5Designation->clear();
}
