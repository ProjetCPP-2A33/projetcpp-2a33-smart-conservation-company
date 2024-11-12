#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked(); // Slot for adding an employee
    void on_pushButton_supprimer_clicked(); // Slot for deleting an employee
    void on_pushButton_modifier_clicked();
    void on_pb_pdf_clicked();
    void on_pushButton_trier_clicked();
private:
    Ui::MainWindow *ui;
    Employee emp; // Instance of Employee
};


#endif // MAINWINDOW_H
