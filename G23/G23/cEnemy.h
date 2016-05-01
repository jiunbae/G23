#pragma once

#include "Globals.h"
#include "cObject.h"

class cAsteroid : public cObject {
public:
	cAsteroid();
	~cAsteroid();

private:
};

class cEnemy {
public:
	cEnemy();
	~cEnemy();

	void initilize();
	void display();
	void loop();
	void idle();

private:
	deque<cAsteroid*> asteroids;
};