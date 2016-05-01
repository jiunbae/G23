#pragma once

#include "Globals.h"

#define SCENE_Xo		  0 
#define SCENE_Yo		  0
#define SCENE_WIDTH		  20
#define SCENE_HEIGHT	  160

class cRect
{
public:
	int left, top, right, bottom;
	cRect() {};
	cRect(int left, int top, int right, int bottom) : left(left), top(top), right(right), bottom(bottom) {};
};

class cScene
{
public:
	cScene(void);
	virtual ~cScene(void);

	bool LoadLevel(int level, int tex_w, int tex_h);
	void Draw(int tex_id,int tex_w,int tex_h,bool run);
	void DrawAnimatedTiles(int tex_id,int tex_w,int tex_h);

private:
};
