#include "cGame.h"

cGame::cGame(void)
{
}
cGame::~cGame(void)
{
}

bool cGame::Init(int level)
{
	return true;
}

bool cGame::Loop()
{
	return true;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
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
	int tex_w,tex_h;
	int tex_w2,tex_h2;
	bool run = (state == STATE_RUN);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	//Activacion de shaders
	if(epilepsia_mode)
	{
		time += 0.8f;
		if(time >= 180.0f) time = 0.0f;
		glActiveTexture(GL_TEXTURE0);
		Shader.Attach(SHADER_EPILEPTIC_F);
		Shader.Activate();
		Shader.SetUniform("time", abs(sin(time)));
		Shader.SetUniform("tex", 0);
		Shader.SetUniform("flatcolor", 0);
	}
	else if(time > 0.0f)
	{
		glActiveTexture(GL_TEXTURE0);
		if(state == STATE_GAMEOVER) Shader.Attach(SHADER_GREYSCALEFADE_F);
		else Shader.Attach(SHADER_FADE_F);
		Shader.Activate();
		Shader.SetUniform("time", time);
		Shader.SetUniform("tex", 0);
		Shader.SetUniform("flatcolor", 0);
	}

	//Pintado
	Data.GetSize(IMG_TILESET,&tex_w,&tex_h);
	Scene.Draw(Data.GetID(IMG_TILESET),tex_w,tex_h,run);


	Data.GetSize(IMG_HEART,&tex_w,&tex_h);

	Overlay1.Draw(Data.GetID(IMG_OVERLAY1));
	Overlay2.Draw(Data.GetID(IMG_OVERLAY2));
	glDisable(GL_BLEND);        
	glAlphaFunc(GL_GREATER, 0.05f);

	if(epilepsia_mode)
	{
		Shader.Detach(SHADER_EPILEPTIC_F);
		Shader.Deactivate();
	}
	else if(time > 0.0f)
	{
		if(state == STATE_GAMEOVER) Shader.Detach(SHADER_GREYSCALEFADE_F);
		else {Shader.Detach(SHADER_FADE_F); time -= 0.01f;}
		Shader.Deactivate();
	}

	glutSwapBuffers();
}
