#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QMessageBox> //Сообщения о подключении к базе

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

    QMessageBox *mes;

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;
};

#endif // LOGIN_H
