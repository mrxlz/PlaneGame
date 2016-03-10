#include "stdafx.h"
#include "Boss.h"
#include "Bomb.h"

Boss::Boss(GameController* controller, QPixmap *bossPng, QGraphicsScene *scene, MyPlane *player) :
									QGraphicsPixmapItem(*bossPng),
									QPixmap(*bossPng),
									planePng(*bossPng),
									controller(controller),
									scene(scene),
									player(player),
									hitedCount(0)
{
	setPos((scene->width() - this->width()) / 2, 5-height());
	speed = 1;
	scene->addItem(this);
	moveTimerId = startTimer(100);
}
Boss::Boss(){

}

void Boss::shoot(){
	shootTimerId = startTimer(1500);
}


void Boss::timerEvent(QTimerEvent *event){
	if (event->timerId() == shootTimerId){
		QPointF position = pos();
		scene->addItem(new Bomb(scene, QPixmap("img/bomb5.png"), position + QPointF(0, height()), Bomb::Direction::MoveDown,player));
		scene->addItem(new Bomb(scene, QPixmap("img/bomb5.png"), position + QPointF(width()-50, height()), Bomb::Direction::MoveDown, player));
	}
	if (event->timerId() == moveTimerId)
		moveDown();
	
}



void Boss::moveDown(){
	if (y() >= height()){
		killTimer(moveTimerId);
		killTimer(shootTimerId);
		return;
	}

	moveBy(0, speed);
	if (this->y() >= scene->height()){
		scene->removeItem(this);
		delete this;
		return;
	}
}

int Boss::hited(){
	hitedCount += 1;
	return hitedCount;
}

int Boss::getHitCount(){
	return hitedCount;
}

void Boss::notShoot(){
	killTimer(shootTimerId);
}

void Boss::gameOver(){
}


Boss::~Boss()
{
}
