class Date
{
	int day;
	int month;
	int year;
	bool leapYear();
	int noOfDayInMonth();
public:
	Date();
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void setDate(int d, int m, int y);
	int getDay();
	int getMonth();
	int getYear();
	void ddmmyyFormat();
	void incDay(int d = 1);
	void incMonth(int m = 1);
	void incYear(int y = 1);
};