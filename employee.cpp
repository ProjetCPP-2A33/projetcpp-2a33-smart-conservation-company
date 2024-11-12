#include "employee.h"
#include <QDebug>
#include <QSqlError>
#include "employee.h"
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPageSize>
using namespace std;
// Default Constructor
Employee::Employee() {}

// Parameterized Constructor
Employee::Employee(int id, QString nom, QString prenom, QString login, QString password, QString telephone, QString poste, QString disponibilite, QString heureTravail)
    : id(id), nom(nom), prenom(prenom), login(login), password(password), telephone(telephone), poste(poste), disponibilite(disponibilite), heureTravail(heureTravail) {}

// Getters
int Employee::getID() const { return id; }
QString Employee::getNom() const { return nom; }
QString Employee::getPrenom() const { return prenom; }
QString Employee::getLogin() const { return login; }
QString Employee::getPassword() const { return password; }
QString Employee::getTelephone() const { return telephone; }
QString Employee::getPoste() const { return poste; }
QString Employee::getDisponibilite() const { return disponibilite; }
QString Employee::getHeureTravail() const { return heureTravail; }

// Setters
void Employee::setID(int id) { this->id = id; }
void Employee::setNom(const QString &nom) { this->nom = nom; }
void Employee::setPrenom(const QString &prenom) { this->prenom = prenom; }
void Employee::setLogin(const QString &login) { this->login = login; }
void Employee::setPassword(const QString &password) { this->password = password; }
void Employee::setTelephone(const QString &telephone) { this->telephone = telephone; }
void Employee::setPoste(const QString &poste) { this->poste = poste; }
void Employee::setDisponibilite(const QString &disponibilite) { this->disponibilite = disponibilite; }
void Employee::setHeureTravail(const QString &heureTravail) { this->heureTravail = heureTravail; }

// Method to add an employee
bool Employee::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYE (IDEMPLOYE, NOMEMPLOYE, PRENOMEMPLOYE, LOGIN, MOTDEPASSE, TELEPHONEEMPLOYE, POSTEEMPLOYE, DISPONIBILITE, HEUREDETRAVAIL) " "VALUES (:id, :nom, :prenom, :login, :password, :telephone, :poste, :disponibilite, :heureTravail)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":telephone", telephone);
    query.bindValue(":poste", poste);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":heureTravail", heureTravail);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'employé :" << query.lastError().text();
        return false;
    }
    qDebug() << "Employee added successfully to database.";
    return true;
}

// Method to display employees
QSqlQueryModel* Employee::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT IDEMPLOYE, NOMEMPLOYE, PRENOMEMPLOYE, LOGIN, MOTDEPASSE, TELEPHONEEMPLOYE, POSTEEMPLOYE, DISPONIBILITE, HEUREDETRAVAIL FROM EMPLOYE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des employés:" << model->lastError().text();
    } else {
        qDebug() << "Employee data fetched successfully";
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Login"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Mot de Passe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Disponibilité"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Heure de travail"));

    return model;
}

// Method to delete an employee
bool Employee::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE IDEMPLOYE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'employé :" << query.lastError().text();
        return false;
    }
    qDebug() << "Employee deleted successfully from database.";
    return true;
}
// Method to modify an employee
bool Employee::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET NOMEMPLOYE = :nom, PRENOMEMPLOYE = :prenom, LOGIN = :login, MOTDEPASSE = :password, "
                  "TELEPHONEEMPLOYE = :telephone, POSTEEMPLOYE = :poste, DISPONIBILITE = :disponibilite, HEUREDETRAVAIL = :heureTravail "
                  "WHERE IDEMPLOYE = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.bindValue(":telephone", telephone);
    query.bindValue(":poste", poste);
    query.bindValue(":disponibilite", disponibilite);
    query.bindValue(":heureTravail", heureTravail);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'employé :" << query.lastError().text();
        return false;
    }
    qDebug() << "Employee modified successfully in database.";
    return true;
}
/*
bool Employee::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)
{
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de créer le fichier PDF.");
        return false;
    }

    // Paramètres PDF
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));

    // Titre
    painter.drawText(2500, 1100, "Liste des Employés");

    // Coordonnées et dimensions des cellules
    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;

    // En-têtes du tableau
    QStringList headers = {"ID", "Nom", "Prénom", "Login", "Téléphone", "Poste", "Disponibilité", "Heure de Travail"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }

    // Données des employés
    int rowCount = model->rowCount();
    painter.setFont(QFont("Arial", 10));

    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor); // Remplir la cellule avec la couleur de fond
            painter.drawText(cellRect, Qt::AlignCenter, data); // Dessiner le texte
            painter.drawRect(cellRect); // Dessiner le contour de la cellule
        }
    }

    // Fin d’écriture du PDF
    painter.end();
    return true;
}*/
/*bool Employee::exporterPDF(const QString &nomFichier, QAbstractItemModel *model)
{
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(nullptr, "Erreur", "Impossible de créer le fichier PDF.");
        return false;
    }

    // Paramètres PDF
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12));

    // Titre
    painter.drawText(2000, 1000, "Liste des Employés");

    // Coordonnées et dimensions des cellules
    int startX = 100;
    int startY = 1300; // Adjusted for better spacing
    int cellWidth = 1200;
    int cellHeight = 500;

    // En-têtes du tableau
    QStringList headers = {"ID", "Nom", "Prénom", "Login", "Téléphone", "Poste", "Disponibilité", "Heure de Travail"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    // Drawing headers
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }

    // Drawing employee data
    int rowCount = model->rowCount();
    int currentY = startY + cellHeight;  // Adjusting starting position for rows

    painter.setFont(QFont("Arial", 10));

    for (int row = 0; row < rowCount; ++row) {
        // Check if we need to add a page break
        if (currentY + cellHeight > pdfWriter.pageSize().height()) {
            pdfWriter.newPage();  // Create a new page if we exceed the page limit
            currentY = startY + cellHeight; // Reset row position for new page
        }

        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, currentY, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor); // Fill cell with background color
            painter.drawText(cellRect, Qt::AlignCenter, data); // Draw text inside cell
            painter.drawRect(cellRect); // Draw border around cell
        }

        currentY += cellHeight;  // Move to next row
    }

    painter.end();
    return true;
}*/
#include "employee.h"
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPageSize>

bool Employee::exporterPDF(const QString &nomFichier, QAbstractItemModel *model) {
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        qDebug() << "Erreur lors de l'initialisation du QPainter pour le PDF.";
        return false;
    }

    // Set PDF parameters
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));

    // Title
    painter.drawText(2500, 1100, "Liste des Employés");

    // Table coordinates and cell dimensions
    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;

    // Table headers
    QStringList headers = {"ID Employé", "Nom", "Prenom", "Login", "Mot de Passe", "Téléphone", "Poste", "Disponibilité", "Heure de Travail"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }

    // Employee data
    int rowCount = model->rowCount();
    painter.setFont(QFont("Arial", 10));
    for (int row = 0; row < rowCount; ++row) {
        QColor bgColor = (row % 2 == 0) ? Qt::lightGray : Qt::white;

        for (int col = 0; col < headers.size(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            painter.fillRect(cellRect, bgColor);
            painter.drawText(cellRect, Qt::AlignCenter, data);
            painter.drawRect(cellRect);
        }
    }

    painter.end();
    QMessageBox::information(nullptr, "PDF Créé", "Un fichier PDF a été créé.");
    return true;
}


QSqlQueryModel* Employee::trierParID(bool asc) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Build the query string
    QString queryString = "SELECT * FROM EMPLOYE ORDER BY IDEMPLOYE";
    queryString += asc ? " ASC" : " DESC";

    query.prepare(queryString);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri des employés par ID :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query)); // Use std::move to pass the query by move
    return model;
}

