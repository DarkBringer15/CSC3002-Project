#include "homewindow.h"
#include "ui_homewindow.h"
#include "login.h"

homewindow::homewindow(QString *username, QString *Password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homewindow), username(username), Password(Password)
{
    ui->setupUi(this);
    QPixmap logo ("C:/Users/Nick/Documents/Qt Project/LoginPage_1/Assets/the-chinese-university-of-hong-kong-logo-F21185E146-seeklogo.com.png");
    ui->label_pic->setPixmap(logo);
    Login conn;
    if (!conn.connOpen()) {
        ui->label_6->setText("Failed to Connect");
        return;
    } else {
        ui->label_6->setText("Connected");
    }
    ui->label_7->setText(*username);
    ui->label_8->setText(*Password);
    QString name;
    QSqlQuery queries;
    queries.prepare("SELECT * FROM Student WHERE StudentID=:username AND Password=:password");
    queries.bindValue(":username", *username);
    queries.bindValue(":password", *Password);
    if (!queries.exec()) {
        qDebug() << "Failed connecting to database";
    }
    if (queries.next()) {
        name = queries.value("Name").toString();
    }
    ui->label_5->setText("Hello, " + name);
//            ui->label_7->setText(*username);
//            ui->label_8->setText(*Password);
//            int count = 0;
//            QSqlQuery queries;
//            queries.prepare("SELECT * FROM Student WHERE StudentID=:username AND Password=:password");
//            queries.bindValue(":username", *username);
//            queries.bindValue(":password", *Password);
//            if (!queries.exec()) {
//                 qDebug() << "failed Executing sql" << queries.lastError();
//                 return;
//            }
//            while(queries.next()) {
//                count++;
//            }
//            qDebug()<< count;
}

homewindow::~homewindow()
{
    delete ui;
}
