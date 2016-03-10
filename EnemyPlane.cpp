#include "stdafx.h"
#include "EnemyPlane.h"
#include "Bomb.h"

EnemyPlane::EnemyPlane(GameController* controller, QPixmap *planePng, QPixmap *bombPng, QGraphicsScene *scene, MyPlane *player) :
										QGraphicsPixmapItem(*planePng),
										QPixmap(*planePng),
										planePng(*planePng),
										bombPng(*bombPng),
										controller(controller),
										scene(scene),
										player(player),
										planeType(Enemy)
{
	qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
	int rand = qrand() % (1000 - width());
	setPos(rand, 5 - height());
	rand = qrand() % 5 + 1;
	speed = rand;
	scene->addItem(this);

	moveTimerId = startTimer(1000/30);

}


void EnemyPlane::shoot(){
	shootTimerId = startTimer(1500);
}


void EnemyPlane::timerEvent(QTimerEvent *event){
	if (event->timerId() == shootTimerId){
		QPointF position = pos();
		scene->addItem((new Bomb(scene, bombPng, position + QPointF((this->width() - bombPng.width()) / 2, height()), Bomb::Direction::MoveDown,player))->setShooter(Bomb::Shooter::Enemy));
	}
}

void EnemyPlane::advance(int step){
	moveDown();
}


void EnemyPlane::moveDown(){
	moveBy(0, speed);
	if (this->y() >= scene->height()){
		scene->removeItem(this);
		delete this;
		return;
	}
}

bool EnemyPlane::isProps(){
	if (planeType == Props)
		return true;
	return false;
}

void EnemyPlane::setPlaneType(PlaneType type){
	planeType = type;
}

EnemyPlane::~EnemyPlane()
{
}
