#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QString>
#include <QTableWidgetItem>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QTableView>
#include <QtWidgets>
#include <QMap>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QLinearGradient>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Ctemp.afficher());
    connect(ui->tableView, SIGNAL(entered(QModelIndex)), this, SLOT(on_tableView_hoveredRow(QModelIndex)));

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

        QString id = model->data(model->index(row, 0)).toString();
        QString dateCommande = model->data(model->index(row, 1)).toString();
        QString etatCommande = model->data(model->index(row, 2)).toString();
        QString prix = model->data(model->index(row, 3)).toString();
        QString pointFidelite = model->data(model->index(row, 4)).toString();

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
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Appel de la fonction de suppression
    bool test = Ctemp.supprimer(id);

    if (test) {
        // Rafraîchissement du modèle pour afficher les données mises à jour
        QSqlQueryModel* model = Ctemp.afficher();  // Supposons que afficher() retourne un modèle
        if (model) {
            ui->tableView->setModel(model);
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
    QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (!nomFichier.isEmpty()) {
        Commande commande;

        // Mettre à jour et récupérer les données de commande
        QSqlQueryModel *model = commande.afficher();

        // Exporter vers PDF
        commande.exporterPDF(nomFichier, model);

        // Libération de mémoire
        delete model;

        QMessageBox::information(this, "Exportation PDF", "Exportation vers PDF réussie !");
    }
}

void MainWindow::on_pushButton_339_clicked() {
    // Perform sorting by date
    QSqlQueryModel* model = Ctemp.trierParDate();

    if (model) {
        // Set the sorted model to tableView_2 in tabTri
        ui->tableView->setModel(model);

        // Switch to the tab containing tableView_2
        ui->tabWidget->setCurrentWidget(ui->tableView);

        QMessageBox::information(this, QObject::tr("Succès"),
                                 QObject::tr("Tri effectué par date du plus proche au plus loin.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("Le tri a échoué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}





void MainWindow::on_statistique_clicked() {
    Commande commande;
    QMap<QString, int> statistiques = commande.getStatistiquesParEtat();

    if (statistiques.isEmpty()) {
        qDebug() << "Aucune donnée pour les statistiques.";
        return;
    }

    // Création de la série pour le graphique
    QPieSeries *series = new QPieSeries();
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        QPieSlice *slice = series->append(it.key() + ": " + QString::number(it.value()), it.value());

        // Alterner entre vert pastel et gris clair
        if (series->slices().size() % 2 == 0) {
            slice->setBrush(QColor(173, 216, 230)); // Gris clair
        } else {
            slice->setBrush(QColor(152, 251, 152)); // Vert pastel
        }

        // Afficher les labels
        slice->setLabelVisible(true);
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes par état");
    chart->setAnimationOptions(QChart::SeriesAnimations);  // Activer les animations

    // Personnaliser le titre
    QFont titleFont;
    titleFont.setPixelSize(20); // Taille du titre
    titleFont.setBold(true);    // Gras
    titleFont.setItalic(false);
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(QColor(152, 251, 152))); // Couleur du titre (vert pastel)

    // Personnaliser les étiquettes
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

    // Basculer automatiquement sur tab_22
    int index = ui->tabWidget->indexOf(ui->tab_22);
    if (index != -1) {
        ui->tabWidget->setCurrentIndex(index);
        qDebug() << "Onglet tab_22 affiché avec le graphique.";
    } else {
        qDebug() << "tab_22 introuvable dans le QTabWidget.";
    }
}


void MainWindow::on_rechercher_clicked()
{
    QString id = ui->lineEdit_272->text().trimmed(); // Suppression des espaces
    QSqlQuery query;

    // Préparation de la requête SQL pour rechercher la commande avec l'ID spécifié
    query.prepare("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {  // Si une commande est trouvée
            QString dateCommande = query.value("dateCommande").toString();
            QString etatCommande = query.value("etatCommande").toString();
            float prix = query.value("prix").toFloat();
            int pointFidelite = query.value("pointFidelite").toInt();

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
    int id = ui->ide->text().toInt(); // Récupérer l'ID de l'utilisateur
    Commande commande;

    if (commande.calculerReductionAvecUpdate(id)) {
        QMessageBox::information(this, "Succès", "Réduction appliquée avec succès.");

        // Recharger le modèle dans tableView
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.exec("SELECT id, dateCommande, etatCommande, prix, pointFidelite FROM commandes");
        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'application de la réduction.");
    }
}













void MainWindow::on_historique_clicked() {
    Commande commande;
    commande.afficherHistorique();
}




