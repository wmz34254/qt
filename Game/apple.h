/* 苹果类 继承Item */
#ifndef APPLE_H
#define APPLE_H

#include "item.h"

class Apple : public Item
{
    Q_OBJECT
public:
    Apple(int speed);
};

#endif // APPLE_H
