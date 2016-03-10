#include "stdafx.h"
#include <QtWidgets/QApplication>
#include "MyPlane.h"
#include "PlaneGame.h"
#include <sstream>
#include"EnemyPlane.h"

using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	PlaneGame gameWindow;
	gameWindow.show();

	return app.exec();
}
