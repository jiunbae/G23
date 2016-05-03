#pragma once

#include "Globals.h"
#include "cObject.h"
#include "cWeapon.h"
#include "cTexture.h"
#include "cIO.h"

#define CHARGE_BREAK   30
#define COOLDOWN		6

#define SUPERATTACK_COST 60
#define ATTACK_COST		 10

#define STATE_SUPERATTACK	 18

#define STATE_SKILLUP		 19
#define STATE_SKILLRIGHT	 20
#define STATE_SKILLDOWN		 21
#define STATE_SKILLLEFT		 22

#define STATE_SKILLWALKUP	 23
#define STATE_SKILLWALKRIGHT 24
#define STATE_SKILLWALKDOWN	 25
#define STATE_SKILLWALKLEFT	 26

class cPlayer: public cObjectBox
{
public:
	cPlayer();
	~cPlayer();

	void initilize();
	void display();
	void loop();
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state);
	void ReadMouseMove(float x, float y);

	cWeapon	weapon;

private:
	bool key_up = false, key_down = false, key_left = false, key_right = false;
	float velocity = 0.5f, acceleration;
	int level, score, hp, mp, max_hp, max_mp;
	bool holdMouse;
	cTexture texture;
	cMouse mouse;
	cTimer<long, milli> timer;

};