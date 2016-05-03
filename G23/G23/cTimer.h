#pragma once
#include <chrono>

using namespace std::chrono;
typedef system_clock::time_point timePoint;

/**
	Time Class for detail timer.
	template<returnType, castType>
	l
	ex: Time<long long, std::nano>
	l
	method:
	l	getTimePoint(return timePoint(now))
	l	setDeltaPoint(save now point)
	l	getDeltaPoint(return delta of set time(by setDeltaPoint) between now)
	l	getDeltaTimePoint(return delta of input time between now)
	l	convertPoint(return returnType value, using input timePoint)
	l	getTime(return now time)
*/
template<typename R, typename T>
class cTimer {
public:
	cTimer() {}
	~cTimer() {}
	timePoint getTimePoint()
	{
		return getPoint();
	}
	void setDeltaPoint()
	{
		flag = getPoint();
	}
	R getDeltaPoint()
	{
		if (flag == timePoint())
			return (R)LONG_MAX;
		return duration_cast<duration<R, T>>(getPoint() - flag).count();
	}
	R getDeltaTimePoint(const timePoint& tp)
	{
		return duration_cast<duration<R, T>>(getPoint() - tp).count();
	}
	R convertPoint(const timePoint& tp)
	{
		return duration_cast<duration<R, T>>(tp.time_since_epoch()).count();
	}
	R getTime()
	{
		return duration_cast<duration<R, T>>(system_clock::now().time_since_epoch()).count();
	}
private:
	system_clock::time_point flag ;
	system_clock::time_point getPoint()
	{
		return system_clock::now();
	}
};
