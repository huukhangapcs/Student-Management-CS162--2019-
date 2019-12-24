#include"Screen.h"
#include"InputData.h"
#include"AcademicYear.h"
#include"ImportCourse.h"
#include"AddANewCourse.h"
#include"RemoveACourse.h"
#include"RemoveAStudentFromCourse.h"
#include"GetcurrentTime.h"
#include"AddAStdToCourse.h"
#include"EditACourse.h"
#include"DisplayCourseList.h"
#include"Attendance.h"
#include"AddAndDisplayLecturer.h"
void AcademicYearScreen() {
	while (1) {
		int Point = 0;

		TextColor(11);
		gotoxy(110, 5);
		cout << "<<  A C A D E M I C   Y E A R   >> ";
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
		displayAcademicYear();
		TextColor(6);
		gotoxy(83, 20); 
		cout << "   ADD Academic Year               ";

		gotoxy(144, 20);
		cout << "   DELETE Academic Year            ";
		
		while (1)
		{
			int m = _getch();
			if (m == 77)//right
			{
				Point++;
				if (Point > 2)
					Point = 1;
			}
			if (m == 75)
			{
				Point--;
				if (Point < 1)
					Point = 2;
			}
			if (m == 27)
			{
				return;
			}
			if (m == 13)
			{
				break;
			}
			TextColor(6);
			gotoxy(83, 20);
			cout << "   ADD Academic Year         ";
			gotoxy(144, 20);
			cout << "   DELETE Academic Year             ";
			if (Point == 1)
			{
				TextColor(12);
				gotoxy(83, 20);
				cout << "<> A D D Academic Year <>";

			}
			if (Point == 2)
			{
				TextColor(12);
				gotoxy(144, 20);
				cout << "<> D E L E T E Academic Year <>";

			}


		}
		if (Point == 1)
		{
			int year;
			gotoxy(73+35, 23);
			TextColor(11);
			cout << "Enter Start Year: ";
			cin >> year;
			addNewAcademicYear(year);
			gotoxy(73+35, 23);
			TextColor(15);
			cout << "ADDING COMPLETED       ";

		}
		if (Point == 2)
		{
			int year;
			gotoxy(73+35, 23);
			TextColor(11);
			cout << "Enter Serial:    ";
			cin >> year;
			deleteAcademicYear(year);
			gotoxy(73 + 35, 23);
			TextColor(15);
			cout << "DELETE COMPLETED         ";
		}
	}
}
void ImportCourseScreen() {
	while (1)
	{
#pragma region adding course
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			char n = 196;
			gotoxy(100 + i, 19);
			cout << n;
			gotoxy(100 + i, 21);
			cout << n;
		}
		char n = 218;
		gotoxy(99, 19);
		cout << n;
		n = 192;
		gotoxy(99, 21);
		cout << n;
		n = 191;
		gotoxy(151, 19);
		cout << n;
		n = 217;
		gotoxy(151, 21);
		cout << n;
		gotoxy(77, 20);
		cout << "  D r i v e  f i l e :|";
		n = '|';
		gotoxy(151, 20);
		cout << n;


		
		

		TextColor(11);
		gotoxy(110, 17);
		cout << "<<  I M P O R T  >> ";
		for (int i = 0; i <= 19; ++i)
		{
			char n = 220;
			gotoxy(110 + i, 16);
			cout << n;
			n = 223;
			gotoxy(110 + i, 18);
			cout << n;
		}
		n = 221;
		gotoxy(110, 17);
		cout << n;
		n = 222;
		gotoxy(129, 17);
		cout << n;

#pragma endregion
		TextColor(7);
		char *filePath;
		filePath = new char[100];
		string term;
	    string	acaYear;

		

		
		gotoxy(103, 20);
		inputData(filePath);

		getAcayearvsTerm(acaYear,term);
		ImportCourse(filePath,  term,  acaYear);
		gotoxy(109, 30);
		TextColor(11);
		cout << "<>[ . R E W R I T E . ]<>";
		int key = _getch();
		if (key == 13)
		{
			gotoxy(95, 20);
			cout << "                                                     ";
			gotoxy(95, 23);
			cout << "                                                     ";
			gotoxy(95, 26);
			cout << "                                                     ";
			gotoxy(103, 28);
			cout << "                                                     ";
			gotoxy(103, 30);
			cout << "                                                     ";

		}
		if (key == 27)
			break;
	}

}
void AddACourseScreen() {
	while (1)
	{
#pragma region adding student
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			for (int j = 0; j <= 9*3; j += 3)
			{
				char n = 196;

				gotoxy(100 + i, 9 + j);
				cout << n;
				gotoxy(100 + i, 9 + j + 2);
				cout << n;
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			char n = 218;
			gotoxy(99, 9 + 3 * i);
			cout << n;
		}
		for (int i = 0; i < 10; ++i)
		{
			char n = 192;
			gotoxy(99, 11 + 3 * i);
			cout << n;

		}
		for (int i = 0; i < 10; ++i)
		{
			char n = 191;
			gotoxy(151, 9 + 3 * i);
			cout << n;
		}
		for (int i = 0; i < 10; ++i)
		{
			char n = 217;
			gotoxy(151, 11 + 3 * i);
			cout << n;
		}
		TextColor(11);
		for (int i = 0; i < 10; ++i)
		{
			char n = '|';
			gotoxy(151, 10 + 3 * i);
			cout << n;
		}
		gotoxy(76, 10);
		cout << "                   I D:|";
		gotoxy(76, 13);
		cout << "               N a m e:|";
		gotoxy(87, 16);
		cout << "C l a s s  :|";
		gotoxy(77, 19);
		cout << "      L e c t u r e r:|";
		gotoxy(73, 22);
		cout << "  S t a r t i n g   D a y:|";
		gotoxy(75, 25);
		cout << "   E n d i n g    D a y:|";
		gotoxy(75, 28);
		cout << "                  D a y:|";
		gotoxy(73, 31);
		cout << " S t a r t i n g  H o u r:|";
		gotoxy(75, 34);
		cout << "  E n d i n g   H o u r:|";
		gotoxy(73, 37);
		cout << "                  R o o m:|";
		TextColor(11);
		gotoxy(110, 6);
		cout << "<<  I M P O R T  >> ";
		for (int i = 0; i <= 19; ++i)
		{
			char n = 220;
			gotoxy(110 + i, 5);
			cout << n;
			n = 223;
			gotoxy(110 + i, 7);
			cout << n;
		}
		char n = 221;
		gotoxy(110, 6);
		cout << n;
		n = 222;
		gotoxy(129, 6);
		cout << n;

#pragma endregion
		TextColor(7);
		string acaYear, term;
		char * Id, * Name, * Class, * LecAccount, * stDay, * enDay, * day, * stHour, * enHour, * Room;
		Id = new char[100];
		Name = new char[100];
		Class = new char[100];
		LecAccount = new char[100];
		stDay = new char[100];
		enDay = new char[100];
		day = new char[100];
		stHour = new char[100];
		enHour = new char[100];
		Room = new char[100];

		getAcayearvsTerm(acaYear,term);

		gotoxy(103, 10);
		inputData(Id);

		gotoxy(103, 13);
		inputData(Name);

		gotoxy(103, 16);
		inputData(Class);

		gotoxy(103, 19);
		inputData(LecAccount);

		gotoxy(103, 22);
		inputData(stDay);

		gotoxy(103, 25);
		inputData(enDay);

		gotoxy(103, 28);
		inputData(day);

		gotoxy(103, 31);
		inputData(stHour);

		gotoxy(103, 34);
		inputData(enHour);

		gotoxy(103, 37);
		inputData(Room);



		AddANewCourse(acaYear, term, Id, Name, Class, LecAccount, stDay, enDay, day, stHour, enHour, Room);
			gotoxy(109, 46);
		TextColor(11);
		cout << "<>[ . R E W R I T E . ]<>";
		delete[]Name;
		delete[]Class;
		delete[]LecAccount;
		delete[]stDay;
		delete[]enDay;
		delete[]day;
		delete[]stHour;
		delete[]enHour;
		delete[]Room;


		int key = _getch();
		if (key == 13)
		{
			gotoxy(103, 10);
			cout << "                                                     ";
			gotoxy(103, 13);
			cout << "                                                     ";
			gotoxy(103, 16);
			cout << "                                                     ";
			gotoxy(103, 19);
			cout << "                                                     ";
			gotoxy(103, 22);
			cout << "                                                     ";
			gotoxy(103, 25);
			cout << "                                                     ";
			gotoxy(103, 28);
			cout << "                                                     ";
			gotoxy(103, 31);
			cout << "                                                     ";
			gotoxy(96, 33);
			cout << "                                                               ";
			gotoxy(103, 34);
			cout << "                                                     ";
			gotoxy(103, 37);
			cout << "                                                     ";
			gotoxy(103, 40);
			cout << "                                                     ";
			gotoxy(103, 43);
			cout << "                                                     ";
			gotoxy(103, 45);
			cout << "                                                     ";
			gotoxy(103, 46);
			cout << "                                                     ";
		}
		if (key == 27)
			break;
	}
}
void RemoveACourseScreen(){
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
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 12);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  R E M O V E  C O U R S E S  >> ";
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
		cout << "{  P L E A S E   E N T E R  'C O U R S E S - I D'  } ";
#pragma endregion
		
		TextColor(7);
		char* id,*Class;
		id = new char[100];
		Class = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(id);
		gotoxy(103, 12);
		inputData(Class);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		RemoveACourse(acaYear, term, id, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]id;
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
void RemoveStudentFrCourseScreen() {
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
		cout << "S t u d e n t  I D: |";
		gotoxy(79, 12);
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 15);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  R E M O V E  S T U D E N T  >> ";
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
		cout << "{  P L E A S E   E N T E R  'S T U D E N T - I D'  } ";
#pragma endregion

		TextColor(7);
		char* stdid, *courseid, *Class ;
		stdid = new char[100];
		courseid = new char[100];
		Class = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(stdid);
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
		RemoveStdFromCourse(stdid, acaYear, term, courseid, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]stdid;
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
void AddStudentToCourseScreen() {
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
		cout << "S t u d e n t  I D: |";
		gotoxy(79, 12);
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 15);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  I M P O R T  S T U D E N T  >> ";
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
		cout << "{  P L E A S E   E N T E R  'S T U D E N T - I D'  } ";
#pragma endregion

		TextColor(7);
		char* stdid, *courseid, *Class;
		stdid = new char[100];
		courseid = new char[100];
		Class = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(stdid);
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
		AddAStdToCourse(stdid, acaYear, term, courseid, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]stdid;
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
void EditCourseScreen() {
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
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 12);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  E D I T      C O U R S E S  >> ";
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
		cout << "{  P L E A S E   E N T E R  'C O U R S E S - I D'  } ";
#pragma endregion

		TextColor(7);
		char* id, *Class;
		id = new char[100];
		Class = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(id);
		gotoxy(103, 12);
		inputData(Class);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		EditACourse(acaYear, term, id, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]id;
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
void ViewCourseScreen() {
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
		cout << "C o u r s e s  I D: |";
		gotoxy(79, 12);
		cout << "         C l a s s: |";



		gotoxy(110, 5);
		cout << "<<  V I E W      C O U R S E S  >> ";
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
		cout << "{  P L E A S E   E N T E R  'C O U R S E S - I D'  } ";
#pragma endregion

		TextColor(7);
		Course id;
		int Class;
		string acaYear;
		string term;
		
		
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		displayCourseList(acaYear, term, id, Class);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		
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
void ViewStudentCourse() {
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
			gotoxy(100+i,11);
			cout << m;
			gotoxy(100+i,13);
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
			gotoxy(151,12);
			cout << n;

		}
		gotoxy(77, 9);
		cout << "  C l a s s  n a m e :|";
		gotoxy(77, 12);
		cout << "   C o u r s e   I D :|";
		gotoxy(110, 5);
		cout << "<<  R E V I E W  S T U D E N T  >> ";
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
#pragma endregion
		TextColor(7);
		string acaYear, term;
		char* id=new char[100], *classname=new char[100];
		gotoxy(77+24,9);
		inputData(classname);
		gotoxy(77 + 24, 12);
		inputData(id);
		getAcayearvsTerm(acaYear, term);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}

		displayStudentListInCourse(acaYear, term,id,classname);
		gotoxy(109, 45);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

	
		int key = _getch();
		if (key == 13)
		{
			for (int j = 5; j < 50; ++j)
			{
				gotoxy(56, j);
				cout << "                                                                                                                                   ";

			}
		}
		if (key == 27)
			break;
	}

}
void ViewAttendanceScreen() {
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
	gotoxy(99, 14 + 3);
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
	cout << "<<  R E V I E W  S T U D E N T  >> ";
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
	char *courseid, *Class, *acaYear, *term;
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
	displayAttendanceOfACourse(acaYear, term, courseid, Class);
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
			gotoxy(56, j);
			cout << "                                                                                                                                   ";

		}
	}
	if (key == 27)
		break;
}
}
void AddLecturerScreen() {
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
			
		}

		m = 218;
		gotoxy(99, 8);
		cout << m;
	

		m = 192;
		gotoxy(99, 10);
		cout << m;
		


		m = 191;
		gotoxy(151, 8);
		cout << m;
		

		m = 217;
		gotoxy(151, 10);
		cout << m;
	

		TextColor(11);
		for (int i = 0; i < 8; ++i)
		{
			char n = '|';
			gotoxy(151, 9);
			cout << n;
			
		}
		gotoxy(79, 9);
		cout << "L e c t u r e r  ID:|";
	


		gotoxy(110, 5);
		cout << "<< A D D I N G  L E C T U R E R >> ";
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
		cout << "{  P L E A S E   E N T E R  'L E C T U R E R I D'  } ";
#pragma endregion

		TextColor(7);
		char* lecAccount;
		lecAccount = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(lecAccount);

		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		AddNewLecturer(lecAccount, acaYear, term);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]lecAccount;
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
void ViewLecturerScreen() {
while(1)	{
	string acaYear;
	string term;
	getAcayearvsTerm(acaYear, term); 
	DisplayLecturerList(acaYear, term);
	gotoxy(109, 35);
	TextColor(12);
	cout << "<>[ . R E W R I T E ? ]<>";
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
void CourseMenuAffect(int CoursePointer) {
	TextColor(12);
	gotoxy(29, 4);
	cout << " <>   ACADEMIC Years     ";//1

	gotoxy(29, 6);
	cout << " <>   IMPORT Courses     ";//2

	gotoxy(29, 8);
	cout << " <>   ADD Course         ";//3

	gotoxy(29, 10);
	cout << " <>   REMOVE Course      ";//4

	gotoxy(29, 12);
	cout << " <>   REMOVE Student     ";//5

	gotoxy(29, 14);
	cout << " <>   ADD Students       ";//6

	gotoxy(29, 16);
	cout << " <>   EDIT Course        ";//7

	gotoxy(29, 18);
	cout << " <>   VIEW Course        ";//8

	gotoxy(29, 20);
	cout << " <>   VIEW Student       ";//9

	gotoxy(29, 22);
	cout << " <>   VIEW Attendance    ";//10

	gotoxy(29, 24);
	cout << " <>   ADD Lecturers     ";//11
	gotoxy(29, 26);
	cout << " <>   VIEW Lecturers     ";//12
	switch (CoursePointer)
	{
	case 1:
		TextColor(6);
		gotoxy(29, 4);
		cout << " <>   ACADEMIC Years     ";//1
		break;
	case 2:
		TextColor(6);
		gotoxy(29, 6);
		cout << " <>   IMPORT Courses     ";//2
		break;
	case 3:
		TextColor(6);		
		gotoxy(29, 8);
		cout << " <>   ADD Course         ";//3
		break;

	case 4:
		TextColor(6);	
		gotoxy(29, 10);
		cout << " <>   REMOVE Course      ";//4
		break;
	case 5:
		TextColor(6);
		gotoxy(29, 12);
		cout << " <>   REMOVE Student     ";//5
		break;
	case 6:
		TextColor(6);
		gotoxy(29, 14);
		cout << " <>   ADD Students       ";//6
		break;
	case 7:
		TextColor(6);
		gotoxy(29, 16);
		cout << " <>   EDIT Course        ";//7
		break;
	case 8:
		TextColor(6);
		gotoxy(29, 18);
		cout << " <>   VIEW Course        ";//8
		break;
	case 9:
		TextColor(6);
		gotoxy(29, 20);
		cout << " <>   VIEW Student       ";//9
		break;
	case 10:
		TextColor(6);
		gotoxy(29, 22);
		cout << " <>   VIEW Attendance    ";//10
		break;
	case 11:
		TextColor(6);
		gotoxy(29, 24);
		cout << " <>   ADD Lecturers     ";//11
		break;
	case 12:
		TextColor(6);
		gotoxy(29, 26);
		cout << " <>   VIEW Lecturers     ";//12
		break;
	default:
		break;
	}
}
void ControlCourseMenuScreen(string Usn) {
	TextColor(11);
	for (int i = 4; i < 50; ++i)
	{
		char m = 177;
		gotoxy(55, i);
		cout << m;
	}
	TextColor(12);
	gotoxy(29, 4);
	cout << " <>   ACADEMIC Years     ";

	gotoxy(29, 6);
	cout << " <>   IMPORT Courses     ";

	gotoxy(29, 8);
	cout << " <>   ADD Course         ";

	gotoxy(29, 10);
	cout << " <>   REMOVE Course      ";	
	
	gotoxy(29, 12);
	cout << " <>   REMOVE Student     ";
	
	gotoxy(29, 14);
	cout << " <>   ADD Students       ";
	
	gotoxy(29, 16);
	cout << " <>   EDIT Course        ";

	gotoxy(29, 18);
	cout << " <>   VIEW Course        ";

	gotoxy(29, 20);
	cout << " <>   VIEW Student       ";

	gotoxy(29, 22);
	cout << " <>   VIEW Attendance    ";

	gotoxy(29, 24);
	cout << " <>   ADD Lecturers     ";
	gotoxy(29, 26);
	cout << " <>   VIEW Lecturers     ";


	int CoursePointer = 0;
	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			CoursePointer++;
			if (CoursePointer > 12)
				CoursePointer = 1;
		}
		if (n == 72)//up 
		{
			CoursePointer--;
			if (CoursePointer < 1)
				CoursePointer = 12;
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
		CourseMenuAffect(CoursePointer);
	}
	if (CoursePointer == 1)//importstudent
	{
		AcademicYearScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 2)//chageclassa
	{
		ImportCourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 3)//removestudent
	{
		AddACourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 4)//AddStudent
	{
		RemoveACourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 5)//viewstudent
	{
		RemoveStudentFrCourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 6)//ViewsClass
	{
		AddStudentToCourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 7)//editInfo
	{
		EditCourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 8)//editInfo
	{
		ViewCourseScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 9)//editInfo
	{
		ViewStudentCourse();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 10)//editInfo
	{
		ViewAttendanceScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 11)//editInfo
	{
		AddLecturerScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}
	if (CoursePointer == 12)//editInfo
	{
		ViewLecturerScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
		ControlCourseMenuScreen(Usn);

	}

}