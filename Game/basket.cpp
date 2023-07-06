#include "basket.h"
#include "global.h"

Basket::Basket(QPixmap pixmap)
{
    setPixmap(pixmap.scaled(kBasketWidth, kBasketHeight));
}
