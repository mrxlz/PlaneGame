#pragma once
#include "qobject.h"
#include "MyPlane.h"
#include "EnemyPlane.h"
#include "Text.h"
#include "Boss.h"
#include <list>
#include<vector>


class GameController : public QObject
{
	Q_OBJECT

private:
	QGraphicsScene *scene;
	MyPlane *myPlane;

	QTimer refreshTimer;
	QTimer gameTimer;
	int bossTimerId;

	int timerId;
	int enemyTimerId;
	int missileTimerId;
	int addEnemyTimerid;
	int propsTimerId;
	int enemyCount;
	bool isPause;
	Text *info;

	void handleKeyPressed(QKeyEvent *event);
	void addEnemy();

public:
	GameController(QGraphicsScene *scene, MyPlane *myPlane, QObject *parent = 0);
	~GameController();
	void timerEvent(QTimerEvent *);
	void setMyPlane(MyPlane *);
	void gameStart();
	void gameOver();

public slots:

	void pause();
	void resume();

	

protected:
	bool eventFilter(QObject *object, QEvent *event);
};

