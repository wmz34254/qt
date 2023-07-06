#include "item.h"
#include "global.h"

Item::Item(QString type, int speed)
{
    this->type = type;
    setPixmap(QPixmap(":/images/" + type + ".png").scaled(QSize(kFruitWidth, kFruitHeight)));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Item::fall);
    timer->start(speed);
}

void Item::resetSpeed(int speed)
{
    if (!timer || !timer->isActive())
        return;

    timer->stop();
    timer->start(speed);
}

void Item::fall() {
    setPos(x(), y() + 10);
    if (y() > kGameHeight) {
        scene()->removeItem(this);
        delete this;
    }
}
