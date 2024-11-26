#include "user.h"
#include <QDebug>

const QList<User> User::userList = {
    User("admin", "admin123"),
    User("user1", "password1"),
    User("user2", "password2")
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
