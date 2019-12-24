#include"ViewSchedule.h"
#include"DesignAffect.h"
void viewSchedule(string acaYear, string  term, string Class)
{
	string year = acaYear;
	string trm = term;
	string css = Class;
	int i = 0;
	gotoxy(100, 9);
	TextColor(6);
	cout << "<< Schedule of Class " << css << " " << term << " " << year << ": " << endl;
	TextColor(11);
	gotoxy(60, 11);
	cout << "MON : ";
	findDate(year, trm, css, "Mon",i);
	TextColor(11);
	gotoxy(90, 11);
	cout << "TUE : ";
	findDate(year, trm, css, "Tue",i);
	TextColor(11);
	gotoxy(120, 11);
	cout << "WED : ";
	findDate(year, trm, css, "Wed",i);
	TextColor(11);
	gotoxy(60, 16);
	cout << "THU : ";
	findDate(year, trm, css, "Thu",i);
	TextColor(11);
	gotoxy(90, 16);
	cout << "FRI : ";
	findDate(year, trm, css, "Fri",i);
	TextColor(11);
	gotoxy(120, 16);
	cout << "SAT : ";
	findDate(year, trm, css, "Sat",i);
	
}
void findDate(string year, string term, string clss, string day,int& i)
{
	ifstream fin;
	TextColor(15);
	fin.open(year + "_" + term + ".txt");
	if (!fin.is_open())
	{
		cout << "NOT EXISTED COURSE.";
	
		return;
	}
	schedule sc;
	string x;
	string no, id, name, className, lec, std, end;
	getline(fin, x); 
	int m = 0;
		while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, className, ',');
		getline(fin, lec, ',');
		getline(fin, std, ',');
		getline(fin, end, ',');
		getline(fin, sc.date, ',');
		getline(fin, sc.sth, ',');
		getline(fin, sc.enh, ',');
		getline(fin, sc.room);
		if (sc.date == day && className == clss)
		{
			if (i < 9)
			{
				gotoxy(60 + i * 10, 12 + m);
				cout << id << "< " << sc.sth << "-" << sc.enh << "," << sc.room << ">     ";
				m + 2;
			}
			else {
				gotoxy( i * 10-30, 17 + m);
				cout << id << "< " << sc.sth << "-" << sc.enh << "," << sc.room << ">     ";
				m + 2;

			}
		}


	}
		i+=3;
	fin.close();
}