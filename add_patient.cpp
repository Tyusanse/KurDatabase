#include "add_patient.h"
#include "ui_add_patient.h"

add_patient::add_patient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_patient)
{
    ui->setupUi(this);
}

add_patient::~add_patient()
{
    delete ui;
}

void add_patient::on_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query -> prepare("INSERT INTO patient (fio, mob_number)"
                     "VALUES (:fio , :M_number)");
    query -> bindValue(":fio", ui -> lineEdit_3 -> text());
    query -> bindValue(":M_number", ui -> lineEdit -> text());

    QMessageBox* mess = new QMessageBox();

    if(!query -> exec())
    {
        mess -> setText("Запрос составлен неверно");
        mess -> show();
    }

    emit refresh_table();
}
