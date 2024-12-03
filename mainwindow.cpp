#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "arduino.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>//connection avec BD
#include <QSqlError>
#include <QString>
#include <QTableWidgetItem>//cellule dans tableWidget
#include <QRegularExpression>
#include <QPdfWriter>//generer en pdf
#include <QPainter>//forme graphique
#include <QFileDialog>//choisir fich
#include <QTableView>
#include <QtWidgets>
#include <QMap>
#include <QStandardItemModel>//pour afficher tableau ou liste
#include <QVBoxLayout>
#include <QtCharts/QChartView>//graphique
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QLinearGradient>
#include <QCalendarWidget>
#include <QDialog>//boite de dialogue pour interagir avec utilisateur
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlRecord>//ligne de base
#include <QTextCharFormat>//style de text

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), arduino(new Arduino(this)) {
    ui->setupUi(this);

    // Configuration initiale de l'interface
    ui->tableView->setModel(Ctemp.afficher()); // Charger les données dans le `tableView`

    // Connecter le signal du `tableView` à une fonction
    connect(ui->tableView, SIGNAL(entered(QModelIndex)), this, SLOT(on_tableView_hoveredRow(QModelIndex)));

    // Vérification du nombre de lignes dans le modèle
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->tableView->model());
    if (model) {
        qDebug() << model->rowCount() << "lignes dans le modèle.";
    }

    // Configuration de la communication avec Arduino
    if (!arduino->connectToArduino()) {
        qDebug() << "Erreur : Impossible de connecter à Arduino.";
    } else {
        qDebug() << "Arduino connecté avec succès.";
    }

    // Ajouter les connexions spécifiques à votre projet
    setupConnections();
}



MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onTableViewClicked(const QModelIndex &index) {
    if (!index.isValid())
        return;

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel *>(ui->tableView->model());
    if (model) {
        int row = index.row();

        // Extraire les données de la ligne sélectionnée
        QString id = model->data(model->index(row, 0)).toString();
        QString dateCommande = model->data(model->index(row, 1)).toString();
        QString etatCommande = model->data(model->index(row, 2)).toString();
        QString prix = model->data(model->index(row, 3)).toString();
        QString pointFidelite = model->data(model->index(row, 4)).toString();

        // Déboguer les valeurs extraites
        qDebug() << "Ligne sélectionnée:" << row;
        qDebug() << "ID : " << id;
        qDebug() << "Date : " << dateCommande;
        qDebug() << "État : " << etatCommande;
        qDebug() << "Prix : " << prix;
        qDebug() << "Points fidélité : " << pointFidelite;

        // Remplir les QLineEdits avec les valeurs extraites
        ui->idInput->setText(id);
        ui->dateInput->setText(dateCommande);
        ui->etatInput->setText(etatCommande);
        ui->prixInput->setText(prix);
        ui->fideliteInput->setText(pointFidelite);
    }
}


void MainWindow::setupConnections() {
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::onTableViewClicked);
}

void MainWindow::on_pushButton_331_clicked() {
    int id = ui->idInput->text().toInt();

    // Retrieve the date from QLineEdit, then convert to QDate using the specified format
    QString dateCommandeStr = ui->dateInput->text();
    QDate dateCommande = QDate::fromString(dateCommandeStr, "dd/MM/yyyy");

    // Validate the date format
    if (!dateCommande.isValid()) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("La date de commande est invalide ou mal formatée."));
        return;
    }

    QString etatCommande = ui->etatInput->text();
    float prix = ui->prixInput->text().toFloat();
    int pointFidelite = ui->fideliteInput->text().toInt();

    // Create the Commande object with the formatted date string
    Commande c(id, dateCommandeStr, etatCommande, prix, pointFidelite);
    bool test = c.ajouter();

    if (test) {
        ui->tableView->setModel(Ctemp.afficher());
        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Ajout effectué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("L'ajout a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}




void MainWindow::on_pushButton_332_clicked() {
    int id = ui->idInput->text().toInt();
    QString dateCommande = ui->dateInput->text();
    QString etatCommande = ui->etatInput->text();
    float prix = ui->prixInput->text().toFloat();
    int pointFidelite = ui->fideliteInput->text().toInt();

    // Vérification de la validité de l'ID
    if (id <= 0) {
        QMessageBox::warning(this, tr("Erreur de saisie"), tr("L'ID de la commande doit être valide."));
        return;
    }

    Commande cmdToUpdate(id, dateCommande, etatCommande, prix, pointFidelite);
    bool exists = cmdToUpdate.idExiste(id);
    if (!exists) {
        QMessageBox::warning(this, tr("Erreur"), tr("Cette commande n'existe pas."));
        return;
    }

    // Modifier uniquement les champs modifiés
    bool test = cmdToUpdate.modifier();
    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("La commande a été modifiée avec succès."));
        ui->tableView->setModel(cmdToUpdate.afficher());

    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("La modification de la commande a échoué."));
    }
}


void MainWindow::on_pushButton_336_clicked() {
    int id = ui->supp->text().toInt();

    // Vérification de l'ID
    if (id == 0) {//vide ou non numerique
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Appel de la fonction de suppression
    bool test = Ctemp.supprimer(id);

    if (test) {// verification du suppresiion
        // Rafraîchissement du modèle pour afficher les données mises à jour
        QSqlQueryModel* model = Ctemp.afficher();  // Supposons que afficher() retourne un modèle
        if (model) {// model valide
            ui->tableView->setModel(model);// affichage tableView bel mise a
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Suppression effectuée.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);

        } else {
            QMessageBox::critical(this, QObject::tr("Erreur"),
                                  QObject::tr("Échec du rafraîchissement de la table.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("La suppression a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pdf_clicked()
{
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");//dialog yekhtar win ihot fich ***nomfich chemin
    if (!nomFichier.isEmpty()) {
        Commande commande;

        // Mettre à jour et récupérer les données de commande
        QSqlQueryModel *model = commande.afficher();

        // Exporter vers PDF
        commande.exporterPDF(nomFichier, model);
        //commande.addToHistory("Exportation des commandes vers PDF", 0);

        // Libération de mémoire
        delete model;

        QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
    }
}

void MainWindow::on_pushButton_339_clicked() {

    QSqlQueryModel* model = Ctemp.trierParDate();//resultat de tri effectué au pointeur
    if (model) {// le tri effectué model n'est pas null

        ui->tableView->setModel(model);// lie le model a table view


        ui->tabWidget->setCurrentWidget(ui->tableView);// afichage tableView sur tableWidget

        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Tri effectué par date du plus proche au plus loin.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("Le tri a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}






void MainWindow::on_statistique_clicked() {
    // Récupérer les statistiques à partir de la commande
    Commande commande;
    QMap<QString, int> statistiques = commande.getStatistiquesParEtat();//ihezehom ml fonction commande ihotehom fl map

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }

    // Création de la série pour le graphique
    QPieSeries *series = new QPieSeries();//dsign cerculaire
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(it.value()), it.value());// ajouter chaque etat comme une tranche

        // Alterner entre vert pastel et gris clair
        if (series->slices().size() % 2 == 0) {
            slice->setBrush(QColor(173, 216, 230)); // Gris clair
        } else {
            slice->setBrush(QColor(152, 251, 152)); // Vert pastel
        }

        // Afficher les labels essem o 9adeh pour chaque tranche
        slice->setLabelVisible(true);
    }

    // Création du graphique cerculaire
    QChart *chart = new QChart();// objet pour graphique
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);  // Activer les animations

    // Personnaliser le titre taille style couleur
    QFont titleFont;
    titleFont.setPixelSize(20); // Taille du titre
    titleFont.setBold(true);    // Gras
    titleFont.setItalic(false);
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(QColor(152, 251, 152))); // Couleur du titre (vert pastel)

    // Personnaliser les étiquettes text affiche sur chaque tranche
    QFont labelFont;
    labelFont.setPixelSize(16); // Taille des labels
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelFont(labelFont);
        slice->setLabelBrush(QBrush(QColor(152, 251, 152))); // Couleur des labels (vert pastel)
    }

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Nettoyer l'ancien contenu de verticalLayout_2
    QLayoutItem *item;
    while ((item = ui->verticalLayout_2->takeAt(0)) != nullptr) {
        delete item->widget(); // Supprimer le widget
        delete item;           // Supprimer l'item
    }

    // Ajouter le graphique au layout
    ui->verticalLayout_2->addWidget(chartView);

    // Rafraîchir le graphique sans quitter l'onglet
    ui->tabWidget->setCurrentIndex(ui->tabWidget->indexOf(ui->tab_22));

    // Afficher un message dans le debug pour confirmer la mise à jour
    qDebug() << "Statistiques mises à jour et graphique actualisé.";
}




void MainWindow::on_rechercher_clicked()
{
    QString id = ui->lineEdit_272->text().trimmed(); //dakhel comme text  Suppression des espaces
    QSqlQuery query;//préparer et exécuter des requêtes SQL

    // Préparation de la requête SQL pour rechercher la commande avec l'ID spécifié
    query.prepare("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id);//t3awedh ":id" bel valeur reel de id

    if (query.exec()) {
        if (query.next()) {  // Si une commande est trouvée passer com 2
            QString dateCommande = query.value("dateCommande").toString();// recuperer de de base et convertion
            QString etatCommande = query.value("etatCommande").toString();// recuperer de de base et convertion
            float prix = query.value("prix").toFloat();// recuperer de de base et convertion
            int pointFidelite = query.value("pointFidelite").toInt();// recuperer de de base et convertion

            // Remplissage des champs avec les informations récupérées
            ui->idInput->setText(id);
            ui->dateInput->setText(dateCommande);
            ui->etatInput->setText(etatCommande);
            ui->prixInput->setText(QString::number(prix, 'f', 2));
            ui->fideliteInput->setText(QString::number(pointFidelite));

            // Rendre les champs en lecture seule
            ui->idInput->setReadOnly(true);
            ui->dateInput->setReadOnly(true);
            ui->etatInput->setReadOnly(true);
            ui->prixInput->setReadOnly(true);
            ui->fideliteInput->setReadOnly(true);

            // Afficher un message de succès
            QMessageBox::information(this, tr("Recherche"), tr("Commande trouvée avec succès."));
        } else {
            // Afficher un message si aucune commande n'est trouvée avec cet ID
            QMessageBox::information(this, tr("Recherche"), tr("Aucune commande trouvée avec cet ID."));
        }
    } else {
        // Afficher un message en cas d'erreur de base de données
        QMessageBox::warning(this, tr("Erreur"), tr("Échec de la recherche dans la base de données : ") + query.lastError().text());
    }
}

void MainWindow::on_calculerReduction_clicked() {
    // Récupérer le texte du champ 'ide'
    QString idText = ui->ide->text();

    // Vérifier si le champ est vide
    if (idText.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID !");
        return; // Arrêter l'exécution si le champ est vide
    }

    // Convertir le texte en entier
    bool conversionOk;
    int id = idText.toInt(&conversionOk);

    // Vérifier si l'ID est un entier valide
    if (!conversionOk || id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return; // Arrêter l'exécution si la conversion échoue
    }

    Commande commande;

    // Appeler la méthode pour appliquer la réduction
    if (commande.calculerReductionAvecUpdate(id)) {
        QMessageBox::information(this, "Succès", "Réduction appliquée avec succès.");

        // Recharger les données dans tableView
        QSqlQueryModel *model = new QSqlQueryModel();//afficher sur tableView
        QSqlQuery query;//préparer et exécuter des requêtes SQL
        query.exec("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes");
        model->setQuery(std::move(query));//trnsfere le model
        ui->tableView->setModel(model);//associé model au tableView
        ui->tableView->resizeColumnsToContents();//ajustertaimlle de colone
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'application de la réduction.");
    }
}


void MainWindow::on_effacer_clicked()
{
    ui->idInput->clear();
    ui->dateInput->clear();
    ui->etatInput->clear();
    ui->prixInput->clear();
    ui->fideliteInput->clear();

}
void MainWindow::on_calendrier_clicked() {
    // Sauvegarder l'état actuel de la table (les commandes affichées)


    afficherCalendrier();
}

void MainWindow::afficherCalendrier() {
    // Créer un dialogue contenant le calendrier
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Calendrier");
    dialog->resize(400, 450);

    // Ajouter un calendrier au dialogue (sans limitation de dates)
    QCalendarWidget *calendrier = new QCalendarWidget(dialog);
    calendrier->setGridVisible(true);
    calendrier->setGeometry(10, 10, 380, 300);//position et taille du calendrier dans dialoqgue

    // Mettre en évidence les dates ayant des commandes
    mettreEnEvidenceDates(calendrier);//colore en jaune

    // Bouton "Fermer" pour fermer le calendrier
    QPushButton *btnFermer = new QPushButton("Fermer", dialog);
    btnFermer->setGeometry(150, 350, 100, 30);//position et taille

    // Connecter le bouton "Fermer" pour fermer le dialogue et réinitialiser les commandes dans le QTableView
    connect(btnFermer, &QPushButton::clicked, this, [=]() {
        // Restaurer l'état de la table avec les commandes précédemment affichées
        //restaurerEtatTableView();
        dialog->accept(); // Fermer le dialogue
    });

    // Connecter la sélection d'une date pour afficher les commandes
    connect(calendrier, &QCalendarWidget::clicked, this, [=](const QDate &date) {//consol marbout b date selectionné
        qDebug() << "Date sélectionnée dans le calendrier:" << date.toString("dd/MM/yyyy");

    });

    // Afficher le dialogue
    dialog->exec();

    // Nettoyer la mémoire après fermeture
    dialog->deleteLater();
}

void MainWindow::mettreEnEvidenceDates(QCalendarWidget *calendrier) {
    QTextCharFormat format;//format de style
    format.setBackground(Qt::yellow); // Couleur de fond jaune pour les dates importantes

    // Requête pour récupérer les dates uniques des commandes
    QSqlQuery query("SELECT DISTINCT dateCommande FROM commandes");
    while (query.next()) {
        QString dateStr = query.value(0).toString();
        QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");  // Utiliser le bon format de date
        if (date.isValid()) {
            qDebug() << "Date avec commande trouvée:" << date.toString("yyyy-MM-dd");
            calendrier->setDateTextFormat(date, format); // Appliquer le format à la date bel jaune
        } else {
            qDebug() << "Date invalide:" << dateStr;
        }
    }
}











/*void MainWindow::on_historique_clicked() {
    Commande commande;
    commande.afficherHistorique();
}*/



/*void MainWindow::on_calendrier_clicked() {
    afficherCalendrier();
    // Appel à la fonction qui gère le calendrier
}



void MainWindow::afficherCalendrier() {
    // Créer un dialogue contenant le calendrier
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Calendrier");
    dialog->resize(400, 450);

    // Ajouter un calendrier au dialogue
    QCalendarWidget *calendrier = new QCalendarWidget(dialog);
    calendrier->setGridVisible(true);
    calendrier->setMinimumDate(QDate(2000, 1, 1));
    calendrier->setMaximumDate(QDate::currentDate());
    calendrier->setGeometry(10, 10, 380, 300);

    // Mettre en évidence les dates ayant des commandes
    mettreEnEvidenceDates(calendrier);

    // Bouton "Fermer" pour fermer le calendrier
    QPushButton *btnFermer = new QPushButton("Fermer", dialog);
    btnFermer->setGeometry(150, 350, 100, 30);

    // Connecter le bouton "Fermer" pour fermer le dialogue
    connect(btnFermer, &QPushButton::clicked, this, [=]() {
        // Ne pas réinitialiser le modèle, juste fermer le calendrier
        dialog->accept();
    });

    // Connecter la sélection d'une date pour afficher les commandes
    connect(calendrier, &QCalendarWidget::clicked, this, [=](const QDate &date) {
        qDebug() << "Date sélectionnée dans le calendrier:" << date.toString("dd-MM-yyyy");
        afficherCommandesParDate(date); // Fonction pour afficher les commandes correspondant à une date
    });

    // Afficher le dialogue
    dialog->exec();

    // Nettoyer la mémoire après fermeture
    dialog->deleteLater();
}


void MainWindow::mettreEnEvidenceDates(QCalendarWidget *calendrier) {
    QTextCharFormat format;
    format.setBackground(Qt::yellow); // Couleur de fond jaune pour les dates importantes

    // Requête pour récupérer les dates uniques des commandes
    QSqlQuery query("SELECT DISTINCT dateCommande FROM commandes");
    while (query.next()) {
        QString dateStr = query.value(0).toString();
        QDate date = QDate::fromString(dateStr, "dd/MM/yyyy");  // Utiliser le bon format de date
        if (date.isValid()) {
            qDebug() << "Date avec commande trouvée:" << date.toString("yyyy-MM-dd");
            calendrier->setDateTextFormat(date, format); // Appliquer le format à la date
        } else {
            qDebug() << "Date invalide:" << dateStr;
        }
    }
}

void MainWindow::afficherCommandesParDate(const QDate &date) {
    // Convertir la date sélectionnée en chaîne avec le format "yyyy-MM-dd"
    QString dateStr = date.toString("dd/MM/yyyy");  // Ajustez le format ici

    // Affichage de la date sélectionnée pour le diagnostic
    qDebug() << "Date sélectionnée:" << dateStr;

    // Initialisation du modèle pour afficher les commandes
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Requête SQL pour récupérer les commandes correspondant à la date sélectionnée
    query.prepare("SELECT * FROM commandes WHERE dateCommande = :date");
    query.bindValue(":date", dateStr);  // Lier la date au paramètre dans la requête

    // Afficher la requête SQL pour vérifier qu'elle est correcte
    qDebug() << "Requête SQL exécutée:" << query.lastQuery();

    // Exécuter la requête
    if (query.exec()) {
        // Vérifier si des résultats ont été trouvés
        if (query.size() > 0) {
            // Déplacer la requête dans le modèle
            model->setQuery(std::move(query));  // Déplacer pour éviter la copie
            ui->tableView->setModel(model); // Afficher les résultats dans le QTableView

            qDebug() << "Commandes affichées dans le QTableView.";
        } else {
            qDebug() << "Aucune commande trouvée pour cette date.";
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError();
    }
}




void MainWindow::afficherToutesLesCommandes() {
    // Cette fonction va réafficher toutes les commandes dans le QTableView
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query("SELECT * FROM commandes");  // Requête pour récupérer toutes les commandes
    query.exec();

    // Déplacer la requête dans le modèle
    model->setQuery(std::move(query)); // Déplacer pour éviter la copie
    ui->tableView->setModel(model);  // Afficher toutes les commandes dans le QTableView
}*/



/*void MainWindow::afficherCommandesParDate(const QDate &date)
{
    QString dateStr = date.toString("dd/MM/yyyy");  // Changer le format de date pour "yyyy-MM-dd" pour correspondre à la base de données
    qDebug() << "Date sélectionnée:" << dateStr;

    // Créer un nouveau modèle à chaque fois
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM commandes WHERE dateCommande = :date");
    query.bindValue(":date", dateStr);  // Utilisation du format ISO "yyyy-MM-dd"

    // Exécuter la requête
    if (query.exec()) {
        if (query.size() > 0) {
            model->setQuery(query);  // Associer la requête au modèle
            ui->tableView->setModel(model); // Afficher les commandes correspondant à la date
        } else {
            qDebug() << "Aucune commande trouvée pour cette date.";
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError();
    }
}

void MainWindow::sauvegarderEtatTableView()
{
    // Sauvegarder la requête SQL utilisée dans le modèle actuel
    QSqlQueryModel *currentModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    if (currentModel) {
        m_previousQuery = currentModel->query().lastQuery();  // Sauvegarder la requête SQL
        qDebug() << "Requête sauvegardée:" << m_previousQuery;
    }
}

void MainWindow::restaurerEtatTableView()
{
    // Créer un nouveau modèle basé sur la requête SQL sauvegardée
    if (!m_previousQuery.isEmpty()) {
        QSqlQuery query;
        query.exec(m_previousQuery);  // Exécuter la requête sauvegardée

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);  // Appliquer la requête au modèle

        ui->tableView->setModel(model);  // Restaurer le modèle dans le QTableView
        qDebug() << "Modèle restauré avec la requête:" << m_previousQuery;
    }
}*/



void MainWindow::on_sendButton_clicked() {
    QString idCommande = ui->lineEdit->text(); // Lire l'ID de commande
    if (idCommande.isEmpty()) {
        qDebug() << "ID de commande vide.";

        // Afficher un message d'erreur si l'ID est vide
        QMessageBox::warning(this, "Erreur", "L'ID de commande est vide. Veuillez entrer un ID valide.");
        return;
    }

    // Connexion à la base de données
    QSqlQuery query;//Creation requette sql
    query.prepare("SELECT etatCommande FROM commandes WHERE id = :id");
    query.bindValue(":id", idCommande); //associer id a la requette

    if (query.exec() && query.next()) {// si commande trouver
        QString etatCommande = query.value(0).toString(); // Récupérer l'état
        qDebug() << "État envoyé à Arduino :" << etatCommande;

        // Afficher un message d'information
        QMessageBox::information(this, "État de la commande", "L'état de la commande est : " + etatCommande);

        // Envoi de l'état à Arduino
        arduino->sendToArduino(etatCommande);
    } else {
        qDebug() << "Commande introuvable.";

        // Afficher un message d'erreur si la commande n'est pas trouvée
        QMessageBox::critical(this, "Erreur", "Commande introuvable. Veuillez vérifier l'ID.");
    }
}













