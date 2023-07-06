#include "dialoghelp.h"
#include "ui_dialoghelp.h"

DialogHelp::DialogHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHelp)
{
    ui->setupUi(this);
    ui->label->setText("玩家通过左右方向键控制聚宝盆左右移动来收集物品，\n收集正确的物品会增加分数和能量，\n"
                       "收集错误的物品会降低分数或能量，\n能量为0则游戏结束。\n"
                       "当到达一定分数时，物品掉落速度将会加快。");
}

DialogHelp::~DialogHelp()
{
    delete ui;
}

void DialogHelp::on_pushButton_clicked()
{
    this->close();
}
