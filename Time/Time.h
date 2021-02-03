class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int h, int m, int s);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	void setTime(int h, int m, int s);
	int getHour();
	int getMinute();
	int getSecond();
	void printTwentyFourHourFormat();
	void printTwelveHourFormat();
	void incHour(int h = 1);
	void incMin(int m = 1);
	void incSec(int s = 1);
};