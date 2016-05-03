#include "cGame.h"

cGame::cGame(void)
{

}
cGame::~cGame(void)
{
}

bool cGame::initilize(int level)
{
	glMatrixMode(GL_PROJECTION);
	//glutSetCursor(GLUT_CURSOR_NONE);
	glLoadIdentity();
	glOrtho(-GAME_WIDTH / 2, GAME_WIDTH / 2, -GAME_HEIGHT / 2, GAME_HEIGHT / 2, -1, 1);

	dataClass datas = data.loadMap("Levels\\main.xml");
	setVolume(datas.size, datas.size);
	title = datas.title;
	mission = datas.mission;
	
	enemys.initilize(datas.size, datas.astroids.count ,datas.astroids.texture);

	scene.initilize();
	player.initilize();
	return true;
}

void cGame::display()
{
	switch (state)
	{
		case STATE_INIT:
			glClear(GL_COLOR_BUFFER_BIT);
				scene.display();
				enemys.display();
				player.display();
			glutSwapBuffers();
			break;
		case STATE_RUN:
			break;
		default:
			break;
	}
}

bool cGame::Loop()
{
	enemys.loop();
	player.loop();
	display();
	return true;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	switch (key)
	{
		case 'a':
			scene.x -= 50;
			break;
		case 'w':
			scene.y -= 50;
			break;
		case 'd':
			scene.x += 50;
			break;
		case 's':
			scene.y += 50;
			break;
		default:
			break;
	}
	player.ReadKeyboard(key, x, y, press);
}

void cGame::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}


void cGame::ReadMouse(int button, int state)
{
	player.ReadMouse(button, state);
}

void cGame::ReadMotion(int x, int y)
{
	mouse.initilize(x, y);
	player.ReadMouseMove(mouse.x, mouse.y);
}

void cGame::ReadPassivMotion(int x, int y)
{
	mouse.initilize(x, y);
	player.ReadMouseMove(mouse.x, mouse.y);
}

//Process
bool cGame::Process()
{
	return true;
}

void cGame::Reshape(int w,int h)
{
	glViewport(0,0,w,h);
}

//Output
void cGame::Render()
{
	glutSwapBuffers();
}
