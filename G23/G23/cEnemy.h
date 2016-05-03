#pragma once

#include "Globals.h"
#include "cObject.h"
#include "cTexture.h"

class cAsteroid : public cObjectDot, public cRotate {
public:
	cAsteroid();
	cAsteroid(float x, float y);
	~cAsteroid();
};
typedef deque<cAsteroid*> cAsteroids;

class cEnemy : public cColor {
public:
	cEnemy();
	~cEnemy();

	void initilize(int mapsize, int count, string textureName);
	void newEnemy();
	void newEnemy(const float x, const float y, const float angle);
	void newEnemy(const float x, const float y, const float angle, int size);
	void destroy(int dist_iter);
	void display(float x, float y);
	void loop();
	void idle();
	cAsteroids getAsteroids();

private:
	cAsteroids asteroids;
	cTexture texture;
	int mapsize;
	cTimer<long, milli> timer;
};