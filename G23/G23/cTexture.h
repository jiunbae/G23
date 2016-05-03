#pragma once

#include "Globals.h"
#pragma comment(lib,"DevIL.lib")
#pragma comment(lib,"ilut.lib")
#pragma comment(lib,"ilu.lib")

#include "Il/il.h"
#include "IL/ilu.h"

class cTexture
{
public:
	cTexture(void);
	~cTexture(void);

	void initilize();

	bool loadTexture(ILenum fileType, string fileName);
	
	void drawTexture(float x, float y);
	void drawTexture(float x, float y, float width, float height);

	int  getID();
	pair<GLuint, GLuint> getSize();

private:
	GLuint id;
	GLubyte * imageData;
	GLuint width, height, bpp;
};
