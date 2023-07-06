#include "dialogover.h"
#include "ui_dialogover.h"
#include "global.h"
DialogOver::DialogOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOver)
{
    ui->setupUi(this);
    ui->label_2->setText(QString::number(total));
}

DialogOver::~DialogOver()
{
    delete ui;
}

void DialogOver::on_pushButton_clicked()
{
    accept();
}
