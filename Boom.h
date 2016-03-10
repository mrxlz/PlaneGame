#pragma once
#include "qgraphicsitem.h"
class Boom :
	public QGraphicsPixmapItem,public QObject
{
private:
	QGraphicsScene *scene;
	int exisTimerId; 

public:
	Boom(QGraphicsScene*, QPixmap&, QPointF);
	~Boom();
	void timerEvent(QTimerEvent *);
};

