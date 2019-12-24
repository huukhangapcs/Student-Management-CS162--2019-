#include"Screen.h"
#include"InputData.h"
#include"AddNewClass.h"
#include"AddNewStudent.h"
#include"changeClass.h"
#include"RemoveAStudent.h"
#include"DisplayStudent.h"
#include"EditAStudent.h"
#include"GetcurrentTime.h"
void AddClassScreen() {
	
		
		while (1)
		{
#pragma region adding class
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
			cout << "  C l a s s  n a m e :|";
			n = '|';
			gotoxy(151, 20);
			cout << n;
			for (int i = 0; i <= 50; ++i)
			{
				char n = 196;
				gotoxy(100 + i, 22);
				cout << n;
				gotoxy(100 + i, 24);
				cout << n;
			}
			n = 218;
			gotoxy(99, 22);
			cout << n;
			n = 192;
			gotoxy(99, 24);
			cout << n;
			n = 191;
			gotoxy(151, 22);
			cout << n;
			n = 217;
			gotoxy(151, 24);
			cout << n;
			gotoxy(77, 23);
			cout << "  D r i v e  f i l e :|";
			n = '|';
			gotoxy(151, 23);
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
			char *filePath, *ClassName;
			filePath = new char[100];
			ClassName = new char[100];
			gotoxy(103, 20);
			
			inputData(ClassName);
			gotoxy(103, 23);
			
			inputData(filePath);
			AddNewClass(filePath, ClassName);
			gotoxy(109, 30);
			TextColor(11);
			cout << "<>[ . R E W R I T E . ]<>";
			int key = _getch();
			if (key == 13)
			{
				gotoxy(95, 25);
				cout << "                                                     ";
				gotoxy(110, 26);
				cout << "                                                     ";
				gotoxy(109, 30);
				cout << "                                                     ";
				gotoxy(103, 20); 
				cout << "                                                     ";
				gotoxy(103, 23);
				cout << "                                                     ";

			}
			if (key == 27)
				break;
		}
}
void ChangeStudentScreen() {
	while (1)
	{
#pragma region adding student
		char m;
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			 m = 196;

			gotoxy(100+i, 8);
			cout << m;
			gotoxy(100+i,10);
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
			gotoxy(151,10);
			cout << m;
		
		TextColor(11);
		for (int i = 0; i < 8; ++i)
		{
			char n = '|';
			gotoxy(151, 9);
			cout << n;
		}
		gotoxy(79, 9);
		cout <<        "S t u d e n t  I D: |";
		gotoxy(110, 5);
		cout << "<<  C H A N G E  C L A S S  >> ";
		for (int i = 0; i <= 32; ++i)
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
		gotoxy(141, 5);
		cout << n;
		gotoxy(100,7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'S T U D E N T - I D'  } ";
#pragma endregion
		TextColor(7);
		char* id;
		id = new char[100];
		gotoxy(103, 9);
		inputData(id);
		for (int j = 7; j <20 ; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		string acaYear = "", term = "";
		getAcayearvsTerm(acaYear, term);
		ChangeClass(id,acaYear,term);
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";
		
		delete[]id;
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
void RemoveStudentScreen(){
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
			cout << "S t u d e n t  I D: |";
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
			char* id;
			id = new char[100];
			string acaYear;
			string term;
			gotoxy(103, 9);
			inputData(id);
			getAcayearvsTerm(acaYear, term);
			RemoveAStudent(id, acaYear, term);
			gotoxy(109, 35);
			TextColor(12);
			cout << "<>[ . R E W R I T E ? ]<>";

			delete[]id;
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
void AddStudentScreen() {
	while (1)
	{
#pragma region adding student
		TextColor(6);
		for (int i = 0; i <= 50; ++i)
		{
			for (int j = 0; j <= 21; j += 3)
			{
				char n = 196;

				gotoxy(100 + i, 9 + j);
				cout << n;
				gotoxy(100 + i, 9 + j + 2);
				cout << n;
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			char n = 218;
			gotoxy(99, 9 + 3 * i);
			cout << n;
		}
		for (int i = 0; i < 8; ++i)
		{
			char n = 192;
			gotoxy(99, 11 + 3 * i);
			cout << n;

		}
		for (int i = 0; i < 8; ++i)
		{
			char n = 191;
			gotoxy(151, 9 + 3 * i);
			cout << n;
		}
		for (int i = 0; i < 8; ++i)
		{
			char n = 217;
			gotoxy(151, 11 + 3 * i);
			cout << n;
		}
		TextColor(11);
		for (int i = 0; i < 8; ++i)
		{
			char n = '|';
			gotoxy(151, 10 + 3 * i);
			cout << n;
		}
		gotoxy(79, 10);

		cout << "C l a s s  n a m e :|";
		gotoxy(80, 13);
		cout << "S t u d e n t  I D:|";
		gotoxy(76, 16);
		cout << "    F i r s t  N a m e:|";
		gotoxy(76, 19);
		cout << "      L a s t  N a m e:|";
		gotoxy(87, 22);
		cout << "G e n d e r:|";
		gotoxy(77, 25);
		cout << "D a y  O f  B i r t h:|";
		gotoxy(73, 28);
		cout << "M o n t h  O f  B i r t h:|";
		gotoxy(75, 31);
		cout << "Y e a r  O f  B i r t h:|";
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
		char* ClassName, *nId, *nLName, *nFName, *nGender, *nYearOB, *nMonthOB, *nDateOB;
		nId = new char[100];
		nLName = new char[100];
		nFName = new char[100];
		nGender = new char[100];
		nYearOB = new char[100];
		nMonthOB = new char[100];
		nDateOB = new char[100];
		ClassName = new char[100];
		gotoxy(103, 10);
		inputData(ClassName);

		gotoxy(103, 13);
		inputData(nId);
		gotoxy(103, 16);
		inputData(nFName);
		gotoxy(103, 19);
		inputData(nLName);
		gotoxy(103, 22);
		inputData(nGender);
		gotoxy(103, 25);
		inputData(nDateOB);
		gotoxy(103, 28);
		inputData(nMonthOB);
		gotoxy(103, 31);
		inputData(nYearOB);
		AddNewStudent(ClassName, nId, nLName, nFName, nGender, nYearOB, nMonthOB, nDateOB);
		gotoxy(109, 36);
		TextColor(11);
		cout << "<>[ . R E W R I T E . ]<>";
		delete[]ClassName;
		delete[]nId;
		delete[]nLName;
		delete[]nFName;
		delete[]nGender;
		delete[]nYearOB;
		delete[]nMonthOB;
		delete[]nDateOB;
		ClassName;
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
			gotoxy(103, 36);
			cout << "                                                     ";
		}
		if (key == 27)
			break;
	}
}
void ViewStudentScreen() {
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
		gotoxy(77, 9);
		cout << "  C l a s s  n a m e :|";
		
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
		cout << "{ P L E A S E   E N T E R  ' C L A S S - N A M E ' } ";
#pragma endregion
		TextColor(7);
		char* classname;
		classname = new char[100];
		gotoxy(103, 9);
		inputData(classname);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		displayStudentList(classname);
		gotoxy(109, 45);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]classname;
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
void ViewClassScreen() {
	while (1)
	{

		TextColor(7);
		int numofClass=0;		
		displayClassList2(numofClass);
	

		
		int key = _getch();
		if (key == 13)
		{
			break;
		}
		if (key == 27)
			break;
	}
}
void EditInfoScreen() {
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
		cout << "S t u d e n t  I D: |";
		gotoxy(110, 5);
		cout << "<< E D I T   I N F O M A T I O N >> ";
		for (int i = 0; i <= 37; ++i)
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
		gotoxy(146, 5);
		cout << n;
		gotoxy(100, 7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'S T U D E N T - I D'  } ";
#pragma endregion
		TextColor(7);
		char* id;
		id = new char[100];
		string acaYear;
		string term;
		gotoxy(103, 9);
		inputData(id);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getAcayearvsTerm(acaYear, term);
		EditAStudent(id, acaYear, term);
		
		gotoxy(109, 35);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]id;
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
void ClassMenuAffect(int ClassPointer) {
	TextColor(12);
	gotoxy(29, 10);
	cout << "                         ";
	gotoxy(29, 11);
	cout << " <>   IMPORT Classes     ";
	gotoxy(29, 12);
	cout << "                         ";
	gotoxy(29, 14);
	cout << "                         ";
	gotoxy(29, 15);
	cout << " <>   CHANGE Student     ";
	gotoxy(29, 16);
	cout << "                         ";
	gotoxy(29, 18);
	cout << "                         ";
	gotoxy(29, 19);
	cout << " <>   REMOVE Student     ";
	gotoxy(29, 20);
	cout << "                         ";
	gotoxy(29, 22);
	cout << "                         ";
	gotoxy(29, 23);
	cout << " <>   ADD Student        ";
	gotoxy(29, 24);
	cout << "                         ";
	gotoxy(29, 26);
	cout << "                         ";
	gotoxy(29, 27);
	cout << " <>   VIEW Students      ";
	gotoxy(29, 28);
	cout << "                         ";
	gotoxy(29, 30);
	cout << "                         ";
	gotoxy(29, 31);
	cout << " <>   VIEW Classes       ";
	gotoxy(29, 32);
	cout << "                         ";
	gotoxy(29, 34);
	cout << "                         ";
	gotoxy(29, 35);
	cout << " <>   EDIT Info          ";
	gotoxy(29, 36);
	cout << "                         ";
	switch (ClassPointer)
	{
	case 1:
		
		gotoxy(29, 10); TextColor(6);
		cout << "------------------------\\";
		gotoxy(29, 11); TextColor(9);
		cout << "   { IMPORT Classes }   " ;
		gotoxy(29, 12); TextColor(6);
		cout << "------------------------/";
		break;
	case 2:
		
		gotoxy(29, 14); TextColor(9);
		cout << "------------------------\\" ;
		gotoxy(29, 15); TextColor(6);
		cout << "   { CHANGE Student }    ";
		gotoxy(29, 16); TextColor(9);
		cout << "------------------------/" ;
		break;
	case 3:
		gotoxy(29, 18);
		TextColor(6);
		cout << "------------------------\\";
		TextColor(9);
		gotoxy(29, 19);
		cout << "   { REMOVE Student }   ";
		gotoxy(29, 20); TextColor(6);
		cout << "------------------------/";
		break;

	case 4:
		gotoxy(29, 22);
		TextColor(9);
		cout << "------------------------\\";
		TextColor(6);
		gotoxy(29, 23);
		cout << "   { ADD Student }   ";
		gotoxy(29, 24); 
		TextColor(9);
		cout << "------------------------/";
		break;
	case 5:
		gotoxy(29, 26);
		TextColor(6);
		cout << "------------------------\\";
		TextColor(9);
		gotoxy(29, 27);
		cout << "   { VIEW Students }   ";
		gotoxy(29, 28);
		TextColor(6);
		cout << "------------------------/";
		
		break;
	case 6:
		gotoxy(29, 30);
		TextColor(9);
		cout << "------------------------\\";
		TextColor(6);
		gotoxy(29, 31);
		cout << "   {  VIEW Classes  }   ";
		gotoxy(29, 32);
		TextColor(9);
		cout << "------------------------/";
		
		break;
	case 7:
		gotoxy(29, 34);
		TextColor(6);
		cout << "------------------------\\";
		TextColor(9);
		gotoxy(29, 35);
		cout << "   {   EDIT Info    }   ";
		gotoxy(29, 36);
		TextColor(6);
		cout << "------------------------/";
		
		break;

	default:
		break;
	}
}
void ControlClassMenuScreen(string Usn) {
	TextColor(11);
	for (int i = 4; i < 50; ++i)
	{
		char m = 177;
		gotoxy(55, i);
		cout << m;
	}
	TextColor(12);
	gotoxy(29, 10);
	cout << "                         ";
	gotoxy(29, 11);
	cout << " <>   IMPORT Classes     ";
	gotoxy(29, 12);
	cout << "                         ";
	gotoxy(29, 14);
	cout << "                         ";
	gotoxy(29, 15);
	cout << " <>   CHANGE Student     ";
	gotoxy(29, 16);
	cout << "                         ";
	gotoxy(29, 18);
	cout << "                         ";
	gotoxy(29, 19);
	cout << " <>   REMOVE Student     ";
	gotoxy(29, 20);
	cout << "                         ";
	gotoxy(29, 22);
	cout << "                         ";
	gotoxy(29, 23);
	cout << " <>   ADD Student        ";
	gotoxy(29, 24);
	cout << "                         ";
	gotoxy(29, 26);
	cout << "                         ";
	gotoxy(29, 27);
	cout << " <>   VIEW Students      ";
	gotoxy(29, 28);
	cout << "                         ";
	gotoxy(29, 30);
	cout << "                         ";
	gotoxy(29, 31);
	cout << " <>   VIEW Classes       ";
	gotoxy(29, 32);
	cout << "                         ";
	gotoxy(29, 34);
	cout << "                         ";
	gotoxy(29, 35);
	cout << " <>   EDIT Info          ";
	gotoxy(29, 36);
	cout << "                         ";
	int ClassPointer = 0;
	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			ClassPointer++;
			if (ClassPointer > 7)
				ClassPointer = 1;
		}
		if (n == 72)//up 
		{
			ClassPointer--;
			if (ClassPointer < 1)
				ClassPointer = 7;
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
		ClassMenuAffect(ClassPointer);
	}
	if (ClassPointer == 1)//importstudent
	{
		AddClassScreen();
		for (int j = 5; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 2)//chageclassa
	{
		ChangeStudentScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 3)//removestudent
	{
		RemoveStudentScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 4)//AddStudent
	{
		AddStudentScreen();
		for (int j = 5; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 5)//viewstudent
	{
		ViewStudentScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(56, j);
			cout << "                                                                                                                                   ";
		}
	ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 6)//ViewsClass
	{
		ViewClassScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
	if (ClassPointer == 7)//editInfo
	{
		EditInfoScreen();
		for (int j = 4; j < 50; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		ControlClassMenuScreen(Usn);

	}
}