#pragma once
#include "qgraphicsitem.h"
#include "MyPlane.h"
//#include "GameController.h"

class GameController;

class EnemyPlane : public QGraphicsPixmapItem, public QPixmap,public QObject
{
public:
	EnemyPlane(GameController*, QPixmap*, QPixmap*, QGraphicsScene*, MyPlane *);
	~EnemyPlane();
	void moveDown();
	void shoot();
	void timerEvent(QTimerEvent *);
	enum PlaneType{Enemy,Props};
	bool isProps();
	void setPlaneType(PlaneType);

private:
	GameController *controller;
	QPixmap planePng;
	QPixmap bombPng;
	int speed;
	QGraphicsScene *scene;
	MyPlane *player;

	QTimer timer;
	int shootTimerId;
	int moveTimerId;
	PlaneType planeType;

protected:
	void advance(int step);


protected slots:
	void movePlane(int step);

};