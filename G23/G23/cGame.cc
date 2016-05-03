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
				scene.display(camera.getX(), camera.getY());
				enemys.display(camera.getX(), camera.getY());
				player.display(camera.getX(), camera.getY());
			glutSwapBuffers();
			break;
		case STATE_RUN:
			break;
		default:
			break;
	}
}

function<float(pair<float, float>, pair<float, float>)> distDot = [](pair<float, float> t, pair<float, float> o)->float {
	return sqrtf(powf(t.first - o.first, 2.f) + powf(t.second - o.second, 2.f));
};

bool cGame::Loop()
{
	cAsteroids asteroids = enemys.getAsteroids();
	cBullets bullets = player.weapon.getBullets();

	for (cAsteroids::iterator ia = asteroids.begin(); ia != asteroids.end(); ++ia)
	{
		for (cBullets::iterator ib = bullets.begin(); ib != bullets.end(); ++ib)
			if (distDot((*ia)->getPosition(), (*ib)->getPosition()) < .2f * (*ia)->getState())
			{
				enemys.destroy(distance(asteroids.begin(), ia));
				player.weapon.destroy(distance(bullets.begin(), ib));
			}
		if (distDot((*ia)->getPosition(), player.getPosition()) < .2f * (*ia)->getState())
		{
			int p = 3;
		}
	}
	
	if (distDot(camera.getPosition(), player.getPosition()) > 30.f)
	{
		camera.setPosition({(player.getX() - camera.getX()) * 0.7f, (player.getY() - camera.getY()) * 0.7f});
	}

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
