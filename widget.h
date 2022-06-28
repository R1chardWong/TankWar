#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "config.h"
#include <QIcon>
#include <QTimer>
#include <QTime>
#include "player.h"
#include <speedup.h>
#include <morelife.h>
#include <QList>
#include <enemy.h>
#include <QCoreApplication>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <memory.h>
#include <QPushButton>
//static const int RETCODE_RESTART = 773;
class Widget : public QWidget
{
    Q_OBJECT
private:
    QPixmap grass;
    QPixmap brick;
    QPixmap water;
    QPixmap ice;
    QPixmap iron;
    QPixmap bg_gray;
    QPixmap camp;
    QPixmap toolPic;
    void init();
    void createPlayer();
    player role1;
    QRect campRect;
    QRect toolRect;
    QPainter paint;
    QTimer* timer1;
    QTimer* timer2;
    QTimer* timer3;
    QTimer* timer4;
    QTimer* timer5;
    QTimer* timer6;

    bool esc_pressed;
    QPushButton* c[40];

    bool toolExist;
    int toolx,tooly;
    int cursor;
    QList<Enemy> enemies;
    int enemyNum;
    int life;
    int gate;
    int start;
    void createEnemy();
protected:
    void loadMap();
    void drawMap();
    void drawFrame();
    void drawPanel();
    void drawStart();
    void drawmenu();
    void paintEvent(QPaintEvent *) override;
    void gameOver();
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void keyPressEvent(QKeyEvent *) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void collisionCheck();
    void toolPicked();
    int toolType;
    void nextGate();
public slots:
    void play();
    void enemyMove();
    void enemyShot();
    void bulletMove();
    void refresh();
    void createTool();
    void setgate();

};
#endif // WIDGET_H
