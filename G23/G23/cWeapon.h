#pragma once
#include "Globals.h"
#include "cObject.h"

typedef cObjectDot* cBullet;
typedef deque<cBullet> cBullets;

class cWeapon : public cColor {
public:
	cWeapon();
	cWeapon(colorType _color);
	~cWeapon();

	void fire(const float x, const float y, const float angle);

	void display();
	void loop();

private:
	float speed =1 ;
	cBullets bullets;
	cTimer<long, std::milli> timer;
};