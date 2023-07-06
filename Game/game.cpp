#include "game.h"
#include "dialogover.h"
#include"global.h"
#include <QSoundEffect>
int total=0;
Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(0, 0, kGameWidth, kGameHeight);
    setScene(scene);
    setFixedSize(kGameWidth, kGameHeight);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle(QStringLiteral("Riches"));
    setWindowIcon(QIcon(":/images/basket.png"));

    // 背景
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(QPixmap(":/images/bg.png"));
    background->setPos(0, 0);
    scene->addItem(background);

    basket = new Basket(QPixmap(":/images/basket.png"));
    basket->setPos(160, kGameHeight-kBasketHeight);
    scene->addItem(basket);

    levelLabel = new QLabel("LEVEL \n1");
    levelLabel->setStyleSheet("background:transparent; font-size: 40px; color: black;");
    levelLabel->setGeometry(360, 100, 130, 100);
    scene->addWidget(levelLabel);

    scoreLabel = new QLabel("SCORE \n0");
    scoreLabel->setStyleSheet("background:transparent; font-size: 40px; color: black;");
    scoreLabel->setGeometry(360, 250, 130, 100);
    scene->addWidget(scoreLabel);

    energyLabel = new QLabel("POWER \n100");
    energyLabel->setStyleSheet("background:transparent; font-size: 35px; color: black;");
    energyLabel->setGeometry(360, 400, 130, 100);
    scene->addWidget(energyLabel);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::spawn);
    timer->start(1000);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::collisions);
    timer->start(100);

// 添加bgm
    QSoundEffect * startSound = new QSoundEffect(this);//创建对象
    startSound->setSource(QUrl::fromLocalFile(":/bgm/bgms.wav"));//添加资源
    startSound->setLoopCount(QSoundEffect::Infinite);//设置循环次数int；  QSoundEffect::Infinite 枚举值 无限循环
    startSound->play();//软件启动自动播放

    energy = 100;
    score = 0;
    level = 1;
    srand(time(0));
}

void Game::spawn()
{
    int spawnWidth=kGameWidth-fixWidth;
    int itemWidth=40;
    int column = rand() % 9;
    int t=5-speed/50;
    int random = rand() % (5+t);
    int random_speed=speed+25-rand()%50;
    int itemX = column * itemWidth;
    if(itemX < spawnWidth){

        if (random == 0) {
            Apple* apple = new Apple(random_speed);
            apple->setPos(itemX, 0);
            scene->addItem(apple);
        }
        else if (random == 1) {
            Banana* banana = new Banana(random_speed);
            banana->setPos(itemX, 0);
            scene->addItem(banana);
        }
        else if (random == 2) {
            Pear* pear = new Pear(random_speed);
            pear->setPos(itemX, 0);
            scene->addItem(pear);
        }
        else if (random == 3 || random == 5 || random == 7) {
            Bomb* bomb = new Bomb(QPixmap(":/images/bomb.png"), random_speed);
            bomb->setPos(itemX, 0);
            scene->addItem(bomb);
        }
        else {
            Spider* spider = new Spider(QPixmap(":/images/spider.png"), random_speed);
            spider->setPos(itemX, 0);
            scene->addItem(spider);
        }
    }
}
void Game::collisions()
{
    // Check for collisions
    QList<QGraphicsItem *> items = scene->collidingItems(basket);
    for (int i = 0; i < items.size(); i++) {
        if (Apple* apple = dynamic_cast<Apple *>(items[i])) {
            increaseScore(kAddScoreApple);
            scene->removeItem(apple);
            delete apple;
        }
        else if (Banana* banana = dynamic_cast<Banana *>(items[i])) {
            increaseScore(kAddScoreBanana);
            scene->removeItem(banana);
            delete banana;
        }
        else if (Pear* pear = dynamic_cast<Pear *>(items[i])) {
            increaseScore(kAddScorePear);
            scene->removeItem(pear);
            delete pear;
        }
        else if (Spider* spider = dynamic_cast<Spider *>(items[i])) {
            decreaseScore();
            scene->removeItem(spider);
            delete spider;
        } else if (Bomb* bomb = dynamic_cast<Bomb *>(items[i])) {
            decreaseEnergy();
            scene->removeItem(bomb);
            delete bomb;
        }
    }
}

void Game::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left) {
        if (basket->x() > 0) {
            basket->setPos(basket->x() - kBasketSpeed, basket->y());
        }
    } else if (event->key() == Qt::Key_Right) {
        if (basket->x() < kGameWidth-kBasketWidth-fixWidth) {
            basket->setPos(basket->x() + kBasketSpeed, basket->y());
        }
    }
}

void Game::increaseScore(int add)
{
    score += add;
    total=score;

    scoreLabel->setText("SCORE \n" + QString::number(score));
    if (score % 50 == 0) {
        energy += 10;
        if (energy > 100)
            energy = 100;
        energyLabel->setText("POWER \n" + QString::number(energy));
    }

    // 升级
    if (score % kPerLevelOfScore == 0) {
        level += 1;
        levelLabel->setText("LEVEL \n" + QString::number(level));

        // 加速
        speed -= kPerSpeedOfLevel;
        QList<QGraphicsItem *> items = scene->items();
        for (int i = 0; i < items.count(); i++)
        {
            for (int i = 0; i < items.size(); i++) {
                if (Item* item = dynamic_cast<Item *>(items[i])) {
                    item->resetSpeed(speed);
                }
                else if (Spider* spider = dynamic_cast<Spider *>(items[i])) {
                    spider->resetSpeed(speed);
                } else if (Bomb* bomb = dynamic_cast<Bomb *>(items[i])) {
                    bomb->resetSpeed(speed);
                }
            }
        }
    }
}

void Game::decreaseScore()
{
    score -= 10;
    if (score < 0)
    {
        score = 0;
    }
    total=score;
    scoreLabel->setText("SCORE \n" + QString::number(score));
    if (score % 50 == 0) {
        energy -= 10;
        energyLabel->setText("POWER \n" + QString::number(energy));
    }
}

void Game::decreaseEnergy()
{
    energy -= 10;
    energyLabel->setText("POWER: \n" + QString::number(energy));
    if (energy <= 0) {

      //  gameOver();
        DialogOver dlg;
       if(dlg.exec()==QDialog::Accepted)//登录成功则跳转主页面
       {
           if(timer->isActive()){
           timer->stop();
           timer->deleteLater();
           timer=nullptr;
           }
           this->close();
       }
    }
}
void Game::gameOver()
{
    scene->clear();
    QLabel* gameOverLabel = new QLabel("Game Over");
    gameOverLabel->setStyleSheet("font-size: 48px; color: white;");
    gameOverLabel->setGeometry(200, 200, 400, 100);
    scene->addWidget(gameOverLabel);
}

