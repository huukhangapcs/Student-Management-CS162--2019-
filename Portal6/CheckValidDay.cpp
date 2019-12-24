#include"CheckValidDay.h"
bool checkValidDate(int day, int month, int year)
{
	if (year < 1950 || year > 2100) return false;
	if (month < 1 || month > 12) return false;
	if (day < 0 || day > 31) return false;
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			if (day > 29) return false;
		}
		else
		{
			if (day > 28) return false;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30) return false;
	}
	return true;
}
bool checkValidTime(int Hour, int Min)
{
	if (Hour > 23 || Hour < 0 || Min > 59 || Min < 0) return false;
	return true;
}

