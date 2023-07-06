/* 物品基类 */
#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "global.h"

class Item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Item(QString type, int speed);

    void resetSpeed(int speed);

public slots:
    // 下落
    void fall();

private:
    // 物品类型，取值：apple banana pear等
    QString type;
    // 计时器，控制下落
    QTimer* timer;
};


#endif // ITEM_H
