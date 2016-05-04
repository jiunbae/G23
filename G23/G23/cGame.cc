#include "cGame.h"

cGame::cGame(void)
{
	fileName = "levels/main.xml";
}
cGame::~cGame(void)
{
}

bool cGame::initilize(string name)
{
	glMatrixMode(GL_PROJECTION);
	//glutSetCursor(GLUT_CURSOR_NONE);
	glLoadIdentity();
	glOrtho(-GAME_WIDTH / 2, GAME_WIDTH / 2, -GAME_HEIGHT / 2, GAME_HEIGHT / 2, -1, 1);

	dataClass datas = data.loadMap(name);
	setVolume(datas.size, datas.size);
	title = datas.title;
	mission = datas.mission;

	objects.clear();
	for (__data__object__ dob : datas.objects)
	{
		cObject * object = new cObject();
		object->setPosition(dob.x, dob.y);
		object->setVolume(dob.w, dob.h);
		object->name = dob.name;
		object->text = dob.text;
		object->script = dob.script;
		object->initilize();
		object->loadTexture(IL_PNG, dob.texture);
		objects.push_back(object);
	}
	
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

			initilize(fileName);
			this->player.setPosition(0, 0);
			state = STATE_PAUSE;
			break;

		case STATE_PAUSE:
			glClear(GL_COLOR_BUFFER_BIT);

			glColor3f(1.0f, 1.0f, 1.0f);
			scene.display(camera.getX(), camera.getY());
			glText(-100, -50, "Press spacebar to start");
			glText(-25, 50, title);
			glText(-50, 25, mission);
			break;
		case STATE_RUN:

			enemys.loop();
			player.setCameraPosition(camera.getX(), camera.getY());
			player.loop();

			glClear(GL_COLOR_BUFFER_BIT);
			scene.display(camera.getX(), camera.getY());
			enemys.display(camera.getX(), camera.getY());
			player.display(camera.getX(), camera.getY());

			for (cObject * object : objects)
			{
				glPushMatrix();
				glColor3f(1, 1, 1);
				glTranslatef(object->getX() - camera.getX(), object->getY() - camera.getY(), 0);
				glRotatef(0, 0, 0, 1);
				glTranslatef(-object->getX() + camera.getX(), -object->getY() + camera.getY(), 0);
				object->drawTexture(object->getX() - camera.getX(), object->getY() - camera.getY());
				glPopMatrix();
			}

			break;
		case STATE_ENDGAME:
			glColor3f(1.0f, 1.0f, 1.0f);
			scene.display(camera.getX(), camera.getY());
			glText(-20, 30, "you die!!");
			glText(-100, 0, "Press spacebar to restart");
			
			break;
		default:
			break;
	}
	glutSwapBuffers();
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
		if (distDot((*ia)->getPosition(), player.getPosition()) < .3f * (*ia)->getState())
		{
			state = STATE_ENDGAME;
			break;
		}
	}
	for (cObjects::const_iterator io = objects.begin(); io != objects.end(); ++io)
	{
		if (distDot((*io)->getPosition(), player.getPosition()) < .5f * (*io)->getW())
		{
			fileName = (*io)->script;
			state = STATE_INIT;
		}
	}
	
	if (timer.getDeltaPoint() > 0)
	{
		timer.setDeltaPoint();
		if (distDot(camera.getPosition(), player.getPosition()) > 30.f)
			camera.setPosition({ camera.getX() + (player.getX() - camera.getX()) * 0.1f, camera.getY() + (player.getY() - camera.getY()) * 0.1f });
	}

	display();

	return true;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	switch (state)
	{
		case STATE_PAUSE:
			switch (key)
			{
				case ' ':
					state = STATE_RUN;
					break;
			}
			break;
		case STATE_RUN:
			player.ReadKeyboard(key, x, y, press);
			break;
		case STATE_ENDGAME:
			switch (key)
			{
				default:
				{
					state = STATE_INIT;
					display();
				}
			}
			break;
		default:
			break;
	}
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
	player.ReadMouseMove(mouse.x, -mouse.y);
}

void cGame::ReadPassivMotion(int x, int y)
{
	mouse.initilize(x, y);
	player.ReadMouseMove(mouse.x, -mouse.y);
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
