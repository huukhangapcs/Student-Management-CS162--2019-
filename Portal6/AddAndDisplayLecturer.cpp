#include"AddAndDisplayLecturer.h"
#include"DesignAffect.h"
void AddNewLecturer(char *lecAccount, string acaYear, string term)
{
	string lA = lecAccount;
	string y = acaYear;
	string t = term;
	if (!checkIfLecAccountExisted(lA))
	{
		ofstream fout;
		fout.open("LecturerLogin.txt", ios::out | ios::app);
		fout << lA << "," << lA << endl;
		fout.close();
		ofstream fout2;
		fout2.open(y + "_" + t + "_LecturerList.txt", ios::out | ios::app);
		fout2 << lA << endl;
		fout2.close();
		gotoxy(100, 20);
		TextColor(6);
		cout << " ADDING COMPLETED!";
	}
	else
	{
		gotoxy(100, 20);
		TextColor(12);
		cout << " ACCOUNT HAS BEEN EXIST";
	}
}
void GetCourseName(string acaYear, string term, string LecAccount, string&data)
{
	string y = acaYear;
	string t = term;
	string lec = LecAccount;
	ifstream fin;
	fin.open(y + "_" + t + ".txt");
	if (!fin.is_open()) return;
	string x;
	getline(fin, x);
	string No;
	Course cs;
	string remain;
	while (!fin.eof())
	{
		getline(fin, No, ',');
		getline(fin, cs.Id, ',');
		getline(fin, cs.Name, ',');
		getline(fin, cs.Class, ',');
		getline(fin, cs.LecAccount, ',');
		getline(fin, remain);
		if (No != ""  && cs.LecAccount == lec)
		{
			if (data == "") data += cs.Id + "<" + cs.Class + "> ";
			else
			{
				data += "," + cs.Id + "<" + cs.Class + "> ";
			}
		}
	}
}
void DisplayLecturerList(string  acaYear, string term)
{
	string y = acaYear;
	string t = term;
	ifstream fin;
	string lec;
	fin.open(y + "_" + t + "_LecturerList.txt");
	if (!fin.is_open()) {
		gotoxy(100, 20);
		cout << "CANNOT FOUND LECTURER";
		return;
	}
	gotoxy(26 + 56, 7);
	TextColor(6);
	cout << "<\><\><\> L E C T U R E R S   L I S T |:|"; TextColor(10); gotoxy(90, 7);
	TextColor(6);
	char m;
	for (int i = 0; i <= 53+13; ++i)
	{
		m = 196;

		gotoxy(26 + 58 + i, 8);
		cout << m;
		gotoxy(26 + 58 + i, 10);
		cout << m;

	}

	m = 218;
	gotoxy(26 + 57, 8);
	cout << m;

	m = 192;
	gotoxy(26 + 57, 10);
	cout << m;



	m = 191;
	gotoxy(26 + 57+53+14, 8);
	cout << m;


	m = 217;
	gotoxy(26+57+53+14, 10);
	cout << m;

	TextColor(11);

	{
		char n = '|';
		gotoxy(57+53+14+26, 9);
		cout << n;

	}
	TextColor(6);
	m = 194;
	gotoxy(26 + 68, 8);
	cout << m;
	gotoxy(26 + 90, 8);
	cout << m;
	m = 193;
	gotoxy(26 + 68, 10);
	cout << m;
	gotoxy(26 + 90, 10);
	cout << m;

	gotoxy(26 + 57, 9);
	TextColor(15);
	int dem = 0;
	cout << "|. N O     |. L E C T U R E R    |. C O U R S E     ";
	while (!fin.eof())
	{
		
		getline(fin, lec);
		string data = "";
		if (lec != "")
		{
			GetCourseName(acaYear, term, lec, data);
			
			gotoxy(26 + 57,2*dem+11);
			cout <<"| " << dem+1;
			gotoxy(25 + 68, 2*dem + 11);
			cout << "|.|   " << lec;
			gotoxy(25 + 90, 2*dem + 11);
			cout<< "|.|   " << data ;
			gotoxy(26 + 57, 2 * dem + 12);
			cout << "___________________________________________________________________";
			dem++;
		}

	}
	fin.close();
}
void DisplayALecturer(char *lecAccount, string acaYear, string term)
{
	string y = acaYear;
	string t = term;
	string lec = lecAccount;
	string data = "";

	GetCourseName(acaYear, term, lec, data);
	cout << lec << " :" << data << endl;
}