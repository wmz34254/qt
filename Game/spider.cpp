#include "spider.h"
#include "global.h"

Spider::Spider(QPixmap pixmap, int speed)
{
    setPixmap(pixmap.scaled(QSize(kSpiderWidth,kSpiderHeight)));
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Spider::fall);
    timer->start(speed);
}

void Spider::resetSpeed(int speed)
{
    if (!timer || !timer->isActive())
        return;

    timer->stop();
    timer->start(speed);
}

void Spider::fall()
{
    setPos(x(), y() + 10);
    if (y() > kGameHeight) {
        scene()->removeItem(this);
        delete this;
    }
}
