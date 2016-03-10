#pragma once
#include "qgraphicsitem.h"
class SecondTimer : public QGraphicsTextItem
{
public:
	SecondTimer();
	~SecondTimer();

protected:
	void advance(int step);
};

