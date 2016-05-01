#include "cGame.h"

cGame::cGame(void)
{
}
cGame::~cGame(void)
{
}

bool cGame::Init(int level)
{
	glMatrixMode(GL_PROJECTION);
	glutSetCursor(GLUT_CURSOR_NONE);
	glLoadIdentity();
	glOrtho(-GAME_WIDTH / 2, GAME_WIDTH / 2, -GAME_HEIGHT / 2, GAME_HEIGHT / 2, -1, 1);

	Scene.initilize();
	return true;
}

void cGame::display()
{
	switch (state)
	{
		case STATE_INIT:
			glClear(GL_COLOR_BUFFER_BIT);
				Scene.display();
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
			Scene.x -= 50;
			break;
		case 'w':
			Scene.y -= 50;
			break;
		case 'd':
			Scene.x += 50;
			break;
		case 's':
			Scene.y += 50;
			break;
		default:
			break;
	}

}

void cGame::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}


void cGame::ReadMouse(int button, int state, int x, int y)
{
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
