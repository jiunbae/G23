#include "cPlayer.h"

cPlayer::cPlayer()
{
	cDot(0, 0);
	cVolume(0, 0);
	cMove(0, 0, 0, 0);
	cRotate(0);
	cColor(make_tuple(0,0,0));
	setVolume(50, 50);
}

cPlayer::~cPlayer()
{
}

void cPlayer::initilize()
{
	weapon.setColor(make_tuple(255,64,64));
	texture.initilize();
	texture.loadTexture(IL_PNG, "Textures/ship.png");
}

void cPlayer::display()
{
	weapon.display();

	glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(getX(), getY(), 0);
		glRotatef(getR(), 0, 0, 1);
		glTranslatef(-getX(), -getY(), 0);
		texture.drawTexture(getX(), getY(), getW(), getH());
	glPopMatrix();
}

void cPlayer::loop()
{
	weapon.loop();

	float r = 360 / 2 / M_PI * asin((mouse.x - getX()) / sqrt(pow(mouse.x - getX(), 2.) + pow(mouse.y - getY(), 2.)));
	r = (((mouse.y - getY() > 0) ? (180 - r) : (r)) < 0) ? (90 - fabs(r) + 270) : ((mouse.y - getY() > 0) ? (180 - r) : (r));
	setR(r);


	if (key_up)
		setVelocity(getVelocity().first, (getVelocity().second >= velocity ? 0 : getVelocity().second) + velocity );
	if (key_down)
		setVelocity(getVelocity().first, (getVelocity().second <= -velocity ? 0 : getVelocity().second) -velocity);
	if (key_left)
		setVelocity((getVelocity().first <= -velocity ? 0 : getVelocity().first)  - velocity, getVelocity().second);
	if (key_right)
		setVelocity((getVelocity().first >= velocity ? 0 : getVelocity().first) + velocity, getVelocity().second);

	if (timer.getDeltaPoint() > 30)
	{
		setVelocity(getVelocity().first * 0.2f, getVelocity().second * 0.2f);
		timer.setDeltaPoint();
	}

	setPosition(move(getX(), getY()));

	if (holdMouse)
		weapon.fire(getX(), getY(), getR());
}

void cPlayer::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	if (press)
	{
		switch (key)	
		{
			case 'a': case 'A':
				key_left = true;
				break;
			case 'w': case 'W':
				key_up = true;
				break;
			case 'd': case 'D':
				key_right = true;
				break;
			case 's': case 'S':
				key_down = true;
				break;
			case 32:
				weapon.fire(getX(), getY(), getR());
				break;
		}
	}
	else
	{
		key_up = false;
		key_down = false;
		key_right = false;
		key_left = false;
		setVelocity(0, 0);
	}
	
}

void cPlayer::ReadMouse(int button, int state)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
			case GLUT_LEFT_BUTTON:
				holdMouse = true;
				break;
			case GLUT_RIGHT_BUTTON:
				break;
			default:
				break;
		}
	}
	else
		holdMouse = false;
}
void cPlayer::ReadMouseMove(float x, float y)
{
	mouse.x = x;
	mouse.y = y;
}
