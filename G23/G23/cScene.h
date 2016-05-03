#pragma once

#include "Globals.h"
#include "cObject.h"

#define SCENE_Xo		  0 
#define SCENE_Yo		  0
#define SCENE_WIDTH		  20
#define SCENE_HEIGHT	  160

class cCamera : public cDot<float>, public cVolume<float>, public cRotate {
public:
	cCamera();
	~cCamera();

	void updateCamera(float x, float y);
	void updateRatio(float r);
private:
};

class cScene
{
public:
	float x, y;
	cScene(void);
	~cScene(void);

	void initilize();
	bool LoadLevel(int level);
	void display();

protected:
	class backDot : public cDot<float>, public cColor {
	public:
		backDot(int x, int y, colorType color ) : cDot(x,y) , cColor(color) {}
	};
private:
	deque<backDot*> backs;

	void backDisplay();
};
