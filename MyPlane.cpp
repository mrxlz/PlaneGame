#include "stdafx.h"
#include "MyPlane.h"
#include "Boom.h"
#include "Bomb.h"
#include "EnemyPlane.h"
#include "Boss.h"
#include <QtMultimedia\QSound>


#define DEFAULT_MOVE_SIZE 15
#define SHOOT_SPEED DEFAULT_MOVE_SIZE+1

MyPlane::MyPlane(GameController *controller, QPixmap &planePng, QPixmap &bombPng, QGraphicsScene *scene) :
		QGraphicsPixmapItem(planePng),
		QPixmap(planePng),
		scene(scene),
		planePng(planePng),
		bombPng(bombPng),
		controller(controller),
		moveDirection(noMove),
		speed(DEFAULT_MOVE_SIZE),
		invincible(false),
		blood(10000),
		integral(0)
{
}

MyPlane::~MyPlane(){

}

void MyPlane::init(){
	invincible = 0;
	blood = 10000;
	integral = 0;
	moveDirection = noMove;
}

void MyPlane::setMoveDirection(Direction direction){
	moveDirection = direction;
}

void MyPlane::advance(int step){

	if (!step || moveDirection == noMove)
		return;

	switch (moveDirection)
	{
	case MoveLeft:
		moveLeft();
		break;
	case MoveRight:
		moveRight();
		break;
	case MoveUp:
		moveUp();
		break;
	case MoveDown:
		moveDown();
		break;
	default:
		break;
	}
	handleCollisions();

}

void MyPlane::moveLeft(){

	if (this->x() - this->speed >= 0)
		this->moveBy(-this->speed, 0);
	else
		this->setPos(0, this->y());
}

void MyPlane::moveRight(){

	if (this->x() + this->speed + this->width() <= 1000)
		this->moveBy(this->speed, 0);
	else
		this->setPos(1000-this->width(), this->y());
}

void MyPlane::moveUp(){
	if (this->y() - this->speed >= 0)
		this->moveBy(0, -this->speed);
	else
		this->setPos(this->x(), 0);
}

void MyPlane::moveDown(){
	if (this->y() + this->speed + this->height() <= 700)
		this->moveBy(0, this->speed);
	else
		this->setPos(this->x(), 700 - this->height());
}

void MyPlane::handleCollisions(){
	QList<QGraphicsItem *> collisions = collidingItems();
	QList<QGraphicsItem *> booms;
	foreach(QGraphicsItem *collidingItem, collisions) {
		if (dynamic_cast<EnemyPlane*>(collidingItem)){
			if (dynamic_cast<EnemyPlane*>(collidingItem)->isProps())
				blood += 2000;
			else if (!invincible){
				blood -= 2000;
				if (blood < 0)
				blood = 0;
				new Boom(scene, QPixmap("img/boom3.png"), collidingItem->pos());
				new Boom(scene, QPixmap("img/boom6.png"), this->pos());
				new Boom(scene, QPixmap("img/boom3.png"), collidingItem->pos() + QPointF(-10, height() / 2));
			}
			scene->removeItem(collidingItem);
			delete collidingItem;
		}
		else if (dynamic_cast<Boss*>(collidingItem) && !invincible){
			blood -= 5000;
			if (blood < 0)
				blood = 0;
			new Boom(scene, QPixmap("img/boom3.png"), collidingItem->pos());
			new Boom(scene, QPixmap("img/boom6.png"), this->pos());
			new Boom(scene, QPixmap("img/boom3.png"), collidingItem->pos() + QPointF(-10, height() / 2));
		}
	}
	collisions.clear();
}

void MyPlane::handleKeyPressed(QKeyEvent *event){
	switch (event->key())
	{
	case Qt::Key_Left:
		setMoveDirection(MyPlane::MoveLeft);
		break;
	case Qt::Key_Right:
		setMoveDirection(MyPlane::MoveRight);
		break;
	case Qt::Key_Up:
		setMoveDirection(MyPlane::MoveUp);
		break;
	case Qt::Key_Down:
		setMoveDirection(MyPlane::MoveDown);
		break;
	}

}


void MyPlane::shoot(){
	QSound::play(QString("sound/biubiubiu.wav"));
	scene->addItem((new Bomb(scene, bombPng, pos() + QPointF((width() - bombPng.width()) / 2, -height()), Bomb::Direction::MoveUp,this))->setShooter(Bomb::Shooter::Me));
}

int MyPlane::subtractBlood(int someBlood){
	blood -= someBlood;
	if (blood < 0)
		blood = 0;
	return blood;
}


int MyPlane::height(){
	return planePng.height();
}

int MyPlane::getBlood(){
	return blood;
}

void MyPlane::addIntegral(int integral){
	this->integral += integral;
}

int MyPlane::getIntegral(){
	return integral;
}

void MyPlane::changeStatus(){
	invincible = (invincible ? false : true);
}

bool MyPlane::isInvincible(){
	return invincible;
}

void MyPlane::boom(){

}

