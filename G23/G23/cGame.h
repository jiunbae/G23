#pragma once

#include "cScene.h"
#include "cEnemy.h"
#include "cPlayer.h"
#include "cIO.h"

#define FPS 60

enum GAME_STATE {STATE_INIT, STATE_RUN, STATE_PAUSE, STATE_MENU, STATE_LEVEL, STAET_GAMEOVER, STATE_ENDGAME};

#define TOTAL_LEVELS	  2
#define DYNAMIC_FILENAME  "dynamic_layer"

//controls
#define P1_UP		'i'
#define P1_DOWN		'k'
#define P1_LEFT		'j'
#define P1_RIGHT	'l'
#define P1_ATTACK	'z'
#define P1_SKILL	'x'

#define P2_UP		GLUT_KEY_UP
#define P2_DOWN		GLUT_KEY_DOWN
#define P2_LEFT		GLUT_KEY_LEFT
#define P2_RIGHT	GLUT_KEY_RIGHT
#define P2_ATTACK	'*'
#define P2_SKILL	'-'
class cGame : public cVolume<float>
{
public:
	cGame(void);
	virtual ~cGame(void);

	bool initilize(string name);
	void display();
	bool Loop();
	void Finalize();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state);
	void ReadMotion(int x, int y);
	void ReadPassivMotion(int x, int y);

	//Process
	bool Process();
	void Reshape(int w,int h);
	//Output
	void Render();

protected:
	class cObject : public cObjectBox, public cTexture {
	public:
		string name, script, text;
	};

	typedef deque<cObject*> cObjects;

private:
	cTimer<long, milli> timer;
	cScene scene;
	cCamera camera;
	cMouse mouse;
	cData data;

	deque<cObject *> objects;
	cPlayer player;
	cEnemy enemys;

	string fileName;
	string title, mission;
	int state, level;
	unsigned char keys[256];

};

