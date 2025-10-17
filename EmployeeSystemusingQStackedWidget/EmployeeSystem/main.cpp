#include "mainwindow.h"

#include <QApplication>
#include<QSqlDatabase>
#include<QSqlError>
#include<QMessageBox>
#include<QDebug>
bool COnnectToDatabase()
{

     QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setDatabaseName("pixelwisedb");
    db.setPassword("Pwtech@999");
    db.setPort(3306);

    if(!db.open()){
        qDebug()<<"Connection failed"<<db.lastError().text();

    }
    else{
        qDebug()<<"Connection Done";
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
