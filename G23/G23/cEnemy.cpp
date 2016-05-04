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
	newEnemy((float)(rand() % mapsize), (float)(rand() % mapsize), rand() % 360);
}

void cEnemy::newEnemy(const float x, const float y, const float angle)
{
	newEnemy(x, y, angle, 192);
}

void cEnemy::newEnemy(const float x, const float y, const float anglem, int size)
{
	if (size < 30)
		return;
	cAsteroid * asteroid = new cAsteroid(x, y);
	asteroid->setVelocity((float) 0.1f * (rand() % 5) - 0.25f, (float) 0.1f * (rand() % 5) - 0.25f);
	asteroid->setR(rand() % 360);
	asteroid->setState(size);
	asteroids.push_back(asteroid);
}

void cEnemy::destroy(int dist_iter)
{
	cAsteroid * asteroid = asteroids[dist_iter];
	int count = rand() % (asteroid->getState() / 10);
	while (count--)
		newEnemy(asteroid->getX(), asteroid->getY(), rand() % 360, rand() % (int)(asteroid->getState()  * 0.7f ));
	delete asteroid;
	asteroids.erase(asteroids.begin() + dist_iter);

}

void cEnemy::display(float x, float y)
{
	colorByte R, G, B;
	tie(R, G, B) = getColor();
	glColor3f(1, 1, 1);
	for (cAsteroids::const_iterator it = asteroids.begin(); it != asteroids.end(); ++it)
	{
		glPushMatrix();
		glTranslatef((*it)->getX() - x, (*it)->getY() - y, 0);
		glRotatef((*it)->getR(), 0, 0, (*it)->getR() < 0 ? -1 : 1);
		if (timer.getDeltaPoint() > ((*it)->getR() / 2))
		{
			timer.setDeltaPoint();
			(*it)->setR(((*it)->getR()) + 1);
		}
		glTranslatef(-(*it)->getX() + x, -(*it)->getY() + y, 0);
		texture.drawTexture((*it)->getX() - x, (*it)->getY() - y, (*it)->getState(), (*it)->getState());
		glPopMatrix();
	}
}

void cEnemy::loop()
{
	for (cAsteroids::const_iterator it = asteroids.begin(); it != asteroids.end();)
		//if (!(*it)->isValid())
		//{
		//	delete (*it);
		//	it = asteroids.erase(it);
		//}
		//else
		{
			(*it)->setPosition((*it)->move((*it)->getX(), (*it)->getY()));
			++it;
		}
}

void cEnemy::idle()
{
}

cAsteroids cEnemy::getAsteroids()
{
	return asteroids;
}

cAsteroid::cAsteroid()
{
}

cAsteroid::cAsteroid(float x, float y) : cObjectDot(x, y)
{
}

cAsteroid::~cAsteroid()
{
}
