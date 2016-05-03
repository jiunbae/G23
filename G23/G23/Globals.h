/**
*	by jiun bea, MaybeS
*
*	G23-Project Global.h
*
*	contain global variables, headers, structer.
*/
#pragma once

//this for window
#define GAME_WIDTH	600
#define GAME_HEIGHT 800
#define WIN_F 			0 | 1 | 5

//this for program
#define NAME 			"G23"
#define VERSION 		"1.00"
#define BUILD 			"v150"

#ifdef _WIN32
	#include <windows.h>

	#ifdef _MSC_VER 
		#pragma warning (disable : 4996)
	#endif

#elif __linux__ 
	#include <sys/unistd.h>

#elif __APPLE__
	#include <sys/unidstd.h>

#else
	#error can't define os

#endif

#pragma comment(lib,"glew32.lib")
#include "glew.h"
#include "glut.h"

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "cTimer.h"

static int map_x = 0, map_y = 0;
using namespace std;
