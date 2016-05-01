#pragma once
#include "Globals.h"
#include "cObject.h"

typedef unsigned char colorByte;
typedef tuple<colorByte, colorByte, colorByte> colorType;

class cWeapon : public cColor {
public:
	cWeapon();
	cWeapon(colorType _color);
	~cWeapon();

	void fire(const float x, const float y, const float angle);

	void display();
	void loop();
	void idle();

private:
	deque<cObjectDot*> bullets;

};