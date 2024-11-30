#ifndef GESTIONEMP_H
#define GESTIONEMP_H

#include <QMainWindow>
#include "employee.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pb_pdf_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_stats_clicked();
    void on_pushButton_10_clicked();
    void on_buttonWelcome_clicked();
    void on_buttonBackup_clicked();

    void on_pushButton_suivant_clicked();
    void handleArduinoData(QString data);
    void on_buttonForgotPassword2_clicked();
    void on_pushButton_fermer_clicked();
    void on_yourPasswordButton_clicked();
    void on_verifyButton_clicked(); // Slot pour le bouton "Verifier" void handleArduinoData(QString data); // Slot pour gérer les données reçues de l'Arduino
private:
    Ui::MainWindow *ui;
    Employee emp;
    void backupToFile(const Employee& employee);
    Arduino *arduino;
};


#endif // GESTIONEMP_H
