#include"DisplayCourseList.h"
#include"DesignAffect.h"
void displayCourseList(string acaYear, string term, Course st, int &numofCourse) // ko can cin bien numofcourse
{
	ifstream fin;
	string y = acaYear;
	string t = term;
	fin.open(y + "_" + t + ".txt");
	if (!fin.is_open())
	{
		gotoxy(100, 20);
		cout << "No Course.";
		fin.close();
	}
	else
	{
		gotoxy(56, 7);
		TextColor(6);
		cout << "[]  C O U R S E S  L I S T |:|"; 
		char m;
		TextColor(6);
		for (int i = 0; i <= 128; ++i)
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
		gotoxy(121+57+8, 8);
		cout << m;


		m = 217;
		gotoxy(121+57+8, 10);
		cout << m;

		TextColor(11);

		{
			char n = '|';
			gotoxy(186, 9);
			cout << n;

		}
		TextColor(6);
		
		m = 193;
		gotoxy(57 + 4, 10);
		cout << m;
		gotoxy(57 + 12, 10);
		cout << m;
		gotoxy(57 + 33 + 6, 10);
		cout << m;
		gotoxy(57 + 41 + 6, 10);
		cout << m;
		gotoxy(57 + 53 + 6 + 3, 10);
		cout << m;
		gotoxy(57 + 65 + 6 + 3, 10);
		cout << m;
		gotoxy(57 + 77 + 6 + 3, 10);
		cout << m;
		gotoxy(57 + 89 + 6 + 3, 10);
		cout << m;
		gotoxy(57 + 101 + 6 + 3, 10);
		cout << m;
		gotoxy(57 + 111 + 6 + 3, 10);
		cout << m;
		
		m = 194;
		gotoxy(57 + 4, 8);
		cout << m;
		gotoxy(57 + 12, 8);
		cout << m;
		gotoxy(57 + 33+6, 8);
		cout << m;
		gotoxy(57 + 41+6, 8);
		cout << m;
		gotoxy(57 + 53+6+3, 8);
		cout << m;
		gotoxy(57 + 65+6+3, 8);
		cout << m;
		gotoxy(57 + 77+6+3, 8);
		cout << m;
		gotoxy(57 + 89+6+3, 8);
		cout << m;
		gotoxy(57 + 101+6+3, 8);
		cout << m;
		gotoxy(57 + 111+6+3, 8);
		cout << m;
		gotoxy(57, 9);
		TextColor(15);
		cout << "|NO |ID     |COURSE NAME               |CLASS  |LECTURER      |START DATE |END DATE   |DAY OF WEEK|START HOUR |END HOUR |ROOM    |";

		string x;
		getline(fin, x); // remove first line
		string no;
		int i = 0;

		while (!fin.eof())
		{
			getline(fin, no, ',');
			getline(fin, st.Id, ',');
			getline(fin, st.Name, ',');
			getline(fin, st.Class, ',');
			getline(fin, st.LecAccount, ',');
			getline(fin, st.stDay, ',');
			getline(fin, st.enDay, ',');
			getline(fin, st.day, ',');
			getline(fin, st.stHour, ',');
			getline(fin, st.enHour, ',');
			getline(fin, st.Room);
			if (no != "")
			{
				numofCourse++;
				TextColor(11);
				gotoxy(57, i + 11);
				cout << "| " << no;
				gotoxy(57 + 4, i + 11);
				cout << "|" << st.Id;

				gotoxy(57 + 12,i+11);
				cout << "|" << st.Name;

				gotoxy(57 + 33 + 6, i + 11);
				cout << "|" << st.Class;

				gotoxy(57 + 41+6, i + 11);
				
				cout << "|" << st.LecAccount;
				gotoxy(57 + 53+9, i + 11);
				cout << "|" << st.stDay;
				gotoxy(57 + 65+9, i + 11);
				cout << "|" << st.enDay;

				gotoxy(57 + 77+9, i + 11);
				cout << "|" << st.day;

				gotoxy(57 + 89+9, i + 11);
				cout << "|" << st.stHour;
				gotoxy(57 + 101+9, i + 11);
				cout << "|" << st.enHour;


				gotoxy(57 + 111+9, i + 11);
				cout << "|" << st.Room;
				gotoxy(186, i + 11);
				cout << "|";
				gotoxy(58, i + 12);
				TextColor(6);
				cout << "________________________________________________________________________________________________________________________________";
				i += 2;

			}
		}
		fin.close();
	}
}

void takeCourseName(string acaYear, string term, Course &st, int n)
{
	string y = acaYear;
	string t = term;
	ifstream fin;
	fin.open(y + "_" + t + ".txt");
	string x;
	getline(fin, x);
	string no;
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, st.Id, ',');
		getline(fin, st.Name, ',');
		getline(fin, st.Class, ',');
		getline(fin, st.LecAccount, ',');
		getline(fin, st.stDay, ',');
		getline(fin, st.enDay, ',');
		getline(fin, st.day, ',');
		getline(fin, st.stHour, ',');
		getline(fin, st.enHour, ',');
		getline(fin, st.Room);
		if (no != "")
		{
			dem++;
			if (dem == n) break;
		}
	}
	fin.close();
}