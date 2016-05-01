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

	bool loatTexture(ILenum fileType, string fileName);
	
	void drawTexture(float x, float y, int type);
	void drawTexture(float x, float y, int type, float width, float height);

	int  getID();
	pair<GLuint, GLuint> getSize();

private:
	GLuint id;
	GLubyte * imageData;
	GLuint width, height, bpp;
};
