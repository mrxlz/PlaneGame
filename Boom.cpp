#include "stdafx.h"
#include "Boom.h"


Boom::Boom(QGraphicsScene *scene, QPixmap &boom, QPointF position) :QGraphicsPixmapItem(boom),scene(scene)
{
	scene->addItem(this);
	setPos(position);
	exisTimerId = startTimer(30);
}

void Boom::timerEvent(QTimerEvent *event){
	if (event->timerId() == exisTimerId){
		scene->removeItem(this);
		delete this;
	}
}

Boom::~Boom()
{
}
