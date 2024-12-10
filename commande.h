#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>

class Commande {
private:
    int id;
    QString dateCommande;
    QString etatCommande;
    float prix;
    int pointFidelite;
    QTableView* m_tableView;
    QList<QString> historyList;






public:
    Commande() {}
    Commande(int id,  QString dateCommande, QString etatCommande, float prix, int pointFidelite);
    Commande(QTableView* tableView);


    int getId() const;
    QString getDateCommande() const;
    QString getEtatCommande() const;
    float getPrix() const;
    int getPointFidelite() const;


    void setId(int id);
    void setDateCommande( QString dateCommande);
    void setEtatCommande(QString etatCommande);
    void setPrix(float prix);
    void setPointFidelite(int pointFidelite);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id  );
    bool idExiste(int id);
    bool modifier();
    void on_tableView_hoveredRow(const QModelIndex &index);

    QSqlQueryModel* trierParDate();
    QMap<QString, int> getStatistiquesParEtat();



    void exporterPDF(const QString &nomFichier, QAbstractItemModel *model);

    bool calculerReductionAvecUpdate(int id);
    void writeHistoryToFile(const QString &fileName);
    void addToHistory(const QString &action, int idCommande = 0);
    void afficherHistorique();










};

#endif // COMMANDE_H
