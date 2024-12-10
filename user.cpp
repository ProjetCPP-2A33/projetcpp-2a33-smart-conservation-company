#include "user.h"
#include <QDebug>

const QList<User> User::userList = {
    User("admin", "admin123"),
    User("client", "client123"),
    User("produit", "produit123"),
    User("commande", "commande123"),
    User("equipement", "equipement123"),
};

User::User() {}

User::User(QString username, QString password)
    : username(username), password(password) {}

QString User::getUsername() const { return username; }
QString User::getPassword() const { return password; }

void User::setUsername(const QString &username) { this->username = username; }
void User::setPassword(const QString &password) { this->password = password; }

bool User::authenticate() {
    for (const User &user : userList) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    return false;
}
