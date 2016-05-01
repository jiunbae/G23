#include "cEnemy.h"

cEnemy::cEnemy()
{
}

cEnemy::~cEnemy()
{
}

void cEnemy::initilize()
{
	asteroids.clear();
	
}

void cEnemy::newEnemy(const float x, const float y, const float angle, const int state)
{

	cAsteroid * asteroid = new cAsteroid(x, y);

	asteroids.push_back(asteroid);
}

void cEnemy::display()
{
	colorByte R, G, B;
	tie(R, G, B) = getColor();
	glColor3d(R / 255, G / 255, B / 255);
	for (cAsteroids::const_iterator it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		glPushMatrix();
		glTranslatef((*it)->getX(), (*it)->getY(), 0);
		glRotatef((*it)->getW(), 0, 0, (*it)->getW() < 0 ? -1 : 1);
		glTranslatef(-(*it)->getX(), -(*it)->getY(), 0);
		
		glPopMatrix();
	}
}

void cEnemy::loop()
{
	for (cAsteroids::iterator it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		(*it)->setPosition((*it)->move((*it)->getX(), (*it)->getY()));
		if (!(*it)->isValid())
		{
			delete (*it);
			it = asteroids.erase(it);
		}
	}
}

void cEnemy::idle()
{
}
