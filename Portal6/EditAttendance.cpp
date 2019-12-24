#include"EditAttendance.h"
#include"DesignAffect.h"

void editAttendance(string acaYear, string term, char *Class, char *cId, int curWeek) // goi ham editAttendance
{
	string y = acaYear;
	string t = term;
	string c = Class;
	string id = cId;
	int n = 0;
	Attendance *at = new Attendance[100];
	if (loadAttendance(y, t, c, id, at, n))
	{
		editAttendanceData(acaYear, term, Class, cId, at, n, curWeek);
		savetheAttendance(y, t, c, id, at, n);
	}
	else
	{
		gotoxy(100, 20);
		cout << "Course is not exist";
		
		return;
	}
}
void displayAtt(Attendance *at, char *clss, char *cid, int n)
{
	int In = 0;
	gotoxy(56, 7);
	TextColor(6);
	cout << "A T T E N D A N C E   L I S T |:|"; TextColor(10); gotoxy(90, 7); cout << clss;

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
	gotoxy(89 + 3, 10);
	cout << m;
	gotoxy(101, 10);
	cout << m;
	gotoxy(105 + 5, 10);
	cout << m;
	gotoxy(105 + 8 + 6, 10);
	cout << m;
	gotoxy(105 + 8 + 8 + 7, 10);
	cout << m;
	gotoxy(105 + 3 * 8 + 8, 10);
	cout << m;
	gotoxy(105 + 4 * 8 + 9, 10);
	cout << m;
	gotoxy(105 + 5 * 8 + 10, 10);
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
	for (int i = 0; i < n; i++)
	{
		TextColor(11);
		gotoxy(57, 2*i + 11);
		cout << "| " << i + 1;
		gotoxy(63, 2 * i + 11);
		cout << "| " << at[i].stdId;
		gotoxy(75, 2 * i + 11);
		cout << "| " << at[i].stdLName << " " << at[i].stdFName;
		
		for (int j = 0; j < 10; j++)
		{
			if (at[i].check[j] == 1)
			{

				TextColor(11);
				gotoxy(89 + 7 + In, 2*i + 11);
				cout << "X";
				In += 9;

			}
			else if (at[i].check[j] == 0)
			{
				TextColor(12);
				gotoxy(89 + 7 + In, 2*i + 11);
				cout << "O";
				In += 9;
			}
			else
			{
				TextColor(15);

				gotoxy(89 + 7 + In, 2*i + 11);
				cout << "-";
				In += 9;
			}	
		}
		gotoxy(58, 2 * i + 12);
		TextColor(6);
		cout << "______________________________________________________________________________________________________________________________";
		In = 0;
	}
}
void editAttendanceData(string acaYear, string term, char *Class, char *cId, Attendance *&at, int n, int curWeek)
{
	while (1) {
		gotoxy(60, 6);
		cout << "Current week : " << curWeek;
		displayAtt(at, Class, cId, n);
		gotoxy(100, 36);
		cout << "click ENTER TO CHECK_IN / ESC TO EXIT.";
		int ent = _getch();
		if (ent == 13)
		{
			gotoxy(100, 40);
			cout << "Please choose a student to edit :";


			int k;
			cin >> k;
			if (0 < k && k <= n)
			{
				char a;
				gotoxy(100, 41);
				cout << "Attendance of " << at[k - 1].stdId << " :";
				for (int i = 0; i < curWeek; i++)
				{
					gotoxy(100, 42);
					cout << "Week " << i + 1 << ": ";
					cin >> a;
					if (a == 'X') at[k - 1].check[i] = 1;
					else if (a == 'O') at[k - 1].check[i] = 0;
					for (int i = 40; i < 50; i++)
					{
						gotoxy(56, i);
						cout << "                                                                                                 ";

					}
				}
			}
		}
		else if (ent == 27)
		{
		

			break;
		}
	}
}
bool loadAttendance(string acaYear, string term, string Class, string cId, Attendance *at, int &n)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + Class + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open()) return false;
	string x;
	getline(fin, x);
	string check;
	string no;
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		if (no != "")
		{
			getline(fin, at[dem].stdId, ',');
			getline(fin, at[dem].stdLName, ',');
			getline(fin, at[dem].stdFName, ',');
			for (int i = 0; i < 10; i++)
			{
				if (i < 9)
					getline(fin, check, ',');
				else
					getline(fin, check);
				if (check == "X") at[dem].check[i] = 1;
				else if (check == "O") at[dem].check[i] = 0;
				else at[dem].check[i] = -1;
			}
			dem++;
		}

	}
	n = dem;
	fin.close();
	return true;
}


void savetheAttendance(string acaYear, string term, string Class, string cId, Attendance *at, int n)
{
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + Class + "_" + cId + "_AttendanceList.txt");
	fout << "No,Student ID,Lastname,Firstname,Week 1,Week 2,Week 3,Week 4,Week 5,Week 6,Week 7,Week 8,Week 9,Week 10\n";
	for (int i = 0; i < n; i++)
	{
		fout << i << ",";
		fout << at[i].stdId << ",";
		fout << at[i].stdLName << ",";
		fout << at[i].stdFName << ",";
		for (int j = 0; j < 10; j++)
		{
			if (j < 9)
			{
				if (at[i].check[j] == -1) fout << "-,";

				else if (at[i].check[j] == 0) fout << "O,";
				else if (at[i].check[j] == 1) fout << "X,";
			}
			else
			{
				if (at[i].check[j] == -1) fout << "-\n";
				else if (at[i].check[j] == 0) fout << "O\n";
				else if (at[i].check[j] == 1) fout << "X\n";
			}
		}
	}
	fout.close();
}