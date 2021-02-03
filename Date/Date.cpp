#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;
Date::Date()
{
	day = 6;
	month = 1;
	year = 18;
}
int Date::noOfDayInMonth()
{
	if (month <= 7 && month % 2 != 0 || month > 7 && month % 2 == 0)
	{
		return 31;
	}
	else if (month == 2)
	{
		if (leapYear() == true)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else
	{
		return 30;
	}
}
bool Date::leapYear()
{
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
	{
		return true;
	}
	if (year % 4 == 0 && year % 100!=0)
	{
		return true;
	}
	return false;  
}
void Date::setDay(int d)
{
	if (d >= 1 && d <= noOfDayInMonth())
	{
		day = d;
	}
	else
	{
		day = 16;
	}
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		month = 10;
	}
}
void Date::setYear(int y)
{
	if (y >= 0)
	{
		year = y;
	}
	else
	{
		year = 2018;
	}
}
void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}
void Date::ddmmyyFormat()
{
	cout << setw(2) << setfill('0') << day << " : ";
	cout << setw(2) << setfill('0') << month << " : ";
	cout << setw(4) << setfill('0') << year << endl;
}
void Date::incDay(int d)
{
	day = day + d;
	if (day > noOfDayInMonth())
	{
		do
		{
			day = day - noOfDayInMonth();
			incMonth();
		} while (day > noOfDayInMonth());
	}
}
void Date::incMonth(int m)
{
	month = month + m;
	if (month > 12)
	{
		incYear(month / 12);
		setMonth(month % 12);
	}
}
void Date::incYear(int y)
{
	year = year + y;
}