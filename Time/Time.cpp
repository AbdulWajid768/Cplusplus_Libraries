#include<iostream>
#include<iomanip>
#include"Time.h"
using namespace std;
Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
}
Time::Time(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}
void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
	}
}
void Time::setMinute(int m)
{
	if (m >= 0 && m <= 59)
	{
		minute = m;
	}
}
void Time::setSecond(int s)
{
	if (s >= 0 && s <= 59)
	{
		second = s;
	}
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);

}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}
int Time::getSecond()
{
	return second;
}
void Time::printTwentyFourHourFormat()
{
	cout << setw(2) << setfill('0') << hour << " : ";
	cout << setw(2) << setfill('0') << minute << " : ";
	cout << setw(2) << setfill('0') << second << endl;
}
void Time::printTwelveHourFormat()
{
	if (hour == 0)
	{
		cout << setw(2) << setfill('0') << hour + 12 << " : ";
		cout << setw(2) << setfill('0') << minute << " : ";
		cout << setw(2) << setfill('0') << second << " AM" << endl;
	}
	else if (hour > 12)
	{
		cout << setw(2) << setfill('0') << hour - 12 << " : ";
		cout << setw(2) << setfill('0') << minute << " : ";
		cout << setw(2) << setfill('0') << second << " PM" << endl;
	}
	else
	{
		cout << setw(2) << setfill('0') << hour << " : ";
		cout << setw(2) << setfill('0') << minute << " : ";
		cout << setw(2) << setfill('0') << second << " AM" << endl;
	}
}
void Time::incHour(int h)
{
	hour = hour + h;
	if (hour >= 24)
	{
		hour = hour % 24;
	}
}
void Time::incMin(int m)
{
	minute = minute + m;
	if (minute > 59)
	{
		incHour(minute / 60);
		minute = minute % 60;
	}
}
void Time::incSec(int s)
{
	second = second + s;
	if (second > 59)
	{
		incMin(second / 60);
		second = second % 60;
	}
}
