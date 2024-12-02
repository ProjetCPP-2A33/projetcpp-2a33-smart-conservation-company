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

#include <QVBoxLayout>
#include "arduino.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new QSqlQueryModel())
    , idActuel(-1) // ID initialisé à -1 (aucun équipement sélectionné)
{
    ui->setupUi(this);
    int ret = arduino.connect_arduino();
    if (ret == 0) {
        qDebug() << "Arduino connecté sur le port :" << arduino.getarduino_port_name();
    } else if (ret == 1) {
        qDebug() << "Erreur : Impossible d'ouvrir le port série.";
    } else {
        qDebug() << "Erreur : Arduino non détecté.";
    }
    // Vérification de la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "La connexion à la base de données a échoué.";
    } else {
        qDebug() << "Connexion à la base de données réussie.";
    }
    setWindowTitle("Gestion des équipements");



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

void MainWindow::genererStatistiquesParEtat()
{
    QSqlQuery query;
    query.prepare("SELECT ETAT, COUNT(*) AS nombre_equipements FROM EQUIPEMENT GROUP BY ETAT");

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL : " << query.lastError();
        QMessageBox::critical(this, "Erreur", "La requête SQL a échoué. Vérifiez votre base de données.");
        return;
    }

    if (!query.next()) {
        QMessageBox::information(this, "Aucune donnée", "Aucune donnée à afficher pour les statistiques.");
        return;
    }

    // Créer une série pour le diagramme en secteurs
    QPieSeries *series = new QPieSeries();
    do {
        QString etat = query.value("ETAT").toString();
        int nombreEquipements = query.value("nombre_equipements").toInt();

        // Générer une couleur aléatoire pour chaque tranche
        QColor randomColor(rand() % 256, rand() % 256, rand() % 256);

        QPieSlice *slice = series->append(etat + ": " + QString::number(nombreEquipements), nombreEquipements);
        slice->setLabelVisible(true);
        slice->setLabelPosition(QPieSlice::LabelOutside);
        slice->setBrush(randomColor);  // Appliquer la couleur aléatoire
    } while (query.next());

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des équipements par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Créer une vue pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un bouton "Fermer"
    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet(
        "QPushButton {"
        "background-color: #f0f0f0;"
        "font-size: 14px;"
        "padding: 5px 10px;"
        "}"
        );

    connect(closeButton, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget_stat->hide();
    });

    // Créer une nouvelle page pour le QStackedWidget
    QWidget *statPage = new QWidget();
    QVBoxLayout *pageLayout = new QVBoxLayout(statPage);
    pageLayout->addWidget(chartView);
    pageLayout->addWidget(closeButton);

    // Supprimer les anciennes pages du QStackedWidget
    while (ui->stackedWidget_stat->count() > 0) {
        QWidget *widgetToRemove = ui->stackedWidget_stat->widget(0);
        ui->stackedWidget_stat->removeWidget(widgetToRemove);
        widgetToRemove->deleteLater();
    }

    // Ajouter la nouvelle page au QStackedWidget
    ui->stackedWidget_stat->addWidget(statPage);

    // Afficher la nouvelle page
    ui->stackedWidget_stat->setCurrentWidget(statPage);
    ui->stackedWidget_stat->show();
}
// Connecter cette fonction au bouton "pushButton_stat"
void MainWindow::on_pushButton_stat_clicked()
{
    genererStatistiquesParEtat();
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

void MainWindow::updateEtatCycle(QMap<QString, int> statistiques)
{
    int total = 0;
    for (auto count : statistiques.values()) {
        total += count; // Calcul du total des équipements
    }

    if (total == 0) {
        qDebug() << "Aucun équipement trouvé pour les statistiques.";
        return;
    }

    // Accéder à la scène actuelle
    QGraphicsScene *scene = ui->graphicsView->scene();
    if (!scene) {
        scene = new QGraphicsScene();
        ui->graphicsView->setScene(scene);
    } else {
        scene->clear();
    }

    int radius = 100;  // Rayon du cercle
    int centerX = 150; // Centre X
    int centerY = 150; // Centre Y

    qreal startAngle = 90; // Angle de départ

    // Générer les arcs pour chaque état
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QString etat = it.key();
        int count = it.value();

        qreal angleSpan = 360.0 * count / total; // Portion de l'angle

        QPainterPath path;
        path.moveTo(centerX, centerY);
        path.arcTo(centerX - radius, centerY - radius, 2 * radius, 2 * radius, startAngle, -angleSpan);

        QGraphicsPathItem *arc = scene->addPath(path, QPen(Qt::black), QBrush(Qt::blue));
        if (etat == "bon état") arc->setBrush(Qt::green);
        else if (etat == "état moyen") arc->setBrush(Qt::yellow);
        else if (etat == "état mauvais") arc->setBrush(Qt::red);

        // Ajouter le pourcentage
        QString percentageText = QString::number((count * 100.0) / total, 'f', 1) + "%";
        QGraphicsTextItem *text = new QGraphicsTextItem(etat + ": " + percentageText);
        text->setFont(QFont("Arial", 10, QFont::Bold));
        text->setDefaultTextColor(Qt::black);
        text->setPos(centerX + radius * qCos(qDegreesToRadians(startAngle - angleSpan / 2)) - text->boundingRect().width() / 2,
                     centerY - radius * qSin(qDegreesToRadians(startAngle - angleSpan / 2)) - text->boundingRect().height() / 2);
        scene->addItem(text);

        startAngle -= angleSpan; // Ajuster l'angle de départ pour le prochain segment
    }

    ui->graphicsView->setScene(scene);
}

void MainWindow::on_pushButton_stats_clicked()
{
    Equipement equipement;
    QMap<QString, int> statistiques = equipement.getEtatStatistics();

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }

    updateEtatCycle(statistiques); // Mettre à jour le graphique
}




void MainWindow::on_graphicsView_rubberBandChanged(const QRect &viewportRect, const QPointF &fromScenePoint, const QPointF &toScenePoint)
{

}

void MainWindow::on_Button_Arduino_clicked()
{
    QString id_equipement = ui->lineEdit_Arduino->text();
    if (id_equipement.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID d'équipement.");
        return;
    }

    // Récupération de l'état de l'équipement à partir de la base de données
    QSqlQuery query;
    query.prepare("SELECT ETAT FROM equipement WHERE ID_EQUIP = :id");
    query.bindValue(":id", id_equipement);

    if (query.exec() && query.next()) {
        QString etat = query.value(0).toString();

        QByteArray command;
        if (etat == "bon etat") {
            command = "buzzer_on\n"; // Commande pour activer le buzzer une fois
        } else if (etat == "etat moyen") {
            // Envoyer deux commandes pour deux bips
            command = "buzzer_on\nbuzzer_on\n";
        } else if (etat == "etat mauvais") {
            // Envoyer trois commandes pour trois bips
            command = "buzzer_on\nbuzzer_on\nbuzzer_on\n";
        } else {
            QMessageBox::information(this, "État inconnu", "L'état de l'équipement n'est pas reconnu.");
            return;
        }

        // Envoi de la commande à l'Arduino
        arduino.write_to_arduino(command);
    } else {
        QMessageBox::warning(this, "Erreur", "Équipement non trouvé.");
    }
}



