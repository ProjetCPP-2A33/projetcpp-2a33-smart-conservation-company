#ifndef GESTIONEMP_H
#define GESTIONEMP_H

#include <QMainWindow>
#include "employee.h"
#include "arduino.h"
#include<client.h>
#include "delegatedeuxbouttons.h"
#include <QChartView>
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
void on_tableView_employee_clicked(const QModelIndex &index);
    void on_pushButton_suivant_clicked();
    void handleArduinoData(QString data);
    void on_buttonForgotPassword2_clicked();
    void on_pushButton_fermer_clicked();
    void on_yourPasswordButton_clicked();
    void on_verifyButton_clicked(); // Slot pour le bouton "Verifier" void handleArduinoData(QString data); // Slot pour gérer les données reçues de l'Arduino
    //--------------------------------------
    //-----------------------------CLIENT--------------------------------------------------------------------------------------------
    void showClientTab();
    void on_pushButton_client_clicked();
    //****************************************************************************************************************************

    void on_pushButton_ajouter2_clicked();
    //supprimer----

    void on_pushButton_supprimer_2_clicked();
    //modifier----
    void on_pushButton_modifier_2_clicked();
     //SUPPEMENTAIRE------
    void on_tableView_clients_clicked(const QModelIndex &index);
    void on_pushButton_effacer_clicked();
    //tri
    void  on_pushButton_tri_nom_clicked();
    //pdf-----------
    void on_pushButton_pdf2_clicked();
    //rapport--------
    void on_pushButton_rapport_clicked();
    //recherche par id
    void rechercherClientParID();
    //statistique-----------
    void on_pushButton_stat_clicked();
    void on_pushButton_closeStackedWidget_stat_clicked();
    void genererStatistiquesParDate();
    void fermerStackedWidgetStat();
    //sms
    void envoyerSMS(const QString &telephone, const QString &message);
    //rapport
    void genererStatistiquesParAdresse();
    //excel
    void on_pushButton_excel_clicked();
    //generer le rapport
    void generateActivityReport();
    void addRowToTable(const QString &label, const QString &value);
    void setupChart(QSqlQueryModel *regionModel);
    void on_pushButton_pdfrapportgeo_2_clicked();
     void clearFields();

     //-----------------------Gestion Produit---------------------------------------------

     void on_buttongererProduit_clicked();
     void on_buttongererClient_clicked();
     void on_bouttonajouterproduit_clicked();
     void on_bouttonacceuil_clicked();
     void on_bouttonafficherproduits_clicked();
     void on_bouttonmodifierproduit_clicked();
     void on_bouttonstatistiques_clicked();
     void afficherstatistiquesproduits();
     void on_bouttonconfirmerajout_clicked();
     void on_ajouterProduit_clicked();
     void on_menutri_currentIndexChanged(int index);
     void on_bouttonconfirmersupprimerproduit_clicked();
     void on_modifierProduit_clicked();
     void on_pushButton_7_clicked();
     void onModifierClicked(int ligne);
     void onSupprimerClicked(int ligne);
     void on_bouttonpdffile_clicked();
     void historique(const QString &typeevenement, const QString &nomproduit, const QString &extrainfo);
     void on_bouttonhistorique_clicked();
     void loadHistoriqueFile();
     void on_bouttonnotification_clicked();
     void verifierproduitexpire();
     void on_bouttonrecherche_clicked();
     void readSerialData(); // Déclaration de readSerialData
     void onReceiveData(const QByteArray &data);  // Slot to receive data
     void onMessageReceived(const QByteArray &data);
     void on_sendButton_clicked();
     void on_searchButton_clicked();


 private:
    Ui::MainWindow *ui;
    Employee emp;
    Client client;
    void backupToFile(const Employee& employee);
    Arduino *arduino;

//------------------------gestion produit---------------------------------------------------
    QSqlQueryModel *model;
    QChartView *chartView = nullptr;
    delegateDeuxBouttons *delegate;
    //Arduino *arduino; // Pointer to Arduino instance
    void sendToArduino(Arduino &arduino, const QString &message); // Declare sendToArduino function
};


#endif // GESTIONEMP_H
