#include "bomb.h"
#include "global.h"

Bomb::Bomb(QPixmap pixmap, int speed)
{
    setPixmap(pixmap.scaled(QSize(kBombWidth,kBombHeight)));

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bomb::fall);
    timer->start(speed);
}

void Bomb::resetSpeed(int speed)
{
    if (!timer || !timer->isActive())
        return;

    timer->stop();
    timer->start(speed);
}

void Bomb::fall() {
    setPos(x(), y() +10);
    if (y() > kGameHeight) {
        scene()->removeItem(this);
        delete this;
    }
}

