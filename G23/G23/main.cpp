#include "Globals.h"
#include "cGame.h"

cGame Game;

void AppReshape(int w, int h) 
{
	Game.Reshape(w,h);
}
void AppDisplay()
{
	Game.display();
}
void AppKeyboard(unsigned char key, int x, int y)
{
	Game.ReadKeyboard(key,x,y,true);
}
void AppKeyboardUp(unsigned char key, int x, int y)
{
	Game.ReadKeyboard(key,x,y,false);
}
void AppSpecialKeys(int key, int x, int y)
{
	Game.ReadSpecialKeyboard(key,x,y,true);
}
void AppSpecialKeysUp(int key, int x, int y)
{
	Game.ReadSpecialKeyboard(key,x,y,false);
}
void AppMouse(int button, int state, int x, int y)
{
	Game.ReadMouse(button,state,x,y);
}
void AppIdle()
{
	if(!Game.Loop()) 
		exit(0);
}

void main(int argc, char** argv)
{
	int res_x,res_y,pos_x,pos_y;

	srand(time(NULL));

	//GLUT initialization
	glutInit(&argc, argv);

	//RGBA with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );

	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x>>1)-(GAME_WIDTH>>1);
	pos_y = (res_y>>1)-(GAME_HEIGHT>>1);
	
	glutInitWindowPosition(pos_x,pos_y);
	glutInitWindowSize(GAME_WIDTH,GAME_HEIGHT);
	glutCreateWindow("G23");

	//Register callback functions
	glutReshapeFunc(AppReshape);
	glutDisplayFunc(AppDisplay);
	glutKeyboardFunc(AppKeyboard);
	glutKeyboardUpFunc(AppKeyboardUp);
	glutSpecialFunc(AppSpecialKeys);
	glutSpecialUpFunc(AppSpecialKeysUp);
	glutMouseFunc(AppMouse);
	glutIdleFunc(AppIdle);

	//GLEW initialization
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) 
		exit(EXIT_FAILURE);

	//Game initializations
	Game.Init(1);

	//Application loop
	glutMainLoop();	
}
