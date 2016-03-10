#pragma once
#include "qgraphicsitem.h"
#include "MyPlane.h"


class Bomb : public QGraphicsPixmapItem, public QPixmap, public QObject
{
public:
	enum Direction{MoveUp, MoveDown };
	enum Shooter{Enemy,Me,BigBoss};
	Bomb(QGraphicsScene*, QPixmap&, QPointF, Direction, MyPlane *player);
	~Bomb();
	void handleCollisions();
	void timerEvent(QTimerEvent *);
	Bomb* setShooter(Shooter);

protected:
	void advance(int step);

private:
	int timerId;
	Direction moveDirection;
	QGraphicsScene *scene;
	Shooter shooter;
	MyPlane *player;
};

