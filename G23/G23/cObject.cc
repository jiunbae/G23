#include "cObject.h"

cObject::cObject(void)
{
	state = STATE_NOR;
}
cObject::~cObject(void){}

void cObject::SetPosition(int posx,int posy)
{
	x = posx;
	y = posy;
}
void cObject::SetX(int posx)
{
	x = posx;
}
int cObject::GetX()
{
	return x;
}
void cObject::SetY(int posy)
{
	y = posy;
}
int cObject::GetY()
{
	return y;
}
void cObject::SetBaseTilesHeight(int bth)
{
	base_tiles_h = bth;
}
int cObject::GetBaseHeight()
{
	return base_tiles_h*TILE_SIZE;
}
void cObject::SetBaseTilesWidth(int btw)
{
	base_tiles_w = btw;
}
int cObject::GetBaseWidth()
{
	return base_tiles_w*TILE_SIZE;
}
void cObject::SetHitHeight(int hh)
{
	hit_h = hh;
}
int cObject::GetHitHeight()
{
	return hit_h;
}
void cObject::SetHitWidth(int hw)
{
	hit_w = hw;
}
int cObject::GetHitWidth()
{
	return hit_w;
}

cRect cObject::GetHitBox()
{
	return cRect( y + hit_h, y, x, x + hit_w );
}
bool cObject::Intersection(cRect box1, cRect box2)
{
	if(box1.top > box2.bottom && box2.top > box1.bottom)
	{
		if(box1.left < box2.right && box2.left < box1.right) return true;
	}
	return false;
}
bool cObject::Intersection(cRect box1, int px, int py)
{
	if(px >= box1.left && px < box1.right && py >= box1.bottom && py < box1.top) return true; 
	return false;
}

int cObject::GetState()
{
	return state;
}
void cObject::SetState(int s)
{
	state = s;
}

bool cObject::IsLooking()
{
	//if( state == STATE_LOOKUP   || state == STATE_LOOKDOWN || 
	//    state == STATE_LOOKLEFT || state == STATE_LOOKRIGHT ) return true;
	return false;
}
bool cObject::IsWalking()
{
	//if( state == STATE_WALKUP   || state == STATE_WALKDOWN || 
	//    state == STATE_WALKLEFT || state == STATE_WALKRIGHT ) return true;
	return false;
}
bool cObject::IsAttacking()
{
	//if( state == STATE_ATTACKUP   || state == STATE_ATTACKDOWN  || 
	//    state == STATE_ATTACKLEFT || state == STATE_ATTACKRIGHT  ) return true;
	return false;
}
bool cObject::IsDamaged()
{
	//if( state == STATE_DAMAGEUP   || state == STATE_DAMAGEDOWN || 
	//    state == STATE_DAMAGELEFT || state == STATE_DAMAGERIGHT ) return true;
	return false;
}
