#pragma once

#include "Globals.h"

typedef unsigned char colorByte;
typedef tuple<colorByte, colorByte, colorByte> colorType;

class cColor {
public:
	cColor();
	cColor(colorType _color);
	~cColor();

	void setColor(colorType _color);
	colorType getColor();

private:
	colorType color;
};

class cRotate {
public:
	cRotate() {}
	cRotate(float _r) : r(_r) {}
	~cRotate() {}

	void setR(float _r) { r = _r; }
	float getR() { return r; }

private:
	float r;
};

template <typename T>
class cDot {
public:
	cDot() {}
	cDot(T _x, T _y) : x(_x), y(_y) {}
	~cDot() {}

	void setX(T _x) { x = _x; }
	void setY(T _y) { y = _y; }
	void setPosition(T _x, T _y) { setX(_x); setY(_y); }
	void setPosition(pair<T, T> xy) { setX(xy.first); setY(xy.second); }
	T getX() { return x; }
	T getY() { return y; }
	pair<T, T> getPosition() { return{ x,y }; };

private:
	T x, y;
};

template <typename T>
class cVolume {
public:
	cVolume() {};
	cVolume(T _w, T _h) : w(_w), h(_h) {};
	~cVolume() {};

	void setW(T _w) { w = _w; }
	void setH(T _h) { h = _h; }
	void setVolume(T _w, T _h) { setW(_w);setH(_h); };
	T getW() { return w; }
	T getH() { return h; }
	pair<T, T> getVolume() { return{ w,h }; };

private:
	T w, h;
};

template <typename T>
class cMove {
public:
	cMove() {}
	cMove(T _vx, T _vy) : vx(_vx), vy(_vy) {}
	cMove(T _vx, T _vy, T _ax, T _ay) : ax(_ax), ay(_ay) { cMove(_vx, _vy); }
	~cMove() {}

	pair<T, T> move(T x, T y)
	{
		x += vx;
		y += vy;
		vx += ax;
		vy += ay;
		return{ x,y };
	}

	void setVx(T _x)
	{
		vx = _x;
	}
	void setVy(T _y)
	{
		vy = _y;
	}
	void setVelocity(T x, T y)
	{
		setVx(x);
		setVy(y);
	}
	T getVx()
	{
		return vx;
	}
	T getVy()
	{
		return vy;
	}
	pair<T, T> getVelocity()
	{
		return{ vx,vy };
	}

	void setAx(T _x)
	{
		ax = _x;
	}
	void setAy(T _y)
	{
		ay = _y;
	}
	void setAcceleration(T x, T y)
	{
		setAx(x);
		setAy(y);
	}
	T getAx()
	{
		return ax;
	}
	T getAy()
	{
		return ay;
	}
	pair<T, T> getAcceleration()
	{
		return{ ax,ay };
	}

private:
	T vx, vy, ax, ay;
};

class cObjectDot : public cDot <float>, public cMove <float> {
public:
	cObjectDot();
	cObjectDot(float x, float y);
	cObjectDot(float x, float y, float vx, float vy);
	cObjectDot(float x, float y, float vx, float vy, float ax, float ay);
	~cObjectDot();

	void setState(int _state);
	int getState();

	bool isValid();

private:
	int state = 0;
};

class cObjectBox : public cObjectDot, public cVolume<float>, public cColor, public cRotate {
public:
	cObjectBox();
	cObjectBox(float x, float y);
	cObjectBox(float x, float y, float w, float h);
	~cObjectBox();

private:
	
};