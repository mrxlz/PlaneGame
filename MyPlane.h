#pragma once
#include "qgraphicsitem.h"
//#include "GameController.h"

class GameController;

class MyPlane : public QGraphicsPixmapItem, public QPixmap,public QObject
{
public:
	enum Direction{noMove, MoveLeft, MoveRight, MoveUp, MoveDown};

private:
	//QPointF position;
	//qreal rx;
	//qreal ry;
	GameController *controller;
	Direction moveDirection;
	QPixmap planePng;
	QPixmap bombPng;
	QGraphicsScene *scene;
	int speed;
	bool invincible;//ÊÇ·ñÎÞµÐ
	int blood;
	int integral;

protected:
	void advance(int step);


public:
	MyPlane(GameController*, QPixmap&, QPixmap&, QGraphicsScene *);
	~MyPlane();

	//void setMoveDirection(Direction);
	//void setInvincible(int);
	//void setBlood(int);
	void init();
	void handleKeyPressed(QKeyEvent *event);
	int height();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void setSpeed();
	void handleCollisions();
	void setMoveDirection(Direction direction);
	void shoot();
	int subtractBlood(int);
	int getBlood();

	int getIntegral();
	void addIntegral(int);
	void changeStatus();
	bool isInvincible();
	void boom();


};

