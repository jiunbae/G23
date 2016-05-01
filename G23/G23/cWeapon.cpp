#include "cWeapon.h"

cBullet::cBullet()
{
	setPosition(0, 0);
	setVelocity(0, 0);
	setAcceleration(0, 0);
}

cBullet::cBullet(float x, float y)
{
	cBullet();
	setPosition(x, y);
}

cBullet::cBullet(float x, float y, float vx, float vy)
{
	cBullet(x, y);
	setVelocity(vx, vy);
}

cBullet::cBullet(float x, float y, float vx, float vy, float ax, float ay)
{
	cBullet(x, y, vx, vy);
	setAcceleration(ax, ay);
}

cBullet::~cBullet()
{
}

void cBullet::setState(int _state)
{
	state = _state;
}

int cBullet::getState()
{
	return state;
}

cWeapon::cWeapon()
{
}

cWeapon::cWeapon(colorType _color) : color(_color)
{
}

cWeapon::~cWeapon()
{
	for_each(bullets.begin(), bullets.end(), [](cBullet* bullet) {
		delete bullet;
	});
}

void cWeapon::setColor(colorType _color)
{
	color = _color;
}

colorType cWeapon::getColor()
{
	return color;
}
