#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <client.cpp>
#include <QInputDialog>
#include <json.hpp>
#include <typeinfo>
#include <QMessageBox>
#include <QTextBlock>
#include <QStringList>
#include <QDebug>
#include <QWidget>
using json = nlohmann::json;
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->update();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui -> pushButton_3->setEnabled(false);
    while (true){
        PORT = QInputDialog :: getInt(this,"Puerto", "Ingrese el puerto del servidor");
        if (PORT == 0) {
            QMessageBox::warning(this, tr("Error"), tr("Entry a port"));
        } else {
            break;
        }
    }
    setPort(PORT);
    ui->statusBar->showMessage ("Initialized on port: "+QString::number(PORT));
    }



bool MainWindow :: Validate (json info){
    if (info["value"].is_string()) return true;
    else return false;
}
void MainWindow::TableRe(json all) {
    ui -> tableWidget -> setRowCount(0);
    int fila = ui -> tableWidget -> rowCount();

    for (nlohmann::json::reverse_iterator it = all.rbegin(); it != all.rend();++it){
        cout << it.key() << endl;
        cout << all[it.key()]["value"] << endl;
        ui -> tableWidget -> insertRow(ui->tableWidget->rowCount());
        if (Validate(all[it.key()])) ui -> tableWidget -> setItem(fila, Value, new QTableWidgetItem (QString::fromStdString(all[it.key()]["value"])));

        else ui -> tableWidget -> setItem(fila, Value, new QTableWidgetItem (QString::number((float)all[it.key()]["value"])));
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


//    json J;
//    J["type"] = "float";
//    J["value"] = 3.14;
//    J["label"] = "Número PI";
//    J["size"] = 4;
//    J["countr"] = 1;
//    json J2;
//    J2["type"] = "float";
//    J2["value"] = "Número PI";
//    J2["label"] = "Número";
//    J2["size"] = 4;
//    J2["countr"] = 1;
//    try {
//        TableRe(Execute(J.dump()));
//        TableRe(Execute(J2.dump()));
//    } catch (...) {
//        QMessageBox :: warning(this, tr("Send failed") , tr ("Server is not initialized"));
//    }
    text = ui->widget->toPlainText();
    lines = text.split("\n");
    currentline = 0;
    ui->widget->setReadOnly(true);
    ui->pushButton->setEnabled(false);
    ui -> pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}


void MainWindow::on_pushButton_3_pressed()
{


    cout << currentline <<  " " << lines.size() << endl;
    if (currentline ==lines.size()){

        QMessageBox :: information(this,tr("Finish reading"), tr ("Ready debug"));
        currentline = 0;
        ui->widget->setReadOnly(false);
        ui->pushButton->setEnabled(true);
        ui -> pushButton_3->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    } else {
        QString lin = lines[currentline];
        string toparser = lin.toStdString();
        const char* p =toparser.c_str();
        ui->widget->moveCursor(QTextCursor::Down);
        cout << p << endl;
        currentline++;
    }


}

void MainWindow::on_pushButton_2_pressed()
{
    ui->widget->clear();
}
