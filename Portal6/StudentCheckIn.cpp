#include"StudentCheckIn.h"
#include"DesignAffect.h"
void studentCheckin(string id, string className, int curWeek)// doc tu file student login khi dang nhap
{
	string acaYear, term;
	getAcayearvsTerm(acaYear, term);
	//
	string day, month, year;
	getDayMonthYear(day, month, year);
	TextColor(11);
	gotoxy(100, 10);
	cout << "////  T O D A Y  : " << day << "  /  " << month << "  /   " << year;
	gotoxy(100, 12);
	TextColor(12);
	cout << "    <>    W E E K: " << curWeek << "      <>";
	//
	string dayofW;
	getWeekDay(dayofW);
	//
	TextColor(15);
	gotoxy(100, 14);
	cout << "<<<0 : C O U R S E  T O D A Y : 0>>>" ;
	Schedule *sc = new Schedule[10];
	int dem = 0;
	loadCheckinList(acaYear, term, className, sc, dem);
	int count = 0;
	TextColor(6);
	for (int i = 0; i < dem; i++)
	{
		if (sc[i].dayofW == dayofW)
		{
			gotoxy(100, 16+count*2 );
			cout << count + 1 << "." << sc[i].CourseId << " : " << sc[i].stHour << "-" << sc[i].enHour ;
			count++;
		}
	}
	if (count == 0)
	{
		gotoxy(110, 20);
		cout << " No courses today." ;
		return;
	}
	gotoxy(110, 20);
	TextColor(12);
	cout << "Please choose to check in: ";
	int n;
	cin >> n;
	if (n > count) return;
	
	else
	{
		string crid;
		int x = 0;
		for (int i = 0; i < dem; i++)
		{
			if (sc[i].dayofW == dayofW) x++;
			if (x == n)
			{
				crid = sc[i].CourseId;
				break;
			}
		}
		Attendance at;
		loadAttendance(acaYear, term, className, at, id, crid);
		for (int i = 0; i < curWeek - 1; i++)
		{
			if (at.check[i] == -1)  at.check[i] = 0;
		}
		if (at.check[curWeek - 1] == 0 || at.check[curWeek - 1] == 1)
		{
			gotoxy(110, 27);
			TextColor(15);
			cout << "You had already checked";
			return;
		}
		at.check[curWeek - 1] = 1;
		saveCheckin(acaYear, term, className, crid, at);
		gotoxy(110, 27);
		TextColor(15);
		cout << "CHECK-IN SUCCESSFULLY!  ";

	}
	delete[]sc;
}
bool loadCheckinList(string acaYear, string term, string className, Schedule *&sc, int &dem)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + ".txt");
	if (!fin.is_open()) return false;
	string x;
	string no, name, clss, lecA, std, end, room;
	string id, day, sth, enh;
	getline(fin, x);// trash
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, clss, ',');
		getline(fin, lecA, ',');
		getline(fin, std, ',');
		getline(fin, end, ',');
		getline(fin, day, ',');
		getline(fin, sth, ',');
		getline(fin, enh, ',');
		getline(fin, room);
		if (no != "" && clss == className)
		{
			sc[dem].CourseId = id;
			sc[dem].dayofW = day;
			sc[dem].stHour = sth;
			sc[dem].enHour = enh;
			dem++;
		}
	}
	fin.close();
	return true;
}
bool loadAttendance(string acaYear, string term, string className, Attendance &at, string stdid, string cId)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open()) return false;
	string x;
	string no, id, ln, fn, check;
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, ln, ',');
		getline(fin, fn, ',');
		if (no != "" && id == stdid)
		{
			at.stdId = id;
			at.stdLName = ln;
			at.stdFName = fn;
			for (int i = 0; i < 10; i++)
			{
				if (i < 9)
					getline(fin, check, ',');
				else
					getline(fin, check);
				if (check == "X") at.check[i] = 1;
				else if (check == "O") at.check[i] = 0;
				else at.check[i] = -1;
			}
			break;
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (i < 9)
					getline(fin, check, ',');
				else
					getline(fin, check);
			}
		}
	}
	return true;
}
void saveCheckin(string year, string term, string className, string cId, Attendance at)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	string content;
	string no, id, remain;
	getline(fin, content);
	content += "\n";
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (id != at.stdId)
			{
				content += no + "," + id + "," + remain + "\n";
			}
			else
			{
				content += no + "," + id + "," + at.stdLName + "," + at.stdFName + ",";
				for (int i = 0; i < 10; i++)
				{
					if (i < 9)
					{
						if (at.check[i] == -1) content += "-,";
						else if (at.check[i] == 0) content += "O,";
						else if (at.check[i] == 1) content += "X,";
					}
					else
					{
						if (at.check[i] == -1) content += "-\n";
						else if (at.check[i] == 0) content += "O\n";
						else if (at.check[i] == 1) content += "X\n";
					}
				}
			}
		}
	}

	ofstream fout;
	fout.open(year + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	fout << content;
	fout.close();
}