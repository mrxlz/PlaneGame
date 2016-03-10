#include "stdafx.h"
#include "Bomb.h"
#include "EnemyPlane.h"
#include "Boom.h"
#include "MyPlane.h"
#include "Boss.h"
#define BOMB_SPEED 16

Bomb::Bomb(QGraphicsScene *scene, QPixmap &bomb, QPointF position, Direction moveDirection, MyPlane *player) :
						scene(scene),
						QGraphicsPixmapItem(bomb),
						QPixmap(bomb),
						moveDirection(moveDirection),
						player(player)
{
	setPos(position);
	timerId = startTimer(1000/30);
}

void Bomb::timerEvent(QTimerEvent *event){
	if (event->timerId() == timerId)
		handleCollisions();
}

void Bomb::advance(int step){

	if (!step)
		return;
	switch (moveDirection)
	{
	case MoveUp:
		moveBy(0, -width() *2/3);
		if (this->y() <= -height()){
			scene->removeItem(this);
			delete this;
			return;
		}
		break;
	case MoveDown:
		moveBy(0, width() / 2);
		if (this->y() >= scene->height()){
			scene->removeItem(this);
			delete this;
			return;
		}
		break;
	default:
		break;
	}

}

void Bomb::handleCollisions(){
	QList<QGraphicsItem *> collisions = collidingItems();
	QList<QGraphicsItem *> booms;
	foreach(QGraphicsItem *collidingItem, collisions) {
		if (dynamic_cast<EnemyPlane*>(collidingItem) &&
			!dynamic_cast<EnemyPlane*>(collidingItem)->isProps() &&
			shooter == Me){
  			scene->removeItem(collidingItem);
			new Boom(scene, QPixmap("img/boom3.png"), collidingItem->pos() + QPointF(-10, height() / 2));
			player->addIntegral(1000);
			delete collidingItem;
		}
		else if (dynamic_cast<Boss*>(collidingItem) && shooter == Me){
			if (dynamic_cast<Boss*>(collidingItem)->hited() > 80){
				scene->removeItem(collidingItem);
				dynamic_cast<Boss*>(collidingItem)->notShoot();
			}
			new Boom(scene, QPixmap("img/boom6.png"), this->pos());
			new Boom(scene, QPixmap("img/boom2.png"), collidingItem->pos() + QPointF(10, height() / 2));
			new Boom(scene, QPixmap("img/boom2.png"), collidingItem->pos() + QPointF(90, height() / 1.5));
			new Boom(scene, QPixmap("img/bomb4.png"), collidingItem->pos() + QPointF(50, height()*2/3));
			player->addIntegral(2000);
		}
		else if (dynamic_cast<MyPlane*>(collidingItem)){
			if (!player->isInvincible()){
				if (shooter == Enemy)
					dynamic_cast<MyPlane*>(collidingItem)->subtractBlood(100);
				else if (shooter == BigBoss)
					dynamic_cast<MyPlane*>(collidingItem)->subtractBlood(1000);
			}
			new Boom(scene, QPixmap("img/boom2.png"), this->pos() + QPointF(-50, -50));
			new Boom(scene, QPixmap("img/boom6.png"), this->pos() + QPointF(width()*2/3, height() / 2));
		}
	}
}

Bomb* Bomb::setShooter(Shooter shooter){
	this->shooter = shooter;
	return this;
}

Bomb::~Bomb()
{
}
