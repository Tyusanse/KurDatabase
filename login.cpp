#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui -> setupUi(this);

    ui -> lineEdit_4 -> setEchoMode(QLineEdit::Password); ///Скрытие символов пароля
    mes = new QMessageBox();
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName(ui -> lineEdit -> text());
    db.setUserName(ui -> lineEdit_2 -> text());
    db.setHostName(ui -> lineEdit_3 -> text());
    db.setPassword(ui -> lineEdit_4 -> text());
    if (!db.open()){
        mes -> setText("Соединение не установлено");
    }
    else{
        mes -> setText("Соединение установлено");
    }

    mes -> show();

}
