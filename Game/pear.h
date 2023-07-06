/* 梨类 继承Item */
#ifndef PEAR_H
#define PEAR_H

#include "item.h"

class Pear : public Item
{
    Q_OBJECT
public:
    Pear(int speed);
};

#endif // PEAR_H
