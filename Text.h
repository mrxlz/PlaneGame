#ifndef TEXT_H
#define TEXT_H

#include "stdafx.h"
#include "qgraphicsitem.h"
#include "MyPlane.h"

class Text : public QGraphicsItem,QObject
{
public:
	Text(QGraphicsScene *scene, MyPlane *player);
    ~Text();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void timerEvent(QTimerEvent *);


private:

    QGraphicsScene *scene;
	MyPlane *player;
	int timerId;
};

#endif // TEXT_H
