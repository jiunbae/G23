#pragma once

#include "cScene.h"

#define STEP_LENGTH	  (TILE_SIZE/8)

enum STATE{STATE_DIE, STATE_NOR, STATE_INF, STATE_STP};

class cObject
{
public:
	cObject(void);
	virtual ~cObject(void);

	void SetPosition(int x,int y);
	void SetX(int x);
	int  GetX();
	void SetY(int y);
	int  GetY();
	void SetBaseTilesHeight(int bth);
	int  GetBaseHeight();
	void SetBaseTilesWidth(int btw);
	int  GetBaseWidth();
	void SetHitHeight(int hh);
	int GetHitHeight();
	void SetHitWidth(int hw);
	int GetHitWidth();

	void SetState(int s);
	int  GetState();

	bool IsLooking();
	bool IsWalking();
	bool IsAttacking();
	bool IsDamaged();

	cRect GetHitBox();
	bool Intersection(cRect box1, cRect box2);
	bool Intersection(cRect box1,int px,int py);

	virtual void Draw(int tex_id,int tex_w,int tex_h,bool run) {};

	void Stop();
private:
	int x, y, hit_w, hit_h, base_tiles_w, base_tiles_h, state;
};

template <typename T>
class cMove {
public:
	cMove() {}
	~cMove() {};

	void move()
	{
		x += vx;
		y += vy;
		vx += ax;
		vy += ay;
	}

	void setX(T _x)
	{
		x = _x;
	}
	T getX()
	{
		return x;
	}
	void setY(T _y)
	{
		y = _y;
	}
	T getY()
	{
		return y;
	}
	void setPosition(T x, T y)
	{
		setX(x);
		setY(y);
	}
	pair<T, T> getPosition()
	{
		return{ x,y };
	}

	void setVx(T _x)
	{
		vx = _x;
	}
	T getVx()
	{
		return vx;
	}
	void setVy(T _y)
	{
		vy = _y;
	}
	T getVy()
	{
		return vy;
	}
	void setVelocity(T x, T y)
	{
		setVx(x);
		setVy(y);
	}
	pair<T, T> getVelocity()
	{
		return{ vx,vy };
	}

	void setAx(T _x)
	{
		ax = _x;
	}
	T getAx()
	{
		return ax;
	}
	void setAy(T _y)
	{
		ay = _y;
	}
	T getAy()
	{
		return ay;
	}
	void setAcceleration(T x, T y)
	{
		setAx(x);
		setAy(y);
	}
	pair<T, T> getAcceleration()
	{
		return{ ax,ay };
	}

	bool isValid()
	{
		if ((x < 0 && vx <0) || (y < 0 && vy < 0) || (x > GAME_WIDTH && vx > 0) || (y > GAME_HEIGHT && vy > 0))
			return false;
		return true;
	}

private:
	T x, y, vx, vy, ax, ay;
};
