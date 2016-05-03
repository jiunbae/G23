#pragma once

#include "Globals.h"

class cMouse {
public:
	float x, y;
	cMouse() : x(0), y(0) {}

	void initilize(int _x, int _y);
	void display();
};

typedef struct {
	string name, texture;
	float x, y, r, w, h;
} __data__object__;
typedef struct {
	string texture;
	int count;
	int size;
} __data__astroids__;

class dataClass {
public:
	string title, mission;
	int size;
	__data__astroids__ astroids;
	vector<__data__object__> objects;
};

class cData {
public:
	dataClass loadMap(string fileName);
	void saveData(dataClass datas, string fileName);
};