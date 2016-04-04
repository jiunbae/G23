/**
	by jiun bea, MaybeS

	G23-Project Global.h

	contain global variables, headers, structer.
*/
#pragma once

//this for window
#define WIN_X 			800
#define WIN_Y 			600
#define WIN_F 			0 | 1 | 5

//this for program
#define NAME 			"G23"
#define VERSION 		"1.00"
#define BUILD 			"MSVCP_150"

#ifdef WIN32_ || WIN64_
	#include <windows.h>
	#ifdef MSVCP_
		#pragma warning (disable : 4996)
	#endif
#elif LINUX_ || AMD64_
	#include <sys/unistd.h>
#endif
	
