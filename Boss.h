#pragma once
#include "qgraphicsitem.h"
#include "MyPlane.h"

class GameController;

class Boss :public QGraphicsPixmapItem, public QPixmap, public QObject
{

private:
	GameController *controller;
	QPixmap planePng;
	//QPixmap bombPng;
	int speed;
	QGraphicsScene *scene;
	MyPlane *player;

	QTimer timer;
	int shootTimerId;
	int moveTimerId;
	int hitedCount;


protected:

public:
	Boss();
	Boss(GameController*, QPixmap*, QGraphicsScene*, MyPlane *);
	~Boss();
	void moveDown();
	void shoot();
	void timerEvent(QTimerEvent *);
	int hited();
	void gameOver();
	int getHitCount();
	void notShoot();

protected slots:
	void movePlane(int step);

};