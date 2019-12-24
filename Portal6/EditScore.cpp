#include"EditScore.h"
#include"DesignAffect.h"
void editScore(string acaY, string  term, char *Class, char *courseId, char *stdId)
{
	string y = acaY;
	string t = term;
	string css = Class;
	string cId = courseId;
	string sId = stdId;
	Score sc;
	if (findScore(y, t, css, cId, sId, sc))
	{
		editScoreData(acaY, term, Class, courseId, stdId, sc);
		saveScore(y, t, css, cId, sc);
		gotoxy(100, 25);
		cout << " EDIT SUCCESSFULLY! ";
	}
	else
	{
		gotoxy(100, 20);
		cout << "NOT FOUND\n";		
		return;
	}

}
bool findScore(string acaYear, string term, string Class, string courseId, string stdId, Score&sc)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + Class + "_" + courseId + "_ScoreBoard.txt");
	if (!fin.is_open()) return false;
	string x;
	getline(fin, x); // first line
	string no;
	string mid, lab, bonus, fn;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, sc.stdId, ',');
		getline(fin, sc.stdLName, ',');
		getline(fin, sc.stdFName, ',');
		getline(fin, mid, ',');
		getline(fin, lab, ',');
		getline(fin, bonus, ',');
		getline(fin, fn);
		sc.Midterm = stof(mid);
		sc.Lab = stof(lab);
		sc.Bonus = stof(bonus);
		sc.Final = stof(fn);
		if (stdId == sc.stdId) return true;
	}
	fin.close();
	return false;
}
void displayStd(Score sc)
{
#pragma region adding student
	TextColor(11);
	gotoxy(80, 10);
	cout << "    Student ID    :|  " << sc.stdId;
	gotoxy(80, 13);
	cout << "    Student Name  :|  " << sc.stdLName << " " << sc.stdFName;
	gotoxy(80, 16);
	cout << "1.     MIDTERM    :|  " << sc.Midterm;
	gotoxy(80, 19);
	cout << "2.     LAB        :|  " << sc.Lab;
	gotoxy(80, 22);
	cout << "3.     BONUS      :|  " << sc.Bonus;
	gotoxy(80, 25);
	cout << "4.     FINAL      :|  " << sc.Final;
	char m;
	TextColor(6);
	for (int i = 0; i <= 50; ++i)
	{
		m = 196;

		gotoxy(100 + i, 9);
		cout << m;
		gotoxy(100 + i, 11);
		cout << m;
		gotoxy(100 + i, 12);
		cout << m;
		gotoxy(100 + i, 14);
		cout << m;
		gotoxy(100 + i, 15);
		cout << m;
		gotoxy(100 + i, 17);
		cout << m;
		gotoxy(100 + i, 18);
		cout << m;
		gotoxy(100 + i, 20);
		cout << m;
		gotoxy(100 + i, 21);
		cout << m;
		gotoxy(100 + i, 23);
		cout << m;
		gotoxy(100 + i, 24);
		cout << m;
		gotoxy(100 + i, 26);
		cout << m;
	}

	m = 218;
	gotoxy(99, 9);
	cout << m;
	gotoxy(99, 12);
	cout << m;
	gotoxy(99, 15);
	cout << m;
	gotoxy(99, 18);
	cout << m;
	gotoxy(99, 21);
	cout << m;
	gotoxy(99, 24);
	cout << m;


	m = 192;
	gotoxy(99, 11);
	cout << m;
	gotoxy(99, 14);
	cout << m;
	gotoxy(99, 17);
	cout << m;
	gotoxy(99, 20);
	cout << m;
	gotoxy(99, 23);
	cout << m;
	gotoxy(99, 26);
	cout << m;

	m = 191;
	gotoxy(151, 9);
	cout << m;
	gotoxy(151, 12);
	cout << m;
	gotoxy(151, 15);
	cout << m;
	gotoxy(151, 18);
	cout << m; 
	gotoxy(151, 21);
	cout << m;
	gotoxy(151, 24);
	cout << m;
	m = 217;
	gotoxy(151, 11);
	cout << m;
	gotoxy(151, 14);
	cout << m;
	gotoxy(151, 17);
	cout << m;
	gotoxy(151, 20);
	cout << m;
	gotoxy(151, 23);
	cout << m;
	gotoxy(151, 26);
	cout << m;
	TextColor(11);
	for (int i = 0; i < 8; ++i)
	{
		char n = '|';
		gotoxy(151, 10);
		cout << n;
		gotoxy(151, 13);
		cout << n;
		gotoxy(151, 16);
		cout << n;
		gotoxy(151, 19);
		cout << n;
		gotoxy(151, 22);
		cout << n;
		gotoxy(151, 25);
		cout << n;
	}
	



	
#pragma endregion


}
void editScoreData(string acaY, string  term, char *Class, char *courseId, char *stdId, Score &sc)
{
	string y = acaY;
	string t = term;
	string css = Class;
	string cId = courseId;
	string sId = stdId;
	displayStd(sc);
	for (int i = 31; i < 50; i++)
	{
		gotoxy(60, i);
		cout << "                                                                            ";
	}
	gotoxy(110, 28);
	TextColor(12);
	cout << "<<   5. E-X-I-T .    >>" ;
	gotoxy(100, 31);
	TextColor(6);
	cout << "Please choose : ";
	int n;
	cin >> n;
	if (n == 1)
	{
		TextColor(11);
		gotoxy(80, 33);
		cout << "MIDTERM SCORE CHANGE TO: ";
		float x;
		cin >> x;
		if (x >= 0 && x <= 10)
		{
			sc.Midterm = x;
			
			editScoreData(acaY, term, Class, courseId, stdId, sc);
		}
	}
	else if (n == 2)
	{
		TextColor(11);
		gotoxy(80, 33);
		cout << "LAB SCORE CHANGE TO: ";
		float x;
		cin >> x;
		if (x >= 0 && x <= 10)
		{
			sc.Lab = x;
			
			editScoreData(acaY, term, Class, courseId, stdId, sc);
		}
	}
	else if (n == 3)
	{
		TextColor(11);
		gotoxy(80, 33);
		cout << "BONUS SCORE CHANGE TO: ";
		float x;
		cin >> x;
		if (x >= 0 && x <= 10)
		{
			sc.Bonus = x;
			
			editScoreData(acaY, term, Class, courseId, stdId, sc);
		}
	}
	else if (n == 4)
	{
		TextColor(11);
		gotoxy(80, 33);
		cout << "FINAL SCORE CHANGE TO: ";
		float x;
		cin >> x;
		if (x >= 0 && x <= 10)
		{
			sc.Final = x;
			editScoreData(acaY, term, Class, courseId, stdId, sc);
		}
	}
	for (int i = 7; i < 50; i++)
	{
		gotoxy(60, i);
		cout << "                                                                                                              ";
	}

}
void saveScore(string year, string term, string css, string cId, Score sc)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + css + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string content;
	string no, id, lname, fname, mid, lab, bonus, fn;
	getline(fin, content);
	content += "\n";
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, mid, ',');
		getline(fin, lab, ',');
		getline(fin, bonus, ',');
		getline(fin, fn);
		if (id != sc.stdId)
		{
			content += no + ",";
			content += id + ",";
			content += lname + ",";
			content += fname + ",";
			content += mid + ",";
			content += lab + ",";
			content += bonus + ",";
			content += fn + "\n";
		}
		else
		{
			content += no + ",";
			content += sc.stdId + ",";
			content += sc.stdLName + ",";
			content += sc.stdFName + ",";
			content += to_string(sc.Midterm) + ",";
			content += to_string(sc.Lab) + ",";
			content += to_string(sc.Bonus) + ",";
			content += to_string(sc.Final) + "\n";
		}
	}
	fin.close();
	ofstream fout;
	fout.open(year + "_" + term + "_" + css + "_" + cId + "_ScoreBoard.txt");
	fout << content;
	fout.close();
}

