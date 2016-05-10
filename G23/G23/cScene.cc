#include "cScene.h"

cScene::cScene(void)
{
	
}

cScene::~cScene(void)
{
}

void cScene::initilize()
{
	backs.clear();
	for (int i = 0; i < 1000;++i)
	{
		backDot * newDot = new backDot(rand() % GAME_WIDTH * 10 - GAME_WIDTH * 5, rand() % GAME_HEIGHT * 10 - GAME_HEIGHT * 5,
			make_tuple(rand() % 255, rand() % 255, rand()%255));
		backs.push_back(newDot);
	}
}

void cScene::display(float x, float y)
{
	backDisplay(x, y);
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(5);
	glBegin(GL_LINES);
	
	glEnd();
	glLineWidth(1);
}

void cScene::backDisplay(float x, float y)
{
	for (deque<backDot*>::const_iterator it = backs.begin(); it != backs.end(); ++it)
	{
		colorByte R, G, B;
		tie(R, G, B) = (*it)->getColor();
		glColor3f(R, G, B);
		glPointSize(3);

		glBegin(GL_POINTS);
		glVertex2f(-x + (*it)->getX(),-y + (*it)->getY());
		glEnd();
	}
}

cCamera::cCamera()
{
	setPosition(0.f, 0.f);
	setVolume(GAME_WIDTH, GAME_HEIGHT);
	setR(100.f);
}

cCamera::~cCamera()
{
}

void cCamera::updateCamera(float x, float y)
{
	setPosition(x, y);
}

void cCamera::updateRatio(float r)
{
	setR(r);
}
