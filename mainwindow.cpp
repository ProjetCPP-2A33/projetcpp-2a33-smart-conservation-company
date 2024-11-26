#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QSqlQuery>
#include <QPdfWriter>
#include <QSqlRecord>
#include <QPainter>
#include <QPageSize>
#include <QSqlError>
#include <QVariant>
#include <QFileDialog>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGraphicsScene>
#include <QPen>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QSqlQueryModel())
    , idActuel(-1) // ID initialisé à -1 (aucun équipement sélectionné)
{
    ui->setupUi(this);



    // Désactiver les champs et le bouton "Valider"
    ui->lineEdit_modif_nom->setEnabled(false);
    ui->lineEdit_modif_type->setEnabled(false);
    ui->lineEdit_modif_date->setEnabled(false);
    ui->lineEdit_modif_etat->setEnabled(false);
    ui->valider_modif->setEnabled(false);

    // Initialiser le QTableView
    model = Equipement::afficher();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow() {
    delete ui;
    delete model;
}

// Bouton Ajouter
void MainWindow::on_ajouter_clicked() {
    // Récupérer les valeurs des QLineEdit
    int id = ui->lineEdit_id->text().toInt(); // Convertir en entier
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    QString date = ui->lineEdit_date->text();
    QString etat = ui->lineEdit_etat->text();

    // Créer un objet Equipement et ajouter à la base
    Equipement equip(id, nom, type, date, etat);
    if (equip.ajouter()) {
        QMessageBox::information(this, "Succès", "Équipement ajouté avec succès.");

        // Mettre à jour le QTableView
        model = Equipement::afficher();
        ui->tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter l'équipement.");
    }
}
// Implémentation de la fonction de suppression


void MainWindow::on_pushButton_supprimer_clicked(bool checked)
{
    // Afficher un QInputDialog pour demander l'ID de l'équipement à supprimer
    bool ok;
    int id = QInputDialog::getInt(this, "Supprimer un équipement", "Entrez l'ID de l'équipement à supprimer :",
                                  0, 0, 100000, 1, &ok);  // Plage d'ID : 0 à 100000

    if (ok) {  // Si l'utilisateur clique sur OK
        // Appeler la méthode supprimer de la classe Equipement avec l'ID saisi
        if (Equipement::supprimer(id)) {
            QMessageBox::information(this, "Succès", "Équipement supprimé avec succès.");

            // Mettre à jour le QTableView pour afficher les équipements restants
            model = Equipement::afficher();
            ui->tableView->setModel(model);
        } else {
            QMessageBox::critical(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        }
    } else {
        // Si l'utilisateur annule la saisie, rien ne se passe
        QMessageBox::information(this, "Annulation", "Suppression annulée.");
    }
}
void MainWindow::on_modifier_clicked() {
    // Demander l'ID de l'équipement à modifier
    bool ok;
    int id = QInputDialog::getInt(this, "Modifier un équipement", "Entrez l'ID de l'équipement à modifier :",
                                  0, 0, 100000, 1, &ok);

    if (ok) {
        // Charger les informations actuelles
        QSqlQuery query;
        query.prepare("SELECT NOM_EQUIP, TYPE, DATE_MAINTENANCE, ETAT FROM equipement WHERE ID_EQUIP = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            // Stocker l'ID actuel
            idActuel = id;

            // Afficher les données dans les QLineEdit
            ui->lineEdit_modif_nom->setText(query.value(0).toString());
            ui->lineEdit_modif_type->setText(query.value(1).toString());
            ui->lineEdit_modif_date->setText(query.value(2).toString());
            ui->lineEdit_modif_etat->setText(query.value(3).toString());

            // Activer les champs et le bouton "Valider"
            ui->lineEdit_modif_nom->setEnabled(true);
            ui->lineEdit_modif_type->setEnabled(true);
            ui->lineEdit_modif_date->setEnabled(true);
            ui->lineEdit_modif_etat->setEnabled(true);
            ui->valider_modif->setEnabled(true);
        } else {
            QMessageBox::critical(this, "Erreur", "Aucun équipement trouvé avec cet ID.");
        }
    } else {
        QMessageBox::information(this, "Annulation", "Modification annulée.");
    }
}
void MainWindow::on_valider_modif_clicked() {
    if (idActuel == -1) {
        QMessageBox::warning(this, "Erreur", "Aucun équipement sélectionné pour modification.");
        return;
    }

    // Récupérer les nouvelles données des QLineEdit
    QString nom = ui->lineEdit_modif_nom->text();
    QString type = ui->lineEdit_modif_type->text();
    QString date = ui->lineEdit_modif_date->text();
    QString etat = ui->lineEdit_modif_etat->text();

    // Vérifier que les champs ne sont pas vides
    if (nom.isEmpty() || type.isEmpty() || date.isEmpty() || etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Mettre à jour les données dans la base
    QSqlQuery query;
    query.prepare("UPDATE equipement SET NOM_EQUIP = :nom, TYPE = :type, DATE_MAINTENANCE = :date, ETAT = :etat WHERE ID_EQUIP = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    query.bindValue(":etat", etat);
    query.bindValue(":id", idActuel);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Équipement modifié avec succès.");

        // Réinitialiser les champs
        ui->lineEdit_modif_nom->clear();
        ui->lineEdit_modif_type->clear();
        ui->lineEdit_modif_date->clear();
        ui->lineEdit_modif_etat->clear();
        ui->lineEdit_modif_nom->setEnabled(false);
        ui->lineEdit_modif_type->setEnabled(false);
        ui->lineEdit_modif_date->setEnabled(false);
        ui->lineEdit_modif_etat->setEnabled(false);
        ui->valider_modif->setEnabled(false);

        // Réinitialiser l'ID actuel
        idActuel = -1;

        // Mettre à jour la vue
        model = Equipement::afficher();
        ui->tableView->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de modifier l'équipement.");
    }
}

void MainWindow::on_trier_clicked() {
    // Récupérer les données triées et les afficher dans le QTableView
    model = Equipement::trierParNom();
    ui->tableView->setModel(model);

    QMessageBox::information(this, "Tri effectué", "Les équipements ont été triés par nom (A-Z).");
}

void MainWindow::on_exporterPDF_clicked() {
    // Ouvrir une boîte de dialogue pour sélectionner le chemin de sauvegarde du PDF
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        // Initialiser un modèle pour récupérer les données de la table `equipement`
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT ID_EQUIP, NOM_EQUIP, TYPE, DATE_MAINTENANCE, ETAT FROM equipement");

        // Vérifier si la table contient des données
        if (model->rowCount() == 0) {
            QMessageBox::warning(this, "Aucune donnée", "Aucun équipement à exporter.");
            delete model; // Libération de la mémoire
            return;
        }

        // Appeler la fonction pour exporter vers PDF
        bool exportSuccess = exporterPDF(nomFichier, model);

        // Libération de mémoire
        delete model;

        // Afficher un message en fonction du succès ou de l'échec
        if (exportSuccess) {
            QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
        } else {
            QMessageBox::critical(this, "Erreur d'exportation", "L'exportation vers PDF a échoué.");
        }
    }
}

bool MainWindow::exporterPDF(const QString &nomFichier, QAbstractItemModel *model) {
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        qDebug() << "Erreur lors de l'initialisation du QPainter pour le PDF.";
        return false;
    }

    // Titre du PDF
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(2000, 1100, "Liste des Équipements");

    // Coordonnées et dimensions des cellules du tableau
    int startX = 200;          // Position X de départ
    int startY = 1800;         // Position Y de départ
    int cellWidth = 1500;      // Largeur des cellules
    int cellHeight = 450;      // Hauteur des cellules

    // En-têtes des colonnes
    QStringList headers = {"ID Equip", "Nom Equip", "Type", "Date Maintenance", "État"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    // Dessiner les en-têtes
    for (int col = 0; col < headers.size(); ++col) {
        QRect headerRect(startX + col * cellWidth, startY, cellWidth, cellHeight);
        painter.drawRect(headerRect); // Dessiner les bordures
        painter.drawText(headerRect, Qt::AlignCenter, headers[col]); // Écrire le texte
    }

    // Données de la table `equipement`
    painter.setFont(QFont("Arial", 10));
    int rowCount = model->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white; // Couleur alternée pour les lignes

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);         // Remplir la cellule avec une couleur de fond
            painter.drawText(cellRect, Qt::AlignCenter, data); // Écrire les données
            painter.drawRect(cellRect);                 // Dessiner les bordures de la cellule
        }
    }

    painter.end();
    return true; // Exportation réussie
}



void MainWindow::on_pushButtonPrevoir_clicked() {
    // Récupérer l'ID depuis le champ `lineEditPrevoir`
    bool conversionOk;
    int idEquipement = ui->lineEditPrevoir->text().toInt(&conversionOk);

    if (!conversionOk || idEquipement <= 0) {
        QMessageBox::warning(this, "Entrée invalide", "Veuillez entrer un ID valide pour l'équipement.");
        return;
    }

    // Appeler la fonction de prévision
    QString resultat = Equipement::prevoirUsure(idEquipement);

    // Afficher le résultat
    if (resultat.startsWith("Erreur")) {
        QMessageBox::critical(this, "Erreur", resultat);
    } else {
        QMessageBox::information(this, "Prévision d'usure", resultat);
    }
}

void MainWindow::on_pushButtonPlanifier_clicked() {
    bool ok;
    int id_equip = ui->lineEditPlanifier->text().toInt(&ok);  // Convertir l'ID de l'équipement en entier

    if (!ok || id_equip <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement valide.");
        return;
    }

    Equipement equipement;
    QString resultat = equipement.planifierMaintenance(id_equip);  // Appel de la méthode pour planifier la maintenance

    // Affichage du résultat dans un message box
    QMessageBox::information(this, "Planification de la maintenance", resultat);
}

void MainWindow::on_pushButtonRecherche_clicked() {
    // Récupérer l'ID depuis lineEdit
    QString idText = ui->lineEdit_recherche->text();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID.");
        return;
    }

    int id = idText.toInt();

    // Appeler la fonction de recherche
    Equipement equipement;
    QString resultat = equipement.rechercherParId(id);

    // Afficher le résultat dans un QMessageBox
    QMessageBox::information(this, "Résultat de la recherche", resultat);
}

void MainWindow::on_pushButton_statistiques_clicked() {
    // Appeler la fonction getStatistiques pour récupérer les résultats
    QString statistiques = Equipement::getStatistiques();

    // Afficher les résultats dans une QMessageBox
    QMessageBox::information(this, "Statistiques des équipements", statistiques);
}
