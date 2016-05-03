#pragma once

#include "Globals.h"
#include "cObject.h"
#include "cTexture.h"

typedef cObjectBox cAsteroid;
typedef deque<cAsteroid*> cAsteroids;

class cEnemy : public cColor {
public:
	cEnemy();
	~cEnemy();

	void initilize(int mapsize, int count, string textureName);
	void newEnemy();
	void newEnemy(const float x, const float y, const float angle, const int state);
	void display();
	void loop();
	void idle();

private:
	cAsteroids asteroids;
	cTexture texture;
	int mapsize;
	cTimer<long, milli> timer;
};