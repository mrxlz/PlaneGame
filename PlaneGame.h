#pragma once
#include <QtWidgets/QMainWindow>
#include "GameController.h"
class PlaneGame : public QMainWindow
{
private:
	QGraphicsScene *scene;
	QGraphicsView *view;
	GameController *controller;

	void initScene();

private slots:
	void adjustViewSize();

public:
	PlaneGame(QWidget *parent = 0);
	~PlaneGame();
};

