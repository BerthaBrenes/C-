#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QInputDialog>
#include <json.hpp>
#include <typeinfo>
#include <QMessageBox>
#include <QTextBlock>
#include <QStringList>
#include <QDebug>
#include <QWidget>
#include <QMutableStringListIterator>
#include "astnodetype.h"
#include <stdio.h>
#include "desicion.h"
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
        bool ok;
        PORT = QInputDialog :: getInt(this,"Puerto", "Ingrese el puerto del servidor\nEntre 5500 y 9000",0,5500,9000,0,&ok);
        if (!ok){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this,"Quit?","You want exit?",QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::No){
                QMessageBox::warning(this, tr("Error"), tr("Entry a port"));
            } else {
                exit(0);
            }
        } else {
            break;
        }
    }
    //cpa.setPort(PORT);
    //cpa.Reset();
    ui->statusBar->showMessage ("Port: "+QString::number(PORT));
    }



bool MainWindow :: Validate (json info){
    if (info["value"].is_string()) return true;
    else return false;
}
void MainWindow::TableRe(json all) {
    ui -> tableWidget -> setRowCount(0);
    int fila = ui -> tableWidget -> rowCount();

    for (json::iterator it = all.begin(); it != all.end(); ++it){
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

    text = ui->widget->toPlainText();
    lines = text.split("\n");
    for (int i = 0; i<lines.size();i++){
        if (lines[i] == ""){
            lines.removeAt(i);
        }
    }
    currentline = 0;
    ui->widget->setReadOnly(true);
    ui->pushButton->setEnabled(false);
    ui -> pushButton_3->setEnabled(true);
    ui->pushButton_2->setEnabled(false);

}
void MainWindow::nextb() {
    QMessageBox :: information(this,tr("Finish reading"), tr ("Ready debug"));
    currentline = 0;
    ui->widget->setReadOnly(false);
    ui->pushButton->setEnabled(true);
    ui -> pushButton_3->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->tableWidget->setRowCount(0);
     //cpa.Reset();
}
void MainWindow::on_pushButton_3_pressed()
{
    if (currentline ==lines.size()){
        nextb();
    } else {
        QString lin = lines[currentline];
        string toparser = lin.toStdString();
        char* linea_actual = (char*)toparser.c_str();
        cout << linea_actual << endl;
        ASTNodeType *node = Desicion(linea_actual,PORT).ReturNode();
        cout<<"asdasdasdsa"<<node->data<<endl;
        ifstream lec;
        lec.open("table.json",ios::in);
        string puta;
            getline(lec, puta);
            cout<<"se me olvido"<<puta<<endl;

        cout<<"todo bien"<<node->data<<endl;
        lec.close();
        //auto j8 = json::parse(puta);
        //TableRe(j8);
        remove("table.json");
        if (lines[currentline] == "float"){
            json J;
            J["type"] = "char";
            J["value"] = "Numerod";
            J["label"] = "NUMER";
            J["size"] = 1;
            J["countr"] = 1;
            //TableRe(cpa.Execute(J.dump()));

        } else if (lines[currentline] == "int"){
            json J;
            J["type"] = "char";
            J["value"] = "strings";
            J["label"] = "Numerod";
            J["size"] = 1;
            J["countr"] = 1;
            //TableRe( cpa.Execute(J.dump()));
        }
        else if (lines[currentline] == "double"){
                json J;
                J["type"] = "char";
                J["value"] = "Numer";
                J["label"] = "Numerod";
                J["size"] = 1;
                J["countr"] = 1;
                //TableRe( cpa.Execute(J.dump()));

        }
        else if (lines[currentline] == "char"){
            json J;
            J["type"] = "char";
            J["value"] = "string";
            J["label"] = "Numer";
            J["size"] = 1;
            J["countr"] = 1;
            //TableRe( cpa.Execute(J.dump()));

        } else if (lines[currentline] == "Get this"){
            QString a = lines[currentline+1];
            //cout<<"Deberia servir" <<  cpa.Get(a.toStdString()) <<endl;
        }


        currentline++;
    }


}

void MainWindow::on_pushButton_2_pressed()
{
    ui->widget->clear();

}

void MainWindow::on_actionChange_Port_triggered()
{
    while (true){
        bool ok;
        int cu = PORT;
        PORT = QInputDialog :: getInt(this,"Puerto", "Ingrese el puerto del servidor\nEntre 5500 y 9000",0,5500,9000,0,&ok);
        if (!ok){
            PORT=cu;
            break;
        } else {
            break;
        }
    }
     //cpa.setPort(PORT);
    ui->statusBar->showMessage ("Initialized on port: "+QString::number(PORT));
}
