#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <client.cpp>
#include <QInputDialog>
#include <json.hpp>
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
    PORT = QInputDialog :: getInt(this,"Puerto", "Ingrese el puerto del servidor");
    setPort(PORT);

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
    J["type"] = 3;
    J["value"] = 3.14;
    J["label"] = "Número PI";

    cout << Execute(J.dump()) << endl;

}
