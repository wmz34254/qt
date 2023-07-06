/* 游戏主界面 */
#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QLabel>
#include <QIcon>
#include "basket.h"
#include "apple.h"
#include "banana.h"
#include "pear.h"
#include "bomb.h"
#include "spider.h"
#include "global.h"


class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent = nullptr);

public slots:
    void spawn();
    // 加分
    void collisions();
    // 判断碰撞
    void increaseScore(int add);
    // 减分
    void decreaseScore();
    // 减能量
    void decreaseEnergy();
    // 游戏结束
    void gameOver();

protected:
    // 键盘左右键，控制篮子左右移动
    void keyPressEvent(QKeyEvent* event);

private:
     QTimer* timer;
    QGraphicsScene* scene;
    // 篮子
    Basket* basket;
    // 游戏关卡显示标签
    QLabel* levelLabel;
    // 得分显示标签
    QLabel* scoreLabel;
    // 能量显示标签
    QLabel* energyLabel;
    // 关卡,默认1
    int level;
    // 能量 默认100
    int energy;
    // 得分 默认0
    int score;
    // 当前速度
    int speed = 250;
};

#endif // GAME_H
