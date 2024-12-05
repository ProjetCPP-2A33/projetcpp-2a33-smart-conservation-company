#ifndef GESTIONEMPLOYEE_H
#define GESTIONEMPLOYEE_H

#include <QMainWindow>
#include "employee.h"
#include "arduino.h"
//#include "ui_gestionemployee.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class GestionEmployee;
}
QT_END_NAMESPACE

class GestionEmployee : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionEmployee(QWidget *parent = nullptr);
    ~GestionEmployee();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    //void on_pb_pdf_clicked();
    void on_pushButton_pdf_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_stats_clicked();
    void on_pushButton_11_clicked();
    void on_buttonWelcome_clicked();
    void on_buttonBackup_clicked();
    void on_pushButton_suivant_clicked();
    void handleArduinoData(QString data);
    void on_buttonForgotPassword2_clicked();
    void on_pushButton_fermer_clicked();
    void on_yourPasswordButton_clicked();
    void on_verifyButton_clicked();

    void on_buttonHome_clicked();
    void on_buttonEmployee_clicked();
private slots:
    void on_tableView_employee_clicked(const QModelIndex &index);
void on_buttonClient_clicked();
    void on_buttonProduct_clicked();
void on_buttonOrder_clicked();
    void on_buttonEquipment_clicked();
private:
    Ui::GestionEmployee *ui;
    Employee emp;
    void backupToFile(const Employee& employee);
    Arduino *arduino;
    QSqlDatabase db;
};

#endif // GESTIONEMPLOYEE_H
