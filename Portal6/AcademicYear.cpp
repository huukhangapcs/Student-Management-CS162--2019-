#include"AcademicYear.h"
#include"DesignAffect.h"
void addNewAcademicYear(int startYear)
{
	string y1 = to_string(startYear);
	string y2 = to_string(startYear + 1);
	string acaY = y1 + "-" + y2;
	if (!checkIfAcaYearIsExisted(acaY))
	{
		ofstream fout;
		fout.open("ListAcademicYear.txt", ios::out | ios::app);
		fout << acaY << endl;
		fout.close();
	}
}
void displayAcademicYear()
{
	TextColor(6);
	gotoxy(60,7);
	cout << "C o u r s e   C a t e g o r y :" << endl;
	ifstream fin;
	string year;
	int dem = 0;
	fin.open("ListAcademicYear.txt");
	if (!fin.is_open())
	{
		TextColor(15);
		gotoxy(90,8);
		cout << "{  .THERE IS NO ACADEMIC YEAR NOW.  }";
	}
	while (!fin.eof())
	{
		getline(fin, year);
		if (year != "")
		{
			TextColor(15);
			dem++;
			gotoxy(110, 8+dem);
			cout << dem << " ||          " << year << endl;
		}
	}
	fin.close();
}
void deleteAcademicYear(int n)
{
	ifstream fin;
	fin.open("ListAcademicYear.txt");
	string year;
	string removeYear;
	string content = "";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, year);
		if (year != "")
		{
			dem++;
			if (dem != n)
			{
				content += year;
				content += "\n";
			}
			else removeYear = year;
		}
	}
	fin.close();
	ofstream fout;
	fout.open("ListAcademicYear.txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	ifstream fin2;
	string term;
	fin2.open(removeYear + ".txt");
	if (fin2.is_open())
	{
		while (!fin2.eof())
		{
			getline(fin2, term);
			if (term != "") removeTermData(removeYear, term);
		}
	}
	fin2.close();
	remove((removeYear + ".txt").c_str());
	// Not completed
}
