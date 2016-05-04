#pragma once
#include "Globals.h"
#include "cObject.h"

typedef cObjectDot cBullet;
typedef deque<cBullet*> cBullets;

class cWeapon : public cColor {
public:
	cWeapon();
	cWeapon(colorType _color);
	~cWeapon();

	void fire(const float x, const float y, const float angle);
	void destroy(int dist_iter);

	void display(float x, float y);
	void loop();
	cBullets getBullets();

private:
	float speed =1 ;
	cBullets bullets;
	deque<timePoint> bulletTime;
	cTimer<long, std::milli> timer;
};