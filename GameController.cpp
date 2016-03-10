#include "stdafx.h"
#include "GameController.h"
#include "Bomb.h"
#include "Boss.h"
#include "qsound.h"
#define ENEMY_MOVE_INTERVAL_TIME 5 //每多少毫秒移动一次
#define ADD_ENEMY_INTERVAL_TIME 700
#define MAX_ENEMY_COUNT 10



GameController::GameController(QGraphicsScene *scene, MyPlane *myPlane, QObject *parent) :
			QObject(parent),
			scene(scene),
			myPlane(myPlane),
			enemyCount(0),
			isPause(false),
			info(new Text(scene,myPlane))
{

	QSound::play(QString("sound/bgm.wav"));
	gameStart();
	refreshTimer.start(1000 / 30);
	bossTimerId = startTimer(30);

	scene->addItem(myPlane);
	scene->addItem(info);
	resume();
}


void GameController::handleKeyPressed(QKeyEvent *event){
	switch (event->key())
	{
	case Qt::Key_Z:
		if (isPause)
			resume();
		else
			pause();
		break;
	case Qt::Key_Space:
		myPlane->shoot();
		break;
	case Qt::Key_C:
		myPlane->changeStatus();
	default:
		myPlane->handleKeyPressed(event);
		break;
	}
	
}

bool GameController::eventFilter(QObject *object, QEvent *event){
	if (event->type() != QEvent::KeyPress)
		return QObject::eventFilter(object, event);

	handleKeyPressed((QKeyEvent *)event);

	myPlane->handleKeyPressed((QKeyEvent *)event);
	return true;
}


void GameController::gameStart(){

	gameTimer.start(1000);
	propsTimerId = startTimer(10000);

	enemyTimerId = startTimer(ENEMY_MOVE_INTERVAL_TIME);
	addEnemyTimerid = startTimer(ADD_ENEMY_INTERVAL_TIME);


	myPlane->setPos(scene->width() / 2 - myPlane->width() / 2, scene->height() - myPlane->height());

	scene->installEventFilter(this);
}


void GameController::gameOver(){
	scene->removeItem(myPlane);
	scene->removeItem(info);
	scene->clear();

	myPlane->init();
	scene->addItem(myPlane);
	myPlane->setPos(scene->width() / 2 - myPlane->width() / 2, scene->height() - myPlane->height());

	bossTimerId = startTimer(30);
	scene->addItem(info);
	pause();
	resume();
}


void GameController::pause()
{
	disconnect(&refreshTimer, SIGNAL(timeout()), scene, SLOT(advance()));
	isPause = true;
}


void GameController::resume()
{
	connect(&refreshTimer, SIGNAL(timeout()), scene, SLOT(advance()));
	isPause = false;
}



void GameController::timerEvent(QTimerEvent *event){

	if (event->timerId() == addEnemyTimerid){
		if (isPause)
			return;
		addEnemy();

	}
	if (event->timerId() == bossTimerId && myPlane->getIntegral()>20000){
		(new Boss(this, new QPixmap("img/boss.png"), scene,myPlane))->shoot();
		killTimer(bossTimerId);
	}

	if (event->timerId() == propsTimerId)
		(new EnemyPlane(this,new QPixmap("img/props.png"),new QPixmap("img/props.png"), scene, myPlane))->setPlaneType(EnemyPlane::PlaneType::Props);
	if (myPlane->getBlood() <= 0 )
		gameOver();

}

void GameController::addEnemy(){
	qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
	for (int i = 0; i < qrand() % 2; i++){
		(new EnemyPlane(this, new QPixmap("img/enemy6.png"), new QPixmap("img/bomb6.png"), scene,myPlane))->shoot();
		enemyCount++;
	}
	for (int i = 0; i < qrand() % 2; i++){
		(new EnemyPlane(this, new QPixmap("img/enemy10.png"), new QPixmap("img/bomb10.png"), scene, myPlane))->shoot();
		enemyCount++;
	}
}



void GameController::setMyPlane(MyPlane *myPlane){
	this->myPlane = myPlane;
}

GameController::~GameController(){

}
