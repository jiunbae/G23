#include "cEnemy.h"

cEnemy::cEnemy()
{
}

cEnemy::~cEnemy()
{
}

void cEnemy::initilize(int mapsize, int count, string textureName)
{
	asteroids.clear();
	this->mapsize = mapsize;
	texture.initilize();
	texture.loadTexture(IL_PNG, textureName);
	while (count--)
		newEnemy();
}

void cEnemy::newEnemy()
{
	newEnemy((float)(rand() % mapsize), (float)(rand() % mapsize), rand() % 360, 1);
}

void cEnemy::newEnemy(const float x, const float y, const float angle, const int state)
{

	cAsteroid * asteroid = new cAsteroid(x, y);
	asteroid->setVelocity((float) 0.1f * (rand() % 5) - 0.25f, (float) 0.1f * (rand() % 5) - 0.25f);
	asteroid->setR(rand() % 360);
	asteroids.push_back(asteroid);
}

void cEnemy::display()
{
	colorByte R, G, B;
	tie(R, G, B) = getColor();
	glColor3f(1, 1, 1);
	for (cAsteroids::const_iterator it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		glPushMatrix();
		glTranslatef((*it)->getX(), (*it)->getY(), 0);
		glRotatef((*it)->getR(), 0, 0, (*it)->getR() < 0 ? -1 : 1);
		if (timer.getDeltaPoint() > 100)
		{
			timer.setDeltaPoint();
			(*it)->setR(((*it)->getR()) + 1);
		}
		glTranslatef(-(*it)->getX(), -(*it)->getY(), 0);
		texture.drawTexture((*it)->getX(), (*it)->getY());
		glPopMatrix();
	}
}

void cEnemy::loop()
{
	for (cAsteroids::const_iterator it = asteroids.begin(); it != asteroids.end();)
		if (!(*it)->isValid())
		{
			delete (*it);
			it = asteroids.erase(it);
		}
		else
		{
			(*it)->setPosition((*it)->move((*it)->getX(), (*it)->getY()));
			++it;
		}
}

void cEnemy::idle()
{
}
