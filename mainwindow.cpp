#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bank.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->spravka,SIGNAL (triggered()), this, SLOT (open_spravka()));
    connect(ui->quit,SIGNAL (triggered()), this, SLOT (close()));
    //соедин€ем сигналы о том, что текст изменен в lineEdit'ах со слотом, который включает кнопки при условии, что все заполнено
    connect(ui->lineEdit_Day, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Month, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Year, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Summa, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Receiver, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    connect(ui->lineEdit_Sender, SIGNAL(textChanged(QString)),this,SLOT(activateButton()));
    //устанавливаем регу€лрные выражени€ дл€ вводимых данных
    QRegExp stringexp("[a-zA-Z ]{1,81}");
    ui->lineEdit_Receiver->setValidator(new QRegExpValidator(stringexp,this));
    ui->lineEdit_Sender->setValidator(new QRegExpValidator(stringexp,this));

    QRegExp intexp("[0-9]{1,2}");
    ui->lineEdit_Day->setValidator(new QRegExpValidator(intexp,this));
    ui->lineEdit_Month->setValidator(new QRegExpValidator(intexp,this));

    QRegExp intexpyear("[0-9]{1,4}");
    ui->lineEdit_Year->setValidator(new QRegExpValidator(intexpyear,this));

    QRegExp floatexp("[0-9]{1,8}");
    ui->lineEdit_Summa->setValidator(new QRegExpValidator(floatexp,this));

    connect(this,SIGNAL(print()),this,SLOT(print_arr()));

    arr = new Arr;

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open_spravka()
{
Spravka formspravka;
formspravka.setModal(true);
formspravka.exec();
}


void MainWindow::on_pushButton_Add_clicked()
{
    bank *n = new bank;
    n->setDD(ui->lineEdit_Day->text().toInt());
    n->setMM(ui->lineEdit_Month->text().toInt());
    n->setYY(ui->lineEdit_Year->text().toInt());
    n->setSum(ui->lineEdit_Summa->text().toFloat());
    n->setSender(ui->lineEdit_Sender->text());
    n->setReceiver(ui->lineEdit_Receiver->text());
    arr->addNew(*n);

    emit print();

}

void MainWindow::print_arr()
{
    bank ce = arr->getCurrentElement();

    ui->textEdit->append(QString("Date: %1").arg(ce.getDD())+ "." + QString (" %1").arg (ce.getMM()) + "." + QString ("%1").arg (ce.getYY()));
    ui->textEdit->append(QString ("Income: %1").arg (ce.getSum()));
    ui->textEdit->append(QString ("Sender: %1").arg (ce.getSender()));
    ui->textEdit->append(QString ("Receiver: %1").arg (ce.getReceiver()));
    ui->textEdit->append(QString ("Total_Sum: %1").arg (arr->getSum()));

}


void MainWindow::activateButton()
{
    //если все пол€ не пустые, включаем кновки, иначе выключаем
    if(!(ui->lineEdit_Day->text().isEmpty())&&!(ui->lineEdit_Month->text().isEmpty())&&!(ui->lineEdit_Year->text().isEmpty())&&!(ui->lineEdit_Summa->text().isEmpty())&&!(ui->lineEdit_Day->text().isEmpty())&&!(ui->lineEdit_Sender->text().isEmpty())&&!(ui->lineEdit_Receiver->text().isEmpty()))
    {
        ui->pushButton_Add->setEnabled(true);
        ui->pushButton_Refresh->setEnabled(true);
    }
    else
    {
        ui->pushButton_Add->setEnabled(false);
        ui->pushButton_Refresh->setEnabled(false);
    }
}

void MainWindow::on_pushButton_Refresh_clicked()
//очищаютс€ пол€ заполнени€, дл€ ввода данных следующей операции
{
       ui->lineEdit_Day->clear();
       ui->lineEdit_Month->clear();
       ui->lineEdit_Year->clear();
       ui->lineEdit_Summa->clear();
       ui->lineEdit_Sender->clear();
       ui->lineEdit_Receiver->clear();
}
