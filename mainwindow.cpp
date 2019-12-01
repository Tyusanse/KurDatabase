#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    logwin = new login();
    logwin -> show();

}

void MainWindow::on_pushButton_clicked()
{
    model = new QSqlQueryModel();
    model -> setQuery("SELECT * FROM patient");

    model -> setHeaderData(0,Qt::Horizontal, "Номер пациента");
    model -> setHeaderData(1,Qt::Horizontal, "ФИО");
    model -> setHeaderData(2,Qt::Horizontal, "Номер телефона");

    ui -> tableView -> setModel(model);
    ui -> tableView -> resizeColumnsToContents();
    ui -> tableView -> show();
}

void MainWindow::on_pushButton_2_clicked()
{
    add_pat = new add_patient();
    connect(add_pat, SIGNAL(refresh_table()),this, SLOT(obr_ref_table()));
    add_pat -> show();
}

void MainWindow::obr_ref_table()
{
    on_pushButton_clicked();
}
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int temp_num;
    temp_num = ui -> tableView -> model() -> data(ui -> tableView -> model() -> index(index.row(), 0)).toInt();

    ui -> lineEdit_4 -> setText(QString::number(temp_num));

    QSqlQuery *query = new QSqlQuery();
    query -> prepare("SELECT fio, mob_number FROM patient WHERE id=:id");
    query -> bindValue(":id", temp_num);

    if(query -> exec())
    {
        query -> next();
        ui -> lineEdit -> setText(query -> value(0).toString());
        ui -> lineEdit_2 -> setText(query -> value(1).toString());

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQuery * query = new QSqlQuery();
    query -> prepare("UPDATE patient SET fio=?, mob_number=? WHERE id=?");
    query -> bindValue(0,ui-> lineEdit -> text());
    query -> bindValue(1,ui-> lineEdit_2 -> text());
    query -> bindValue(2,ui-> lineEdit_4 -> text());

    query -> exec();
    on_pushButton_clicked();
}

void MainWindow::on_pushButton_4_clicked()
{
    QSqlQuery * query = new QSqlQuery();
    query -> prepare("DELETE FROM patient WHERE id=?");
    query -> bindValue(0,ui-> lineEdit_4 -> text());

    query -> exec();
    on_pushButton_clicked();
}
