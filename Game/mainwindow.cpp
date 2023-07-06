#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoghelp.h"
#include "game.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Game *game = new Game();
    game->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    DialogHelp dlg_help;
    dlg_help.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
