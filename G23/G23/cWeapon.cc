#include "cWeapon.h"

cWeapon::cWeapon()
{

}

cWeapon::cWeapon(colorType _color) : cColor(_color)
{
	setColor(_color);
	cWeapon();
}

cWeapon::~cWeapon()
{
	for_each(bullets.begin(), bullets.end(), [](cBullet * bullet) {
		delete bullet;
	});
}

void cWeapon::fire(float x, float y, float angle)
{
	if (timer.getDeltaPoint() > 500)
	{
		cBullet * newBullet = new cObjectDot(x, y, -speed * sin(2 * M_PI * (angle + 180) / 360), speed * cos(2 * M_PI * (angle + 180) / 360));
		bullets.push_back(newBullet);
		bulletTime.push_back(timer.getTimePoint());
		timer.setDeltaPoint();
	}
}

void cWeapon::destroy(int dist_iter)
{
	delete  (*(bullets.begin() + dist_iter));
	bullets.erase(bullets.begin() + dist_iter);
	bulletTime.erase(bulletTime.begin() + dist_iter);
}

void cWeapon::display(float x, float y)
{
	colorByte R, G, B;
	tie(R, G, B) = getColor();
	glColor3f(R / 255, G / 255, B / 255);
	
	glPointSize(3);
	glBegin(GL_POINTS);

	for (cBullets::const_iterator it = bullets.begin(); it != bullets.end(); ++it)
		glVertex2f((*it)->getX() -x,(*it)->getY() -y);
	
	glEnd();
	glPointSize(1);
}

void cWeapon::loop()
{
	for (cBullets::iterator it = bullets.begin(); it != bullets.end();)
		//if (!(*it)->isValid() )
		if (timer.getDeltaTimePoint(*(bulletTime.begin() + distance(bullets.begin(), it))) > 5000)
		{
			delete (*it);
			bulletTime.erase(bulletTime.begin() + distance(bullets.begin(), it));
			it = bullets.erase(it);
		}
		else
		{
			(*it)->setPosition((*it)->move((*it)->getX(), (*it)->getY()));
			++it;
		}
}

cBullets cWeapon::getBullets()
{
	return bullets;
}
