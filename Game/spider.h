/* 蜘蛛类*/
#ifndef SPIDER_H
#define SPIDER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Spider : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Spider(QPixmap pixmap, int speed);

    void resetSpeed(int speed);

public slots:
    // 下落
    void fall();

private:
    // 计时器，控制下落
    QTimer* timer;
};

#endif // SPIDER_H
