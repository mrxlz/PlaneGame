#include "stdafx.h"
#include "PlaneGame.h"



PlaneGame::PlaneGame(QWidget *parent) : QMainWindow(parent),
								scene(new QGraphicsScene(this)),
								view(new QGraphicsView(scene, this))
{
	initScene();
	controller = new GameController(scene, new MyPlane(controller, QPixmap("img/me.png"), QPixmap("img/bomb3.png"), scene));
	view->setRenderHints(QPainter::Antialiasing);
	setCentralWidget(view);
	resize(1002, 702);
	QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}


void PlaneGame::initScene(){
	setWindowTitle(QStringLiteral("·É»ú´óÕ½"));
	scene->setSceneRect(0, 0, 1000, 700);
	scene->setBackgroundBrush(QBrush(QPixmap("img/background2.bmp")));
}


void PlaneGame::adjustViewSize(){
	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

PlaneGame::~PlaneGame()
{
}
