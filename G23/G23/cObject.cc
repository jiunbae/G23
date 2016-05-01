#include "cObject.h"

cObjectDot::cObjectDot()
{
	setPosition(0, 0);
	setVelocity(0, 0);
	setAcceleration(0, 0);
}

cObjectDot::cObjectDot(float x, float y)
{
	cObjectDot();
	setPosition(x, y);
}

cObjectDot::cObjectDot(float x, float y, float vx, float vy)
{
	cObjectDot(x, y);
	setVelocity(vx, vy);
}

cObjectDot::cObjectDot(float x, float y, float vx, float vy, float ax, float ay)
{
	cObjectDot(x, y, vx, vy);
	setAcceleration(ax, ay);
}

cObjectDot::~cObjectDot()
{
}

void cObjectDot::setState(int _state)
{
	state = _state;
}

int cObjectDot::getState()
{
	return state;
}

bool cObjectDot::isValid()
{
	if ((getX() < 0 && getVx() < 0) || (getY() < 0 && getVy() < 0) ||
		(getX() > GAME_WIDTH && getVx() > 0) || (getY() > GAME_HEIGHT && getVy() > 0))
		return false;
	return true;
}

cColor::cColor()
{
}

cColor::cColor(colorType _color) : color(_color)
{
}

cColor::~cColor()
{
}

void cColor::setColor(colorType _color)
{
	color = _color;
}

colorType cColor::getColor()
{
	return color;
}

cObjectBox::cObjectBox()
{
	setPosition(0, 0);
	setVelocity(0, 0);
	setAcceleration(0, 0);
	setVolume(0, 0);
	setColor(make_tuple(0, 0, 0));
}

cObjectBox::cObjectBox(float x, float y) : cObjectDot(x, y)
{
	cObjectBox();
}

cObjectBox::cObjectBox(float x, float y, float w, float h)
{
	cObjectBox(x, y);
	setVolume(w, h);
}

cObjectBox::~cObjectBox()
{
}
