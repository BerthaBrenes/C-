#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <client.cpp>
#include <QInputDialog>
#include <json.hpp>
#include <typeinfo>
using json = nlohmann::json;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString text = ui->plainTextEdit->toPlainText();
    ui->plainTextEdit->backgroundRole();
    ui->label->update();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    PORT = QInputDialog :: getInt(this,"Puerto", "Ingrese el puerto del servidor");
    setPort(PORT);


}
void MainWindow::TableRe(json all) {
    ui -> tableWidget -> setRowCount(0);
    int fila = ui -> tableWidget -> rowCount();

    for (nlohmann::json::reverse_iterator it = all.rbegin(); it != all.rend();++it){
        cout << it.key() << endl;
        cout << all[it.key()]["value"] << endl;
        ui -> tableWidget -> insertRow(ui->tableWidget->rowCount());
        ui -> tableWidget -> setItem(fila, Value, new QTableWidgetItem (QString::number((float)all[it.key()]["value"])));
        ui -> tableWidget -> setItem(fila, Direction, new QTableWidgetItem (QString::fromStdString(all[it.key()]["direction"])));
        ui->tableWidget -> setItem(fila, Label, new QTableWidgetItem (QString::fromStdString(it.key())));
        ui->tableWidget -> setItem(fila, Count, new QTableWidgetItem (QString::number((int)all[it.key()]["countr"])));
        fila++;
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_windowIconTextChanged(const QString &iconText)
{
   ui->label->setText(iconText);
}

void MainWindow::on_plainTextEdit_textChanged()
{
    on_label_windowIconTextChanged(ui->plainTextEdit->documentTitle());
    on_lcdNumber_windowIconTextChanged(QString::number(ui->plainTextEdit->cursorWidth()));

    if(ui->plainTextEdit->toPlainText() == "int"){
        cout<<"vale 2 bytes"<<endl;
        on_label_windowIconTextChanged("int");
        ui->plainTextEdit->setCursorWidth(2);
 }
}

void MainWindow::on_lcdNumber_windowIconTextChanged(const QString &iconText)
{
    ui->lcdNumber->display(iconText);
}

void MainWindow::on_pushButton_pressed()
{
    Update();
}

void MainWindow::Update()
{


    json J;
    J["type"] = "float";
    J["value"] = 3.14;
    J["label"] = "Número PI";
    J["size"] = 4;
    J["countr"] = 1;
    TableRe(Execute(J.dump()));




}


