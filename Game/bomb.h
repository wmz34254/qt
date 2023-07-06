/* 炸弹类 */
#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Bomb : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bomb(QPixmap pixmap, int speed);

    void resetSpeed(int speed);

public slots:
    // 下落
    void fall();

private:
    // 计时器，控制下落
    QTimer* timer;
};

#endif // BOMB_H
