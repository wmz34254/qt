/* 篮子类 继承Item */
#ifndef BASKET_H
#define BASKET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "global.h"

class Basket : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Basket(QPixmap pixmap);
};


#endif // BASKET_H
