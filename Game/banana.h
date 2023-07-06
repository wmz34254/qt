/* 香蕉类 继承Item */
#ifndef BANANA_H
#define BANANA_H

#include "item.h"

class Banana : public Item
{
    Q_OBJECT
public:
    Banana(int speed);
};

#endif // BANANA_H
