#include"Screen.h"
#include"ScoreBoard.h"
#include"Attendance.h"
#include"InputData.h"
#include"GetcurrentTime.h"

void ViewScoreBoardScreen() {
	while (1)
	{
#pragma region adding student
		char m;
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			m = 196;

			gotoxy(100 + i, 8);
			cout << m;
			gotoxy(100 + i, 10);
			cout << m;
			gotoxy(100 + i, 11);
			cout << m;
			gotoxy(100 + i, 13);
			cout << m;
			gotoxy(100 + i, 14);
			cout << m;
			gotoxy(100 + i, 16);
			cout << m;
			gotoxy(100 + i, 17);
			cout << m;
			gotoxy(100 + i, 19);
			cout << m;
		}

		m = 218;
		gotoxy(99, 8);
		cout << m;
		gotoxy(99, 11);
		cout << m;
		gotoxy(99, 14);
		cout << m;
		gotoxy(99, 14+3);
		cout << m;

		m = 192;
		gotoxy(99, 10);
		cout << m;
		gotoxy(99, 13);
		cout << m;
		gotoxy(99, 16);
		cout << m;
		gotoxy(99, 19);
		cout << m;


		m = 191;
		gotoxy(151, 8);
		cout << m;
		gotoxy(151, 11);
		cout << m;
		gotoxy(151, 14);
		cout << m;
		gotoxy(151, 17);
		cout << m;

		m = 217;
		gotoxy(151, 10);
		cout << m;
		gotoxy(151, 13);
		cout << m;
		gotoxy(151, 16);
		cout << m;
		gotoxy(151, 19);
		cout << m;

		TextColor(11);
		for (int i = 0; i < 8; ++i)
		{
			char n = '|';
			gotoxy(151, 9);
			cout << n;
			gotoxy(151, 12);
			cout << n;
			gotoxy(151, 15);
			cout << n;
			gotoxy(151, 18);
			cout << n;
		}
		gotoxy(79, 9);
		cout << "    A c a  Y e a r: |";
		gotoxy(79, 12);
		cout << "           T e r m: |";
		gotoxy(79, 15);
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 18);
		cout << "         C l a s s: |";


		gotoxy(110, 5);
		cout << "<< V I E W  S C O R E B O A R D >> ";
		for (int i = 0; i <= 36; ++i)
		{
			char n = 220;
			gotoxy(109 + i, 4);
			cout << n;
			n = 223;
			gotoxy(109 + i, 6);
			cout << n;
		}
		char n = 221;
		gotoxy(109, 5);
		cout << n;
		n = 222;
		gotoxy(145, 5);
		cout << n;
		gotoxy(100, 7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'I N F O M A T I O N'  } ";
#pragma endregion

		TextColor(7);
		char *courseid, *Class,*acaYear,*term;
		acaYear = new char[100];
		term = new char[100];
		courseid = new char[100];
		Class = new char[100];
		gotoxy(103, 9);
		inputData(acaYear);
		gotoxy(103, 12);
		inputData(term);
		gotoxy(103, 15);
		inputData(courseid);
		gotoxy(103, 18);
		inputData(Class);

		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		displayScoreOfACourse(acaYear, term, courseid, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]term;
		delete[]acaYear;
		delete[]courseid;
		delete[]Class;
		int key = _getch();
		if (key == 13)
		{
			for (int j = 5; j < 50; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}
		}
		if (key == 27)
			break;
	}
};
void ExportScoreToCSVScreen() {
	while (1)
	{
#pragma region adding student
		char m;
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			m = 196;

			gotoxy(100 + i, 8);
			cout << m;
			gotoxy(100 + i, 10);
			cout << m;
			gotoxy(100 + i, 11);
			cout << m;
			gotoxy(100 + i, 13);
			cout << m;
		
		}

		m = 218;
		gotoxy(99, 8);
		cout << m;
		gotoxy(99, 11);
		cout << m;
	

		m = 192;
		gotoxy(99, 10);
		cout << m;
		gotoxy(99, 13);
		cout << m;
	


		m = 191;
		gotoxy(151, 8);
		cout << m;
		gotoxy(151, 11);
		cout << m;
	

		m = 217;
		gotoxy(151, 10);
		cout << m;
		gotoxy(151, 13);
		cout << m;
		

		TextColor(11);
		for (int i = 0; i < 8; ++i)
		{
			char n = '|';
			gotoxy(151, 9);
			cout << n;
			gotoxy(151, 12);
			cout << n;
		
		}
		gotoxy(79, 9);
		cout << "         C l a s s: |";
		gotoxy(79, 12);
		cout << "C o u r s e s  I D: |";
		
		



		gotoxy(110, 5);
		cout << "<<  E X P O R T  --  S C O R E  >> ";
		for (int i = 0; i <= 36; ++i)
		{
			char n = 220;
			gotoxy(109 + i, 4);
			cout << n;
			n = 223;
			gotoxy(109 + i, 6);
			cout << n;
		}
		char n = 221;
		gotoxy(109, 5);
		cout << n;
		n = 222;
		gotoxy(145, 5);
		cout << n;
		gotoxy(100, 7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'I N F O M A T I O N'  } ";
#pragma endregion

		TextColor(7);
		char* filePth, *courseid, *Class;
		filePth = new char[100];
		courseid = new char[100];
		Class = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(Class);
		gotoxy(103, 12);
		inputData(courseid);
		

		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		exportScoreToCSV(acaYear, term,  courseid, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		
		delete[]courseid;
		delete[]Class;
		int key = _getch();
		if (key == 13)
		{
			for (int j = 5; j < 50; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}
		}
		if (key == 27)
			break;
	}
}
void ScoreboardMenuAffect(int CoursePointer) {
	TextColor(12);
	gotoxy(29, 24);
	cout << " <>   VIEW SCOREBOARD    ";//1

	gotoxy(29, 26);
	cout << " <>   EXPORT SCOREBOARD  ";//2

	
	switch (CoursePointer)
	{
	case 1:
		TextColor(6);
		gotoxy(29, 24);
		cout << " <>   VIEW SCOREBOARD    ";//1
		break;
	case 2:
		TextColor(6);
		gotoxy(29, 26);
		cout << " <>   EXPORT SCOREBOARD  ";//2
		break;
	
	default:
		break;
	}
}
void ControlScoreboardScreen(string Usn) {
	TextColor(11);
	for (int i = 4; i < 50; ++i)
	{
		char m = 177;
		gotoxy(55, i);
		cout << m;
	}
	TextColor(12);
	gotoxy(29, 24);
	cout << " <>   VIEW SCOREBOARD    ";

	gotoxy(29, 26);
	cout << " <>   EXPORT SCOREBOARD  ";




	int CoursePointer = 0;
	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			CoursePointer++;
			if (CoursePointer > 2)
				CoursePointer = 1;
		}
		if (n == 72)//up 
		{
			CoursePointer--;
			if (CoursePointer < 1)
				CoursePointer = 2;
		}
		if (n == 27)//esc
		{
			MenuDisplay(Usn);
		}
		if (n == 13)//enter
		{
			break;
		}
		//ControlMenuScreen();
		ScoreboardMenuAffect(CoursePointer);
	}
	if (CoursePointer == 1)//importstudent
	{
		ViewScoreBoardScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                            ";

		}
		ControlScoreboardScreen(Usn);

	}
	if (CoursePointer == 2)//chageclassa
	{
		ExportScoreToCSVScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                           ";

		}
		ControlScoreboardScreen(Usn);

	}

}