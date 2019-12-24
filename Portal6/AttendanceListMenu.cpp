#include"Screen.h"
#include"ScoreBoard.h"
#include"InputData.h"
#include"GetcurrentTime.h"
#include"Attendance.h"
void ImportScoreBoardScreen() {
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
		}

		m = 218;
		gotoxy(99, 8);
		cout << m;
		gotoxy(99, 11);
		cout << m;
		gotoxy(99, 14);
		cout << m;

		m = 192;
		gotoxy(99, 10);
		cout << m;
		gotoxy(99, 13);
		cout << m;
		gotoxy(99, 16);
		cout << m;


		m = 191;
		gotoxy(151, 8);
		cout << m;
		gotoxy(151, 11);
		cout << m;
		gotoxy(151, 14);
		cout << m;

		m = 217;
		gotoxy(151, 10);
		cout << m;
		gotoxy(151, 13);
		cout << m;
		gotoxy(151, 16);
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
		}
		gotoxy(79, 9);
		cout << "F i l e  D r i v e: |";
		gotoxy(79, 12);
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 15);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  I M P O R T  --  S C O R E  >> ";
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
		inputData(filePth);
		gotoxy(103, 12);
		inputData(courseid);
		gotoxy(103, 15);
		inputData(Class);

		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		importScore( acaYear, term, Class, courseid,filePth );
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]filePth;
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
void ExportAttendanceToCSVScreen() {
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
		cout << "< E X P O R T  A T T E N D A N C E>";
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
		exportAttendanceListToCSV(acaYear, term,  courseid, Class);
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




void AttendaceMenuAffect(int CoursePointer) {
	TextColor(12);
	gotoxy(29, 24);
	cout << " <>   VIEW ATTENDANCE    ";//1

	gotoxy(29, 26);
	cout << " <>   EXPORT ATTENDANCE  ";//2

	
	switch (CoursePointer)
	{
	case 1:
		TextColor(6);
		gotoxy(29, 24);
		cout << " <>   VIEW ATTENDANCE    ";//1
		break;
	case 2:
		TextColor(6);
		gotoxy(29, 26);
		cout << " <>   EXPORT ATTENDANCE  ";//2
		break;
	
	default:
		break;
	}
}
void ControlAttendaceScreen(string Usn) {
	TextColor(11);
	for (int i = 4; i < 50; ++i)
	{
		char m = 177;
		gotoxy(55, i);
		cout << m;
	}
	TextColor(12);
	gotoxy(29, 24);
	cout << " <>   VIEW ATTENDANCE    ";

	gotoxy(29, 26);
	cout << " <>   EXPORT ATTENDANCE  ";




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
		AttendaceMenuAffect(CoursePointer);
	}
	if (CoursePointer == 1)//importstudent
	{
		ViewAttendanceScreen();
		
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";

		}
		ControlAttendaceScreen(Usn);

	}
	if (CoursePointer == 2)//chageclassa
	{
		ExportAttendanceToCSVScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";

		}
		ControlAttendaceScreen(Usn);

	}

}