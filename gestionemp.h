#ifndef GESTIONEMP_H
#define GESTIONEMP_H

#include <QMainWindow>
#include "employee.h"
#include "arduino.h"
#include<client.h>
#include "delegatedeuxbouttons.h"
#include <QChartView>
#include "commande.h"
#include <QCalendarWidget>
#include "equipement.h"

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
     QString getEtatCommande(const QString &id);


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
    //-----------------------------------------------------------------------------------------------------------------------------
    //-----------------------------CLIENT--------------------------------------------------------------------------------------------

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

     //-----------------------------Gestion Commande-----------------------------------------
     void on_ajouterCommande_clicked();
     void on_SupprimerCommande_clicked();
     void on_ModifierCommande_clicked();
     void setupConnections();
     void on_TrierCommande_clicked();
     void on_pdfCommande_clicked();
     void on_statistiqueCommande_clicked();
     void on_rechercherCommande_2_clicked();
     void on_calculerReductionCommande_clicked();

     void on_effacerCommande_clicked();
     void on_calendrierCommande_clicked() ;
     void afficherCalendrier();
     void mettreEnEvidenceDates(QCalendarWidget *calendrier);

     void chargerCommandes();
     void on_RetourCommande_clicked();
      void on_tableViewCommande_clicked(const QModelIndex &index);
      //---------------------------------gestion equipement------------------------------------------------
      void on_ajouter_equip_clicked(); // Gère le clic sur le bouton "Ajouter"

      void on_equip_supprimer_clicked(bool checked);
      void on_equip_modifier_clicked();
      void on_equip_valider_clicked();
      void on_equip_trier_clicked();
      //void on_pushButton_exporter_pdf_clicked();
      void on_equip_PDF_clicked();
      void on_equip_Prevoir_clicked();
      void on_equip_Planifier_clicked();
      bool exporterPDF(const QString &nomFichier, QAbstractItemModel *model);
      void on_equip_Recherche_clicked();
      void on_vende_clicked(); // Slot pour afficher les statistiques


      void genererStatistiquesParEtat();
      void on_equip_stat_clicked();
      void on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint);
      void on_equip_arduino_clicked();
      //------------------menu de l'employe---------------------
      void on_pushButton_prod_clicked();
      void showGestionProduitTab();

      void showGestionCommandeTab();
      void on_pushButton_cmd_clicked();

      void showTab5();
      void on_buttonequip_clicked();

      void showTab();
      void on_pushButton_h1_clicked();

      void showClientTab();
      void on_pushButton_client_clicked();
      //menu du client
      void on_bouttonacceuil2_clicked();
      void on_bouttequip2_clicked();
      void on_boucomm2_clicked();
      void on_bprod2_clicked();
      void showTab2();
      void on_bouttonemp2_clicked()  ;
      //menu du produit
      void on_bouttonacceuil3_clicked();
      void on_bequip3_clicked();
      void on_bcomm3_clicked();
      void on_bemp3_clicked();
      void on_bcl3_clicked();
      //menu de la commande
      void on_homeeee_clicked();
      void on_buttongererProduitcom_clicked();
      void on_buttongererequipements4_clicked();
      void on_buttonemp4_clicked();
      void on_buttoncll4_clicked();
      //menu equip
      void on_bouttonacceuil_4_clicked();
      void on_buttongererClient_5_clicked();
      void on_bouttonprod5_clicked();
      void on_btemp5_clicked();
      void on_bouttoncom5_clicked();

  private:
      void updateEtatCycle(QMap<QString, int> statistiques); // Méthode pour mettre à jour le graphique


 private:
    Ui::MainWindow *ui;
    Employee emp;
    Client client;

    void backupToFile(const Employee& employee);
    Arduino *arduino;
    Arduino a;

//------------------------gestion produit---------------------------------------------------
    QSqlQueryModel *model;
    QChartView *chartView = nullptr;
    delegateDeuxBouttons *delegate;
    //Arduino *arduino; // Pointer to Arduino instance
    void sendToArduino(Arduino &arduino, const QString &message); // Declare sendToArduino function
 //---------------------gestion commande---------------------------------------------------
    Commande Ctemp;
    QSqlQueryModel m_previousModel;
    QString m_previousQuery;
   // Arduino *arduino;
    //---------------------------------gestion equipement------------------------------------------------

    Equipement equipement;
    int idActuel;

};


#endif // GESTIONEMP_H
