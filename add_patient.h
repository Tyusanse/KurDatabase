#ifndef ADD_PATIENT_H
#define ADD_PATIENT_H

#include <QWidget>
#include<QMessageBox>
#include<QSqlQuery>

namespace Ui {
class add_patient;
}

class add_patient : public QWidget
{
    Q_OBJECT

public:
    explicit add_patient(QWidget *parent = 0);
    ~add_patient();

private slots:
    void on_pushButton_clicked();

signals:
    void refresh_table();

private:
    Ui::add_patient *ui;
};

#endif // ADD_PATIENT_H
