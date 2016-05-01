#pragma once

#include "cObject.h"
#include "cData.h"
#include "cShader.h"
#include "cTimer.h"
#include "cEnemy.h"
#include "cPlayer.h"
#include "cScene.h"

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

class cGame
{
public:
	cGame(void);
	virtual ~cGame(void);

	bool Init(int level);
	void display();
	bool Loop();
	void Finalize();

	//Input
	void ReadKeyboard(unsigned char key, int x, int y, bool press);
	void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	void ReadMouse(int button, int state, int x, int y);
	//Process
	bool Process();
	void Reshape(int w,int h);
	//Output
	void Render();

private:
	cTimer<long, milli> timer;
	int state, level;
	cScene Scene;
	//cOverlay Overlay1;
	//cOverlay Overlay2;

	unsigned char keys[256];
	cRect visible_area;

	cEnemy enemys;
	cPlayer player;

	cData Data;
	cShader Shader;
	
	float time;
	bool ia, epilepsia_mode;

	void UpdateCamera(int h1,int h2);
	bool LoadDynamicLayer(int lvl);
};
