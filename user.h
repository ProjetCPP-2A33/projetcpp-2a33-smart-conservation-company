#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>

class User
{
private:
    QString username;
    QString password;

public:
    User();
    User(QString username, QString password);

    // Getters
    QString getUsername() const;
    QString getPassword() const;

    // Setters
    void setUsername(const QString &username);
    void setPassword(const QString &password);

    // Functions
    bool authenticate();

    static const QList<User> userList; // Liste statique d'utilisateurs
};

#endif // USER_H
