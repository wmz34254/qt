/* 变量定义 */
#ifndef GLOBAL_H
#define GLOBAL_H

// 游戏窗口大小
const int kGameWidth = 530;//800;
const int kGameHeight =582;//600;

const int fixWidth = 170;

extern int total;
// 水果大小
const int kFruitWidth = 40;
const int kFruitHeight = 40;

// 炸弹大小
const int kBombWidth = 40;
const int kBombHeight = 40;

// 蜘蛛大小
const int kSpiderWidth = 40;
const int kSpiderHeight = 40;


// 篮子大小
const int kBasketWidth = 40;
const int kBasketHeight = 40;
// 篮子移动速度
const int kBasketSpeed = 40;

// 加分
const int kAddScoreApple = 5;
const int kAddScoreBanana = 10;
const int kAddScorePear = 15;

// 每升一个关卡需要多少分
const int kPerLevelOfScore = 200;

// 每加一关，速度提升多少
const int kPerSpeedOfLevel = 50;

#endif // GLOBAL_H
