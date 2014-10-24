#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spravka.h"
#include "bank.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    Arr *arr;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    Spravka *formspravka;

private slots:
    void open_spravka();
    void on_pushButton_Add_clicked();
    void on_pushButton_Refresh_clicked();
    void activateButton();
    void print_arr();

signals:
    void print();
};


#endif // MAINWINDOW_H
