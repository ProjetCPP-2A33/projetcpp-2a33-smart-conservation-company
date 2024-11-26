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
#include <QHash>
#include <QFile>
#include <QTextStream>

using namespace std;

Employee::Employee() {}


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

bool Employee::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE "
                  "SET NOMEMPLOYE = :nom, PRENOMEMPLOYE = :prenom, LOGIN = :login, MOTDEPASSE = :password, "
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



bool Employee::exporterPDF(const QString &nomFichier, QAbstractItemModel *model) {
    QPdfWriter pdfWriter(nomFichier);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setPageMargins(QMargins(30, 30, 30, 30));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        qDebug() << "Erreur lors de l'initialisation du QPainter pour le PDF.";
        return false;
    }

    //
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));


    painter.drawText(2500, 1100, "Liste des Employés");


    int startX = 200;
    int startY = 1800;
    int cellWidth = 1100;
    int cellHeight = 450;


    QStringList headers = {"ID Employé", "Nom", "Prenom", "Login", "Mot de Passe", "Téléphone", "Poste", "Disponibilité", "Heure de Travail"};
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawText(startX + col * cellWidth, startY, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
    }


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


    QString queryString = "SELECT * FROM EMPLOYE ORDER BY IDEMPLOYE";
    queryString += asc ? " ASC" : " DESC";

    query.prepare(queryString);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri des employés par ID :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query));
    return model;
}

bool Employee::chercherParID(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE IDEMPLOYE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche de l'employé par ID :" << query.lastError().text();
        return false;
    }

    if (query.next()) {

        return true;
    }


    return false;
}



QMap<QString, int> Employee::statistiquesDisponibilite() {
    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT disponibilite, COUNT(*) FROM EMPLOYE GROUP BY disponibilite");

    if (query.exec()) {
        while (query.next()) {
            QString disponibilite = query.value(0).toString();
            int count = query.value(1).toInt();
            statistiques.insert(disponibilite, count);
        }
    } else {
        qDebug() << "Erreur lors de la récupération des statistiques de disponibilité :" << query.lastError().text();
    }

    return statistiques;
}



