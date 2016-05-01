#pragma once

#include "cObject.h"

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

class cPlayer: public cObject
{
public:
	cPlayer();
	~cPlayer();

	void initilize();
	void display();
	void loop();
	void idle();


private:
	int level, score, hp, mp, max_hp, max_mp;
};