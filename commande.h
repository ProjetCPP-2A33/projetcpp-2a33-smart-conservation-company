#ifndef COMMANDE_H
#define COMMANDE_H//empeche fichier soit inclus plusieurs fois
#include <QString>
#include <QDate>
#include <QSqlQuery>//exécuter des requêtes SQL pour interagir avec une base de données.
#include <QSqlQueryModel>//QTableView
#include <QTableView>// Fournit un widget pour afficher des données sous forme de tableau
#include <QStandardItemModel>//Manipule des données sous forme de tableaux, listes.

class Commande {
private:
    int id;
    QString dateCommande;
    QString etatCommande;
    float prix;
    int pointFidelite;
    QTableView* m_tableView;//pointeur pointe sur   tableView mt3 les commandes ajoutés
    QList<QString> historyList;// liste fih l'historique ( chaine de caractére )






public:
    Commande() {}  // Constructeur par défaut
    Commande(int id,  QString dateCommande, QString etatCommande, float prix, int pointFidelite);
    Commande(QTableView* tableView);// constructeur pour initialiser le tabView

    // Getters
    int getId() const;
    QString getDateCommande() const;
    QString getEtatCommande() const;
    float getPrix() const;
    int getPointFidelite() const;

    // Setters
    void setId(int id);
    void setDateCommande( QString dateCommande);
    void setEtatCommande(QString etatCommande);
    void setPrix(float prix);
    void setPointFidelite(int pointFidelite);

    bool ajouter();
    QSqlQueryModel* afficher();//retourne requette sql affiche donner sur tableView
    bool supprimer(int id  );
    bool idExiste(int id);// si existe ou non besh najem nml modification
   bool modifier();
    void on_tableView_hoveredRow(const QModelIndex &index);

   QSqlQueryModel* trierParDate();// pointeur sql puis afficher dans tableView
    QMap<QString, int> getStatistiquesParEtat();// compter combien de commande


    void exporterPDF(const QString &nomFichier, QAbstractItemModel *model);

    bool calculerReductionAvecUpdate(int id);
    void writeHistoryToFile(const QString &fileName);
   void addToHistory(const QString &action, int idCommande = 0);
    void afficherHistorique();








};

#endif // COMMANDE_H
