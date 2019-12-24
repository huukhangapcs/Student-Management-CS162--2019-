#include"GetcurrentTime.h"
#include"DesignAffect.h"
void getAcayearvsTerm(string &acaYear, string &term)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	if (timePtr->tm_mon < 5)
	{
		term = "term2";
		acaYear = to_string(timePtr->tm_year - 1 + 1900) + "-" + to_string(timePtr->tm_year + 1900);
	}
	else if (timePtr->tm_mon < 9)
	{
		term = "term3";
		acaYear = to_string(timePtr->tm_year - 1 + 1900) + "-" + to_string(timePtr->tm_year + 1900);
	}
	else
	{
		term = "term1";
		acaYear = to_string(timePtr->tm_year + 1900) + "-" + to_string(timePtr->tm_year + 1 + 1900);
	}
}

void getWeekDay(string &dayofweek)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	switch (timePtr->tm_wday)
	{
	case 1: dayofweek = "Mon"; break;
	case 2: dayofweek = "Tue"; break;
	case 3: dayofweek = "Wed"; break;
	case 4: dayofweek = "Thu"; break;
	case 5: dayofweek = "Fri"; break;
	case 6: dayofweek = "Sat"; break;
	case 7: dayofweek = "Sun"; break;
	}

}
void getDayMonthYear(string &day, string &month, string &year)
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	year = to_string(timePtr->tm_year + 1900);
	if (timePtr->tm_mon < 10)
		month = "0" + to_string(timePtr->tm_mon + 1);
	else
		month = to_string(timePtr->tm_mon);
	if (timePtr->tm_mday < 10)
		day = "0" + to_string(timePtr->tm_mday);
	else
		day = to_string(timePtr->tm_mday);
}


void updateCurrentWeek(int &curWeek)
{
	while (1) {
		gotoxy(100, 10);
		TextColor(6);
		cout << "<> C u r r e n t   w e e k: | <>";
		int n=0;
		gotoxy(100, 12);	
		cout << "                        ";
		gotoxy(100, 12);
		TextColor(11);
		cout << "W E E K : " << curWeek;
		gotoxy(100, 14);
		TextColor(15);
		cout << " CLICK ENTER TO UPDATE/ESC TO QUIT.";
		char click = _getch();
		if (click == 13)
		{
			n++;
			if (n == 1 && curWeek < 10) curWeek++;
			else if (n == 1 && curWeek == 10) curWeek = 1;
			ofstream fout;
			fout.open("CurrentWeek.txt");
			fout << curWeek;
			fout.close();
		}
		else if(click==27)
		{
			break;
		}
	}
}
void getCurrentWeek(int &curWeek)
{
	ifstream fin;
	fin.open("CurrentWeek.txt");
	if (!fin.is_open())
	{
		curWeek = 1;
	}
	else
	{
		fin >> curWeek;
		if (curWeek < 1) curWeek = 1;
		fin.close();
	}
}