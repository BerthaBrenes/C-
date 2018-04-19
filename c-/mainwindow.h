#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <json.hpp>
#include <QTextLine>
#include <QString>
#include <QDebug>
using json = nlohmann::json;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_label_windowIconTextChanged(const QString &iconText);

    void on_lcdNumber_windowIconTextChanged(const QString &iconText);

    void on_pushButton_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_2_pressed();

    void on_actionChange_Port_triggered();

private:
    Ui::MainWindow *ui;

    int PORT;
    int SIZE;
    int currentline;
    QString text;
    QStringList lines;
    void Update ();
    void TableRe (json all);
    bool Validate (json info);
    enum Columna {
        Direction, Label, Value, Count
    };
};

#endif // MAINWINDOW_H
