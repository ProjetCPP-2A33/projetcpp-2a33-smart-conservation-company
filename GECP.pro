QT       += core gui
QT += core gui sql network
QT += charts
QT += widgets
QT += core serialport
QT       +=sql
QT       += pdf

QT       += network
QT       += axcontainer
QT       +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    client.cpp \
    connection.cpp \
    delegatedeuxbouttons.cpp \
    employee.cpp \
    gestionemp.cpp \
    main.cpp \
    produits.cpp \
    user.cpp

HEADERS += \
    arduino.h \
    client.h \
    connection.h \
    delegatedeuxbouttons.h \
    employee.h \
    gestionemp.h \
    produits.h \
    user.h

FORMS += \
    gestionemp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
