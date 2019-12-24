#include"ScoreBoard.h"
#include"DesignAffect.h"
void importScore(string acaY, string term, char *Class, char *courseId, char *filePath) // goi ham nay
{
	string y = acaY;
	string t = term;
	string css = Class;
	string fp = filePath;
	string cId = courseId;
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open())
	{
		gotoxy(110, 18);
		cout << "  C A N' T   A D D     ";
		return;
	}
	string x;
	getline(fin, x);// first line.
	string no;
	string id, lname, fname, mt, lb, bn, fn;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, mt, ',');
		getline(fin, lb, ',');
		getline(fin, bn, ',');
		getline(fin, fn);
		if (no != "")
		{
			changeScorebyImport(y, t, css, id, cId, mt, lb, bn, fn);
		}
	}
	fin.close();
	gotoxy(113, 18);
	cout << "I M P O R T  C O M P L E T E D !";
}
void changeScorebyImport(string year, string term, string Class, string stdid, string crsId, string midterm, string lab, string bonus, string Final)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + Class + "_" + crsId + "_ScoreBoard.txt");
	if (!fin.is_open())
	{
		gotoxy(100, 20);
		cout << "Course is not existed." << endl;
		return;
	}
	string no;
	string id, lname, fname, mt, lb, bn, fn;
	string content = "";
	getline(fin, content);
	content += "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, mt, ',');
		getline(fin, lb, ',');
		getline(fin, bn, ',');
		getline(fin, fn);
		if (no != "")
		{
			dem++;
			if (id == stdid)
			{
				content += to_string(dem) + ",";
				content += id + ",";
				content += lname + ",";
				content += fname + ",";
				content += midterm + ",";
				content += lab + ",";
				content += bonus + ",";
				content += Final + "\n";
			}
			else
			{
				content += to_string(dem) + ",";
				content += id + ",";
				content += lname + ",";
				content += fname + ",";
				content += mt + ",";
				content += lb + ",";
				content += bn + ",";
				content += fn + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(year + "_" + term + "_" + Class + "_" + crsId + "_ScoreBoard.txt");
	fout << content;
	fout.close();
}



void displayScoreOfACourse(char * acaY, char* term, char *courseId, char  *Class)
{
	string y = acaY;
	string t = term;
	string cId = courseId;
	string css = Class;
	ifstream fin;
	fin.open(y + "_" + t + "_" + css + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open())
	{
		gotoxy(110, 18);
		cout << "  C A N' T   V I E W   ";
		return;
	}
	string x;
	string no;
	Score sc;
	string md, lab, bonus, fn;
	getline(fin, x);
	gotoxy(56, 7);
	TextColor(6);
	cout << "[]  S C O R E B O A R D  o f  C L A S S ";
	TextColor(11);
	gotoxy(56+41,7);
	cout<< cId <<" - "<< css;

	char m;
	TextColor(6);
	for (int i = 0; i <= 87; ++i)
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
	gotoxy(88+57, 8);
	cout << m;


	m = 217;
	gotoxy(88+57, 10);
	cout << m;

	TextColor(11);

	{
		char n = '|';
		gotoxy(88+57, 9);
		cout << n;

	}


	TextColor(6);
	m = 194;
	gotoxy(63, 8);
	cout << m;
	gotoxy(73, 8);
	cout << m;
	gotoxy(96, 8);
	cout << m;
	gotoxy(96+12, 8);
	cout << m;
	gotoxy(96+2*12, 8);
	cout << m;
	gotoxy(96+3*12, 8);
	cout << m;


	m = 193;
	gotoxy(63, 10);
	cout << m;
	gotoxy(73, 10);
	cout << m;
	gotoxy(96, 10);
	cout << m;
	gotoxy(96 + 12, 10);
	cout << m;
	gotoxy(96 + 2 * 12, 10);
	cout << m;
	gotoxy(96 + 3 * 12, 10);
	cout << m;


	gotoxy(57, 9);
	TextColor(15);
	cout << "|. NO |. ID     |. STUDENT NAME        | MIDTERM   | LAB       | BONUS     | FINAL     ";
	int i=0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, sc.stdId, ',');
		getline(fin, sc.stdLName, ',');
		getline(fin, sc.stdFName, ',');
		getline(fin, md, ',');
		getline(fin, lab, ',');
		getline(fin, bonus, ',');
		getline(fin, fn);
		sc.Midterm = stof(md);
		sc.Lab = stof(lab);
		sc.Bonus = stof(bonus);
		sc.Final = stof(fn);
		if (no != "")
		{
			TextColor(11);
			gotoxy(57, i + 11);
			cout <<"| " <<no;
			gotoxy(63, i + 11);
			cout <<"| "<< sc.stdId ;
			gotoxy(73, i + 11);
			cout << "| " << sc.stdLName << " " << sc.stdFName ;
			gotoxy(96, i + 11);
			cout << "| " << sc.Midterm ;
			gotoxy(96+12, i + 11);
			cout << "| " << sc.Lab ;
			gotoxy(96+2*12, i + 11);
			cout << "| " << sc.Bonus ;
			gotoxy(96+3*12, i + 11);
			cout << "| " << sc.Final ;
			gotoxy(57, i + 12);
			cout << "________________________________________________________________________________________ ";
			i += 2;
		}

	}
	fin.close();
}


void displayScoreOfAStudent(string  acaY, string  term, char *courseId, string Class, string stdId)
{
	string y = acaY;
	string t = term;
	string cId = courseId;
	string css = Class;
	string siD = stdId;
	ifstream fin;
	fin.open(y + "_" + t + "_" + css + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string x;
	string no;
	Score sc;
	string md, lab, bonus, fn;
	getline(fin, x);
	TextColor(6);
	gotoxy(100, 8);
	cout << "M A R K  O F " << siD ;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, sc.stdId, ',');
		getline(fin, sc.stdLName, ',');
		getline(fin, sc.stdFName, ',');
		getline(fin, md, ',');
		getline(fin, lab, ',');
		getline(fin, bonus, ',');
		getline(fin, fn);
		sc.Midterm = stof(md);
		sc.Lab = stof(lab);
		sc.Bonus = stof(bonus);
		sc.Final = stof(fn);
		
		if (no != "" && siD == sc.stdId)
		{
			TextColor(11);
			gotoxy(100, 10);
			cout << "Id             :    " << sc.stdId;
			gotoxy(100, 12);
			cout << "Name           :    " << sc.stdLName << " " << sc.stdFName;
			gotoxy(100, 14);
			cout << "Midterm        :    " << sc.Midterm;
			gotoxy(100, 16);
			cout << "Lab            :    " << sc.Lab;
			gotoxy(100, 18);
			cout << "Bonus          :    " << sc.Bonus;
			gotoxy(100, 20);
			cout << "Final          :    " << sc.Final;
			for (int i = 0; i < 6; i++)
			{
				gotoxy(100, i * 2 + 11);
				TextColor(6);
				cout << "___________________________________________";
			}
		}

	}
	fin.close();
}

void exportScoreToCSV(string acaY, string term, char *courseId, char  *Class)
{
	string Year = acaY;
	string Term = term;
	string css = Class;
	string id = courseId;
	string content = "";
	ifstream fin;
	fin.open(Year + "_" + Term + "_" + css + "_" + id + "_ScoreBoard" + ".txt");
	if (!fin.is_open()) {
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
	fout.open(Year + "_" + Term + "_" + css + "_" + id + "_ScoreBoard" + ".csv");
	fout << content;
	fout.close();
	gotoxy(113, 18);
	cout << "E X P O R T  C O M P L E T E D !";
}