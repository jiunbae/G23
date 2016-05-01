#pragma once
#include "Globals.h"
#include "cObject.h"

typedef unsigned char colorByte;
typedef tuple<colorByte, colorByte, colorByte> colorType;

class cBullet : public cMove < float > {
public:
	cBullet();
	cBullet(float x, float y);
	cBullet(float x, float y, float vx, float vy);
	cBullet(float x, float y, float vx, float vy, float ax, float ay);
	~cBullet();

	void setState(int _state);
	int getState();

private:
	int state = 0;
};
class cWeapon {
public:
	cWeapon();
	cWeapon(colorType _color);
	~cWeapon();

	void fire(const float x, const float y, const float angle)
	{
		cBullet * newBullet = new cBullet(x, y, 50 * sin(2 * M_PI * -(angle + 180) / 360), 50 * cos(2 * M_PI * -(angle + 180) / 360));
		bullets.push_back(newBullet);
	}

	void display()
	{
		colorByte R, G, B;
		tie(R, G, B) = color;
		glColor3f(R / 255, G / 255, B / 255);

		glPointSize(3);
		glBegin(GL_POINTS);
		for (deque<cBullet*>::const_iterator it = bullets.begin(); it != bullets.end(); ++it)
		{
			glVertex2f((*it)->getX(), (*it)->getY());
		}
		glEnd();
		glPointSize(1);
	}
	void loop()
	{
		for (deque<cBullet*>::const_iterator it = bullets.begin(); it != bullets.end(); ++it)
			(*it)->move();
		
		for (deque<cBullet*>::const_iterator it = bullets.begin(); it != bullets.end(); ++it)
			if (!(*it)->isValid())
			{
				delete (*it);
				it = bullets.erase(it);
			}
	}
	void idle()
	{

	}

	void setColor(colorType _color);
	colorType getColor();

private:
	deque<cBullet*> bullets;

	colorType color = make_tuple(0, 0, 0);
};