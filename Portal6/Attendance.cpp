#include"Attendance.h"
#include"DesignAffect.h"
void displayAttendanceOfACourse(char* acaY, char* term, char *courseId, char  *Class)
{
	string y = acaY;
	string t = term;
	string cId = courseId;
	string css = Class;
	ifstream fin;
	fin.open(y + "_" + t + "_" + css + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open())
	{
		gotoxy(110, 20);
		cout << " C A N N O T  V I E W  ";
		return;
	}
	string x;
	string no;
	Attendance at;
	string check;
	getline(fin, x);
	gotoxy(56, 7);
	TextColor(6);
	cout << "A T T E N D A N C E   L I S T |:|"; TextColor(10); gotoxy(90, 7); cout << Class;

	char m;
	TextColor(6);
	for (int i = 0; i <= 125; ++i)
	{
		m = 196;

		gotoxy(58 + i, 8);
		cout << m;
		gotoxy(58 + i, 10);
		cout << m;

	}

	m = 218;
	gotoxy(57, 8);
	cout << m;

	m = 192;
	gotoxy(57, 10);
	cout << m;



	m = 191;
	gotoxy(183, 8);
	cout << m;


	m = 217;
	gotoxy(183, 10);
	cout << m;

	TextColor(11);

	{
		char n = '|';
		gotoxy(183, 9);
		cout << n;

	}
	TextColor(6);
	
	m = 193;
	gotoxy(63, 10);
	cout << m;
	gotoxy(75, 10);
	cout << m;
	gotoxy(89+3, 10);
	cout << m;
	gotoxy(101, 10);
	cout << m;
	gotoxy(105+5, 10);
	cout << m;
	gotoxy(105+8 + 6, 10);
	cout << m;
	gotoxy(105 + 8+8 + 7, 10);
	cout << m;
	gotoxy(105 + 3*8 + 8, 10);
	cout << m;
	gotoxy(105 + 4*8 + 9, 10);
	cout << m;
	gotoxy(105 + 5*8 + 10, 10);
	cout << m;
	gotoxy(105 + 6 * 8 + 11, 10);//9
	cout << m;
	gotoxy(105 + 7 * 8 + 12, 10);
	cout << m;
	m = 194;
	gotoxy(63, 8);
	cout << m;
	gotoxy(75, 8);
	cout << m;
	gotoxy(89 + 3, 8);
	cout << m;
	gotoxy(101, 8);
	cout << m;
	gotoxy(105 + 5, 8);
	cout << m;
	gotoxy(105 + 8 + 6, 8);
	cout << m;
	gotoxy(105 + 8 + 8 + 7, 8);
	cout << m;
	gotoxy(105 + 3 * 8 + 8, 8);
	cout << m;
	gotoxy(105 + 4 * 8 + 9, 8);
	cout << m;
	gotoxy(105 + 5 * 8 + 10, 8);
	cout << m;
	gotoxy(105 + 6 * 8 + 11, 8);//9
	cout << m;
	gotoxy(105 + 7 * 8 + 12, 8);
	cout << m;


	gotoxy(57, 9);
	TextColor(15);  
 	cout << "|No   |ID         |Name            |Week 1  |Week 2  |Week 3  |Week 4  |Week 5  |Week 6  |Week 7  |Week 8  |Week 9  |Week 10 ";
	int w = 0,In=0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, at.stdId, ',');
		getline(fin, at.stdLName, ',');
		getline(fin, at.stdFName, ',');
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
		if (no != "")
		{
			TextColor(11);
			gotoxy(57, w + 11);
			cout << "| " << no;
			gotoxy(63, w + 11);
			cout << "| " << at.stdId ;
			gotoxy(75, w + 11);
			cout << "| " << at.stdLName << " " << at.stdFName ;
			for (int i = 0; i < 10; i++)
			{
				if (at.check[i] == 1)
				{
					
					TextColor(11);
					gotoxy(89 + 7 + In, w + 11);
					cout << "X";
					In += 9;

				}
				else if (at.check[i] == 0)
				{
					TextColor(12);
					gotoxy(89 + 7 + In, w + 11);
					cout << "O";
					In += 9;
				}
				else
				{
					TextColor(15);

					gotoxy(89+7+In, w + 11);
					cout << "-";
					In += 9;
				}
			}
			gotoxy(58, w + 12);
			TextColor(6);
			cout << "______________________________________________________________________________________________________________________________";

			In = 0;
			w += 2;
		}

	}
	fin.close();
}


void displayAttendanceOfAStudent(string acaY, string term, char *courseId, string Class, string stdId)
{
	string y = acaY;
	string t = term;
	string cId = courseId;
	string css = Class;
	string siD = stdId;
	ifstream fin;
	fin.open(y + "_" + t + "_" + css + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open())
	{
		gotoxy(100, 20);
		cout << " C A N N O T   V I E W ";
		return;
	}
	string x;
	string no;
	Attendance at;
	string check;
	getline(fin, x);
	gotoxy(100, 10);
	TextColor(6);
	cout << "A T T E N D A N C E  :|" << siD << " " << css ;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, at.stdId, ',');
		getline(fin, at.stdLName, ',');
		getline(fin, at.stdFName, ',');
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
		if (no != "" && siD == at.stdId)
		{
			TextColor(11);
			gotoxy(100, 12);
			cout << "STUDENT ID  :|  " << at.stdId ;
			gotoxy(100, 14);
			cout << "STUDENT NAME:|  " << at.stdLName << " " << at.stdFName << endl;
			for (int i = 0; i < 10; i++)
			{
				TextColor(6);
				gotoxy(100, 16 + i * 2);
				cout << "   W E E K  :|  " << i + 1 << "  : ";
				if (at.check[i] == 1) { 
					TextColor(11);
					cout << "    X    "; }
				else if (at.check[i] == 0)
				{
					TextColor(12);
					cout << "    O    ";
				}
				else {
					TextColor(15);
					cout << "    -    ";
				}
				gotoxy(100, i*2 + 17);
				TextColor(6);
				cout << "___________________________________________";

			}
		}

	}
	fin.close();
}

void exportAttendanceListToCSV(string acaY, string term, char *courseId, char  *Class)
{
	string Year = acaY;
	string Term = term;
	string css = Class;
	string id = courseId;
	string content = "";
	ifstream fin;
	fin.open(Year + "_" + Term + "_" + css + "_" + id + "_AttendanceList.txt");
	if (!fin.is_open())
	{
		gotoxy(110, 18);
		cout << "  C A N' T  E X P O R T";
		return;
	}
	string x;
	while (!fin.eof())
	{
		getline(fin, x);
		content += x + "\n";
	}
	fin.close();
	ofstream fout;
	fout.open(Year + "_" + Term + "_" + css + "_" + id + "_AttendanceList.csv");
	fout << content;
	fout.close();
	gotoxy(113, 18);
	cout << "E X P O R T  C O M P L E T E D !";
}