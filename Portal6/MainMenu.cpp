#include"Screen.h"
#include"GetcurrentTime.h"
#include"AddNewClass.h"
#include"AddNewStudent.h"
#include"ChangeLecturerPass.h"
#include"ChangeStaffPass.h"
#include"ChangeStudentPass.h"
#include"FindAStudent.h"
#include"RemoveAStudent.h"
#include"Student.h"
#include"DisplayStudent.h"
#include"DesignAffect.h"
#include"ChangeLecturerPass.h"
#include"ChangeStaffPass.h"
#include"ChangeStudentPass.h"
#include"EditAttendance.h"
#include"EditScore.h"
#include"StudentCheckIn.h"
#include"getSTDdata.h"
#include"ViewSchedule.h"
#include"Student.h"
#include"InputPassword.h"
#include"ScoreBoard.h"
void EditAttendanceScreen() {
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
		cout << "<< E D I T  A T T E N D A N C E >> ";
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
		string acaYear, term;
		char *courseid, *Class;
		int curWeek;
		courseid = new char[100];
		Class = new char[100];
		gotoxy(103, 9);
		inputData(Class);
		gotoxy(103, 12);
		inputData(courseid);
		
		
		

		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		getCurrentWeek(curWeek);
		getAcayearvsTerm(acaYear, term);
		editAttendance(acaYear, term, Class, courseid,curWeek);
		gotoxy(109, 46);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		
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
};
void EditStudentGradeScreen() {
	{
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
			cout << "         C l a s s: |";
			gotoxy(79, 12);
			cout << "C o u r s e s  I D: |";
			gotoxy(79, 15);
			cout << "S t u d e n t  I D: |";



			gotoxy(110, 5);
			cout << "<<     E D I T   G R A D E    >> ";
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
			string acaYear, term;
			char *courseid, *Class,*stdId;
			stdId = new char[100];
			courseid = new char[100];
			Class = new char[100];
			gotoxy(103, 9);
			inputData(Class);
			gotoxy(103, 12);
			inputData(courseid);
			gotoxy(103, 15);
			inputData(stdId);



			for (int j = 7; j < 20; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}
			
			getAcayearvsTerm(acaYear, term);
			editScore(acaYear, term, Class, courseid, stdId);
			gotoxy(109, 46);
			TextColor(12);
			cout << "<>[ . R E W R I T E ? ]<>";

			delete[]stdId;
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
	};
}
void ChangePassScreen(int hehe, string Usn) {
	if (hehe == 1)
	{
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
			cout << "CURRENT Password  : |";
			gotoxy(79, 12);
			cout << "  NEW   Password  : |";
			gotoxy(79, 15);
			cout << "rewrite New Pass  : |";



			gotoxy(110, 5);
			cout << "<< C H A N G E  P A S S W O R D >> ";
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
			char *courseid, *Class, *acaYear;
			acaYear = new char[100];
			courseid = new char[100];
			Class = new char[100];
			gotoxy(103, 9);
			inputData(acaYear);
			gotoxy(103, 12);
			inputData(courseid);
			gotoxy(103, 15);
			inputData(Class);


			for (int j = 7; j < 20; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}


			ChangeStaffPass(acaYear, courseid, Class);
	
	gotoxy(109, 35);
	TextColor(12);
	cout << "<>[ . R E W R I T E ? ]<>";

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
	}
	 if (hehe == 2||hehe==3) {
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
			 gotoxy(76, 9);
			 cout << "CURENT P a s s w o r d:|";
			 gotoxy(79, 12);
			 cout << "NEW P a s s w o r d:|";
			 gotoxy(79, 15);
			 cout << "rewrite new P a s s:|";


			 gotoxy(110, 5);
			 cout << "<< C H A N G E  P A S S W O R D >> ";
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
			 char *curpass, *npass, *repass;
			 curpass = new char[100];
			 npass = new char[100];
			 repass = new char[100];
			 gotoxy(103, 9);
			 InputPassword(curpass);
			 gotoxy(103, 12);
			 InputPassword(npass);
			 gotoxy(103, 15);
			 InputPassword(repass);

			 for (int j = 7; j < 20; ++j)
			 {
				 gotoxy(60, j);
				 cout << "                                                                                                   ";

			 }
			 if(hehe==2)
			 ChangeLecturerPassWord(Usn, curpass, npass,repass);
			 if (hehe == 3)
			 ChangeStudentPassWord(Usn, curpass, npass, repass);
			 gotoxy(109, 35);
			 TextColor(12);
			 cout << "<>[ . R E W R I T E ? ]<>";

			 delete[]curpass;
			 delete[]npass;
			 delete[]repass;
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

	
};
void ViewScheduleScreen(string Usn) {
	{
		while (1)
		{
#pragma region adding student
			/*char m;
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
			cout << "Academic Y e a r  : |";
			gotoxy(79, 12);
			cout << "         T e r m  : |";
			gotoxy(79, 15);
			cout << "       C l a s s  : |";
			*/


			gotoxy(110, 5);
			cout << "<<  V I E W  S C H E D U L E  >> ";
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


			/*gotoxy(100, 7);
			TextColor(7);
			cout << "{  P L E A S E   E N T E R  'I N F O M A T I O N'  } ";*/
#pragma endregion

			TextColor(7);
			string acaYear, term,clss;
			getAcayearvsTerm(acaYear, term);
			getClass(clss, Usn);


			for (int j = 7; j < 20; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}

			
			viewSchedule(acaYear, term, clss);
			gotoxy(109, 46);
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
	};
}
void StudentCheckInScreen(string Usn) {
	while (1) {
		gotoxy(110, 5);
		TextColor(6);
		cout << "<<      C h e c k -  i n      >> ";
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
		string clss;
		int week;
		getCurrentWeek(week);
		getClass(clss,Usn);
		studentCheckin(Usn,clss,week);
		gotoxy(109, 46);
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
void ViewCheckinScreen(string Usn) {
	while (1) {
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
			cout << "C O U R S E  I D  : |";
			
			
		gotoxy(110, 5);
		TextColor(6);
		cout << "<<      C h e c k -  i n      >> ";
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
		char*courseID=new char[100];

		string clss,acaYear,term;
		gotoxy(103, 9);
		inputData(courseID);

		getAcayearvsTerm(acaYear, term);
		getClass(clss, Usn);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		displayAttendanceOfAStudent(acaYear,term, courseID,clss, Usn);
		gotoxy(109, 46);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]courseID;
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
void ViewScoreScreen(string Usn) {
	while (1) {
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
		cout << "C O U R S E  I D  : |";


		gotoxy(110, 5);
		TextColor(6);
		cout << "<<      C h e c k -  i n      >> ";
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
		char*courseID = new char[100];

		string clss, acaYear, term;
		gotoxy(103, 9);
		inputData(courseID);

		getAcayearvsTerm(acaYear, term);
		getClass(clss, Usn);
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		displayScoreOfAStudent(acaYear, term, courseID, clss, Usn);
		gotoxy(109, 46);
		TextColor(12);
		cout << "<>[ . R E W R I T E ? ]<>";

		delete[]courseID;
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
void UpdateWeekScreen() {
	while (1) {
		/*char m;
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
		cout << "C O U R S E  I D  : |";*/


		gotoxy(110, 5);
		TextColor(6);
		cout << "<<    UPDATE CURRENT WEEK     >> ";
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
		/*gotoxy(100, 7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'I N F O M A T I O N'  } ";*/

		int curweek;
		gotoxy(103, 9);
		getCurrentWeek(curweek);

		
	
		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		updateCurrentWeek(curweek);
		gotoxy(109, 46);
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
void ViewStudentInfoScreen(string Usn) {
	while (1) {
		gotoxy(110, 5);
		TextColor(6);
		cout << "<<V I E W  I N F O M A T I O N>> ";
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
		/*gotoxy(100, 7);
		TextColor(7);
		cout << "{  P L E A S E   E N T E R  'I N F O M A T I O N'  } ";*/


		for (int j = 7; j < 20; ++j)
		{
			gotoxy(60, j);
			cout << "                                                                                                   ";

		}
		string clss;
		Student st;
		getClass(clss, Usn);
		getstdData(Usn,clss, st);
		displayAStudent2(st);
		gotoxy(109, 46);
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

void MenuDisplay(string Usn);
void MainMenuAffect(int PointerPosition) {
	TextColor(6);
	for (int i = 0; i < 28; i++)
	{
		for (int j = 9; j < 35; j += 4)
		{
			char n = 127;
			gotoxy(i, j);
			cout << n;
		}
	}
	TextColor(7);
	gotoxy(0, 10);
	cout << "                          " << endl;
	cout << "   []   CLASS             " << endl;
	cout << "                          " << endl;

	gotoxy(0, 14);
	cout << "                          " << endl;
	cout << "   []   COURSE            " << endl;
	cout << "                          " << endl;
	gotoxy(0, 18);
	cout << "                          " << endl;
	cout << "   []   SCOREBOARD        " << endl;
	cout << "                          " << endl;
	gotoxy(0, 22);
	cout << "                          " << endl;
	cout << "   []   ATTENDANCE LIST   " << endl;
	cout << "                          " << endl;
	gotoxy(0, 26);
	cout << "                          " << endl;
	cout << "   []  UPDATE CURRENT WEEK" << endl;
	cout << "                          " << endl;
	TextColor(3);
	gotoxy(0, 30);
	cout << "                          " << endl;
	cout << "   {}   Change Password   " << endl;
	cout << "                          " << endl;
	TextColor(3);
	gotoxy(0, 34);
	cout << "                          " << endl;
	cout << "   {}   Log Out           " << endl;
	cout << "                          " << endl;

	switch (PointerPosition)
	{
	case 1:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j < 14; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 10);
		cout << "                          " << endl;
		cout << "  <[ ]> C L A S S         " << endl;
		cout << "                          " << endl;
		break;
	case 2:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 13; j < 18; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 14);
		cout << "                          " << endl;
		cout << "  <[ ]> C O U R S E       " << endl;
		cout << "                          " << endl;
		break;
	case 3:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 17; j < 22; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 18);
		cout << "                          " << endl;
		cout << " <[ ]> S C O R E B O A R D" << endl;
		cout << "                          " << endl;
		break;

	case 4:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 21; j < 26; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 22);
		cout << "                          " << endl;
		cout << "  <[ ]> ATTENDANCE LIST   " << endl;
		cout << "                          " << endl;
		break;
	case 5:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 25; j < 30; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 26);
		cout << "                          " << endl;
		cout << " <[ ]> UPDATE CURRENT WEEK" << endl;
		cout << "                          " << endl;
		break;
	case 6:
		TextColor(14);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 29; j < 34; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		gotoxy(0, 30);
		cout << "                          " << endl;
		cout << "  {( )} Change Password   " << endl;
		cout << "                          " << endl;
		break;
	case 7:
		TextColor(12);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 33; j < 38; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}

		gotoxy(0, 34);
		cout << "                          " << endl;
		cout << "  {( )} Log Out           " << endl;
		cout << "                          " << endl;
		break;
	default:
		break;
	}
}
void ControlMenuScreen(string Usn)
{
	int PointerPosition = 0;

	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			PointerPosition++;
			if (PointerPosition > 7)
				PointerPosition = 1;
		}
		if (n == 72)//up 
		{
			PointerPosition--;
			if (PointerPosition < 1)
				PointerPosition = 7;
		}
		if (n == 27)//esc
		{
			ExitProcess(0);
		}
		if (n == 13)//enter
		{
			break;
		}
		{

			MainMenuAffect(PointerPosition);
		}
	}
	if (PointerPosition == 1)//Vao Class
	{
		ControlClassMenuScreen(Usn);
	}



	if (PointerPosition == 2)//Vao Course
	{
		ControlCourseMenuScreen(Usn);
	}
	if (PointerPosition == 3) //Vao Scoreboard
	{
		ControlScoreboardScreen(Usn);
	}
	if (PointerPosition == 4)//Vao Attendeance List
	{
		ControlAttendaceScreen(Usn);
	}
	if (PointerPosition == 5)//vao Change pass
	{
		UpdateWeekScreen();
	}
	if (PointerPosition == 6)//vao Change pass
	{
		ChangePassScreen(1, Usn);
	}
	if (PointerPosition == 7)//logout
	//Vao Attendeance List
	{
		system("cls");
		string b[9];
#pragma region the logo                                                                                
		b[0] = "10101110      101100111010    11010010    0110110110111011     110         100                     1001";
		b[1] = "111    011   10   110   001   101    111        o0|1o        011 101       110                    111";
		b[2] = "001     101  10 011     100   001     101        0|0        111    111     101                  110 ";
		b[3] = "110    011   1110       001   111    010         1|1       0101     001    111                 011";
		b[4] = "1001101      010        110   110  111           1|1      1001101    111   000                101    1010";
		b[5] = "001          110       1101   001   010          1|1      111    11  010   110                110       001";
		b[6] = "100          001     101 00   101    110         1|1      011      01101   010            o   001       100";
		b[7] = "111          111   101   11   011     101        1|0      101        011   111           ooo   111     010";
		b[8] = "010           101110101011    110      011       1|1      111        110   ---01010111    o      101010";
#pragma endregion
		//logodisplay
		TextColor(11);
		for (int i = 0; i < 9; ++i)
		{
			gotoxy(45, 5 + i);
			cout << b[i] << endl;
		}
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(78, 17);
		cout << "%%%%%  L . </> . G . I . N  %%%%%";
		gotoxy(70, 22);
		TextColor(14);
		cout << " P L E A S E <> D E C L A I R - I D E N T I T Y :";
		Sleep(500);
		gotoxy(77, 25);
		TextColor(12);
		cout << "* * * * * * | | <!> | | * * * * * *";
		TextColor(7);
		Sleep(150);
		gotoxy(79, 27);
		cout << "- A C A D E M I C  S T A F F -";
		Sleep(150);
		gotoxy(86, 29);
		cout << "- T E A C H E R -";
		Sleep(150);
		gotoxy(86, 31);
		cout << "- S T U D E N T -";
		Login(Usn);

	}
}
void MenuDisplay(string Usn)
{
	while (1)
	{
		system("cls");
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(2, 2);
		cout << "Portal.6";
		gotoxy(0, 3);
		for (int i = 0; i < 190; ++i)
		{
			char n = 205;
			gotoxy(i, 3);
			cout << n;
		}
		gotoxy(28, 3);
		char n = 203;
		cout << n;
		gotoxy(28, 4);
		for (int i = 4; i < 50; ++i)
		{
			char n = 186;
			gotoxy(28, i);
			cout << n;
		}
		gotoxy(28, 4);
		gotoxy(4, 5);
		TextColor(11);
		cout << "  M . E . N . U";
		TextColor(6);
		for (int i = 0; i <= 18; ++i)
		{
			char n = 174;
			gotoxy(3 + i, 4);
			cout << n;
			n = 175;
			gotoxy(3 + i, 6);
			cout << n;
		}
		TextColor(11);
		n = 178;
		gotoxy(2, 5);
		cout << n;
		gotoxy(22, 5);
		cout << n;
		TextColor(6);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j < 40; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(7);
		gotoxy(0, 11);
		cout << "   []   CLASS             ";
		gotoxy(0, 15);
		cout << "   []   COURSE            ";
		gotoxy(0, 19);
		cout << "   []   SCOREBOARD        ";
		gotoxy(0, 23);
		cout << "   []   ATTENDANCE LIST   ";
		gotoxy(0, 27);
		cout << "   []  UPDATE CURRENT WEEK";
		TextColor(3);
		gotoxy(0, 30);
		cout << "                          " << endl;
		cout << "   {}   Change Password   " << endl;
		cout << "                          " << endl;
		gotoxy(0, 34);
		TextColor(3);
		cout << "                          " << endl;
		cout << "   {}   Log Out           " << endl;
		cout << "                          " << endl;
		ControlMenuScreen(Usn);

	}
}





void LecturerMenuDisplay(string Usn);
void LecturerMainMenuAffect(int PointerPosition) {
	TextColor(6);
	
	for (int i = 0; i < 28; i++)
	{
		for (int j = 9; j < 48; j += 4)
		{
			char n = 127;
			gotoxy(i, j);
			cout << n;
		}
	}
	TextColor(7);
	gotoxy(0, 10);
	cout << "                          " << endl;
	cout << "   [] VIEW COURSE LIST   " << endl;//1
	cout << "                          " << endl;

	gotoxy(0, 14);
	cout << "                          " << endl;
	cout << "   [] VIEW STUDENT LIST   " << endl;//2
	cout << "                          " << endl;
	gotoxy(0, 18);
	cout << "                          " << endl;
	cout << "   [] VIEW ATTENDANCE LIST" << endl;//3
	cout << "                          " << endl;
	gotoxy(0, 22);
	cout << "                          " << endl;
	cout << "   [] EDIT ATTENDANCE LIST" << endl;//4
	cout << "                          " << endl;
	gotoxy(0, 26);
	cout << "                          " << endl;
	cout << "   [] IMPORT SCOREBOARD   " << endl;//5
	cout << "                          " << endl;
	gotoxy(0, 30);
	cout << "                          " << endl;
	cout << "   [] EDIT STUDENT GRADE  " << endl;//6
	cout << "                          " << endl;
	gotoxy(0, 34);
	cout << "                          " << endl;
	cout << "   [] VIEW SCOREBOARD     " << endl;//7
	cout << "                          " << endl;

	TextColor(3);
	gotoxy(0, 38);
	cout << "                          " << endl;
	cout << "   {}   Change Password   " << endl;//8
	cout << "                          " << endl;
	TextColor(3);
	gotoxy(0, 42);
	cout << "                          " << endl;
	cout << "   {}   Log Out           " << endl;//9
	cout << "                          " << endl;

	switch (PointerPosition)
	{
	case 1:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j < 14; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 10);
		cout << "                          " << endl;
		cout << "  < > VIEW COURSE LIST   " << endl;
		cout << "                          " << endl;
		break;
	case 2:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 13; j < 18; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 14);
		cout << "                          " << endl;
		cout << "  < > VIEW STUDENT LIST   " << endl;
		cout << "                          " << endl;
		break;
	case 3:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 17; j < 22; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 18);
		cout << "                          " << endl;
		cout << "  < > VIEW ATTENDANCE LIST" << endl;
		cout << "                          " << endl;
		break;

	case 4:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 21; j < 26; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 22);
		cout << "                          " << endl;
		cout << "  < > EDIT ATTENDANCE LIST" << endl;
		cout << "                          " << endl;
		break;

	case 5:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 25; j < 30; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 26);
		cout << "                          " << endl;
		cout <<"  < > IMPORT SCOREBOARD   " << endl;//6
		cout << "                          " << endl;
		break;
		
	case 6:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 29; j < 34; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 30);
		cout << "                          " << endl;
		cout << "  < > EDIT STUDENT GRADE  " << endl;
		cout << "                          " << endl;
		break;

	case 7:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 33; j < 38; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 34);
		cout << "                          " << endl;
		cout << "  < > VIEW SCOREBOARD     " << endl;
		cout << "                          " << endl;
		break;




	case 8:
		TextColor(14);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 37; j < 42; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		gotoxy(0, 38);
		cout << "                            " << endl;
		cout << "  {( )} Change Password   " << endl;
		cout << "                          " << endl;
		break;
	case 9:
		TextColor(12);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 41; j < 46; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}

		gotoxy(0, 42);
		cout << "                          " << endl;
		cout << "  {( )} Log Out           " << endl;
		cout << "                          " << endl;
		break;
	default:
		break;
	}
}
void ControlLecturerMenuScreen(string Usn)
{
	int PointerPosition = 0;

	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			PointerPosition++;
			if (PointerPosition > 9)
				PointerPosition = 1;
		}
		if (n == 72)//up 
		{
			PointerPosition--;
			if (PointerPosition < 1)
				PointerPosition = 9;
		}
		if (n == 27)//esc
		{
			ExitProcess(0);
		}
		if (n == 13)//enter
		{
			break;
		}
		{

			LecturerMainMenuAffect(PointerPosition);
		}
	}
	if (PointerPosition == 1)//Vao Class
	{
		ViewCourseScreen();
	}
	if (PointerPosition == 2)//Vao Course
	{
		ViewStudentCourse();
	}
	if (PointerPosition == 3) //Vao Scoreboard
	{
		ViewAttendanceScreen();
	}
	if (PointerPosition == 4) //Vao Scoreboard
	{
		EditAttendanceScreen();
	}
	if (PointerPosition == 5) //Vao Scoreboard
	{
		ImportScoreBoardScreen();
	}
	if (PointerPosition == 6)//Vao Attendeance List
	{
		EditStudentGradeScreen();
	}
	if (PointerPosition == 7)//vao Change pass
	{
		ViewScoreBoardScreen();
	}
	if (PointerPosition == 8) //Vao Scoreboard
	{
		ChangePassScreen(2, Usn);
	}
	if (PointerPosition == 9)//Vao Attendeance List
	{
		system("cls");
		string b[9];
#pragma region the logo                                                                                
		b[0] = "10101110      101100111010    11010010    0110110110111011     110         100                     1001";
		b[1] = "111    011   10   110   001   101    111        o0|1o        011 101       110                    111";
		b[2] = "001     101  10 011     100   001     101        0|0        111    111     101                  110 ";
		b[3] = "110    011   1110       001   111    010         1|1       0101     001    111                 011";
		b[4] = "1001101      010        110   110  111           1|1      1001101    111   000                101    1010";
		b[5] = "001          110       1101   001   010          1|1      111    11  010   110                110       001";
		b[6] = "100          001     101 00   101    110         1|1      011      01101   010            o   001       100";
		b[7] = "111          111   101   11   011     101        1|0      101        011   111           ooo   111     010";
		b[8] = "010           101110101011    110      011       1|1      111        110   ---01010111    o      101010";
#pragma endregion
		//logodisplay
		TextColor(11);
		for (int i = 0; i < 9; ++i)
		{
			gotoxy(45, 5 + i);
			cout << b[i] << endl;
		}
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(78, 17);
		cout << "%%%%%  L . </> . G . I . N  %%%%%";
		gotoxy(70, 22);
		TextColor(14);
		cout << " P L E A S E <> D E C L A I R - I D E N T I T Y :";
		Sleep(500);
		gotoxy(77, 25);
		TextColor(12);
		cout << "* * * * * * | | <!> | | * * * * * *";
		TextColor(7);
		Sleep(150);
		gotoxy(79, 27);
		cout << "- A C A D E M I C  S T A F F -";
		Sleep(150);
		gotoxy(86, 29);
		cout << "- T E A C H E R -";
		Sleep(150);
		gotoxy(86, 31);
		cout << "- S T U D E N T -";
		Login(Usn);
		
	}
	
}
void LecturerMenuDisplay(string Usn)
{
	while (1)
	{
		system("cls");
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(2, 2);
		cout << "Portal.6";
		gotoxy(0, 3);
		for (int i = 0; i < 190; ++i)
		{
			char n = 205;
			gotoxy(i, 3);
			cout << n;
		}
		gotoxy(28, 3);
		char n = 203;
		cout << n;
		gotoxy(28, 4);
		for (int i = 4; i < 50; ++i)
		{
			char n = 186;
			gotoxy(28, i);
			cout << n;
		}
		gotoxy(28, 4);
		gotoxy(4, 5);
		TextColor(11);
		cout << "  M . E . N . U";
		TextColor(6);
		for (int i = 0; i <= 18; ++i)
		{
			char n = 174;
			gotoxy(3 + i, 4);
			cout << n;
			n = 175;
			gotoxy(3 + i, 6);
			cout << n;
		}
		TextColor(11);
		n = 178;
		gotoxy(2, 5);
		cout << n;
		gotoxy(22, 5);
		cout << n;
		TextColor(6);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j <48; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(7);
		gotoxy(0, 11);
		cout << "   [] VIEW COURSE LIST    ";
		gotoxy(0, 15);
		cout << "   [] VIEW STUDENT LIST   " ;
		gotoxy(0, 19);
		cout << "   [] VIEW ATTENDANCE LIST" ;//3
		gotoxy(0, 23);
		cout << "   [] EDIT ATTENDANCE LIST" ;
		gotoxy(0, 27);
		cout << "   [] IMPORT SCOREBOARD   ";
		gotoxy(0, 31);
		cout << "   [] EDIT STUDENT GRADE  " ;//6
		gotoxy(0, 35);
		cout << "   [] VIEW SCOREBOARD     ";
		TextColor(3);
		gotoxy(0, 38);
		cout << "                          " << endl;
		cout << "   {}   Change Password   " << endl;
		cout << "                          " << endl;
		gotoxy(0, 42);
		TextColor(3);
		cout << "                          " << endl;
		cout << "   {}   Log Out           " << endl;
		cout << "                          " << endl;
		ControlLecturerMenuScreen(Usn);

	}
}


void StudentMenuDisplay(string Usn);
void StudentMainMenuAffect(int PointerPosition) {
	TextColor(6);

	for (int i = 0; i < 28; i++)
	{
		for (int j = 9; j < 40; j += 4)
		{
			char n = 127;
			gotoxy(i, j);
			cout << n;
		}
	}
	TextColor(7);
	gotoxy(0, 10);
	cout << "                          " << endl;
	cout << "   [] CHECK-IN           " << endl;//1
	cout << "                          " << endl;

	gotoxy(0, 14);
	cout << "                          " << endl;
	cout << "   [] VIEW CHECK-IN RESULT" << endl;//2
	cout << "                          " << endl;
	gotoxy(0, 18);
	cout << "                          " << endl;
	cout << "   [] VIEW SCHEDULE       " << endl;//3
	cout << "                          " << endl;
	gotoxy(0, 22);
	cout << "                          " << endl;
	cout << "   [] VIEW SCOREBOARD     " << endl;//7
	cout << "                          " << endl;
	gotoxy(0, 26);
	cout << "                          " << endl;
	cout << "   [] VIEW INFORMATION    "<< endl;//7
	cout << "                          " << endl;
	TextColor(3);
	gotoxy(0, 30);
	cout << "                          " << endl;
	cout << "   {}   Change Password   " << endl;//8
	cout << "                          " << endl;
	TextColor(3);
	gotoxy(0, 34);
	cout << "                          " << endl;
	cout << "   {}   Log Out           " << endl;//9
	cout << "                          " << endl;

	switch (PointerPosition)
	{
	case 1:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j < 14; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 10);
		cout << "                          " << endl;
		cout << "  < > CHECK-IN           " << endl;//1
		cout << "                          " << endl;
		break;
	case 2:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 13; j < 18; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 14);
		cout << "                          " << endl;
		cout << "  < > VIEW CHECK-IN RESULT" << endl;//2
		cout << "                          " << endl;
		break;
	case 3:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 17; j < 22; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 18);
		cout << "                          " << endl;
		cout << "  < > VIEW SCHEDULE       " << endl;//3
		cout << "                          " << endl;
		break;

	case 4:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 21; j < 26; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 22);
		cout << "                          " << endl;
		cout << "  < > VIEW SCOREBOARD     " << endl; 
		cout << "                          " << endl;
		break;

	case 5:
		TextColor(11);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 25; j < 30; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(13);
		gotoxy(0, 26);
		cout << "                          " << endl;
		cout << "  < > VIEW INFORMATION    " << endl;
		cout << "                          " << endl;
		break;

	case 6:
		TextColor(14);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 29; j < 34; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		gotoxy(0, 30);
		cout << "                            " << endl;
		cout << "  {( )} Change Password   " << endl;
		cout << "                          " << endl;
		break;
	case 7:
		TextColor(12);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 33; j < 38; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}

		gotoxy(0, 34);
		cout << "                          " << endl;
		cout << "  {( )} Log Out           " << endl;
		cout << "                          " << endl;
		break;
	default:
		break;
	}
}
void ControlStudentMenuScreen(string Usn)
{
	int PointerPosition = 0;

	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			PointerPosition++;
			if (PointerPosition > 7)
				PointerPosition = 1;
		}
		if (n == 72)//up 
		{
			PointerPosition--;
			if (PointerPosition < 1)
				PointerPosition = 7;
		}
		if (n == 27)//esc
		{
			ExitProcess(0);
		}
		if (n == 13)//enter
		{
			break;
		}
		{

			StudentMainMenuAffect(PointerPosition);
		}
	}
	if (PointerPosition == 1)//Vao Class
	{
		
		StudentCheckInScreen(Usn);
		
	}
	if (PointerPosition == 2)//Vao Course
	{
		ViewCheckinScreen(Usn);
	}
	if (PointerPosition == 3) //Vao Scoreboard
	{
		ViewScheduleScreen(Usn);
		

	}
	if (PointerPosition == 4) //Vao Scoreboard
	{
		ViewScoreScreen(Usn);
	}
	if (PointerPosition == 5) //Vao Scoreboard
	{
		ViewStudentInfoScreen(Usn);
	}
	if (PointerPosition == 6) //Vao Scoreboard
	{
		ChangePassScreen(3, Usn);
	}
	if (PointerPosition == 7)//Vao Attendeance List
	{
		system("cls");
		string b[9];
#pragma region the logo                                                                                
		b[0] = "10101110      101100111010    11010010    0110110110111011     110         100                     1001";
		b[1] = "111    011   10   110   001   101    111        o0|1o        011 101       110                    111";
		b[2] = "001     101  10 011     100   001     101        0|0        111    111     101                  110 ";
		b[3] = "110    011   1110       001   111    010         1|1       0101     001    111                 011";
		b[4] = "1001101      010        110   110  111           1|1      1001101    111   000                101    1010";
		b[5] = "001          110       1101   001   010          1|1      111    11  010   110                110       001";
		b[6] = "100          001     101 00   101    110         1|1      011      01101   010            o   001       100";
		b[7] = "111          111   101   11   011     101        1|0      101        011   111           ooo   111     010";
		b[8] = "010           101110101011    110      011       1|1      111        110   ---01010111    o      101010";
#pragma endregion
		//logodisplay
		TextColor(11);
		for (int i = 0; i < 9; ++i)
		{
			gotoxy(45, 5 + i);
			cout << b[i] << endl;
		}
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(78, 17);
		cout << "%%%%%  L . </> . G . I . N  %%%%%";
		gotoxy(70, 22);
		TextColor(14);
		cout << " P L E A S E <> D E C L A I R - I D E N T I T Y :";
		Sleep(500);
		gotoxy(77, 25);
		TextColor(12);
		cout << "* * * * * * | | <!> | | * * * * * *";
		TextColor(7);
		Sleep(150);
		gotoxy(79, 27);
		cout << "- A C A D E M I C  S T A F F -";
		Sleep(150);
		gotoxy(86, 29);
		cout << "- T E A C H E R -";
		Sleep(150);
		gotoxy(86, 31);
		cout << "- S T U D E N T -";
		Login(Usn);

	}

}
void StudentMenuDisplay(string Usn)
{
	while (1)
	{
		system("cls");
		gotoxy(84, 1);
		TextColor(15);
		cout << "<< G r 0 u P * 6 >> ";
		gotoxy(2, 2);
		cout << "Portal.6";
		gotoxy(0, 3);
		for (int i = 0; i < 190; ++i)
		{
			char n = 205;
			gotoxy(i, 3);
			cout << n;
		}
		gotoxy(28, 3);
		char n = 203;
		cout << n;
		gotoxy(28, 4);
		for (int i = 4; i < 50; ++i)
		{
			char n = 186;
			gotoxy(28, i);
			cout << n;
		}
		gotoxy(28, 4);
		gotoxy(4, 5);
		TextColor(11);
		cout << "  M . E . N . U";
		TextColor(6);
		for (int i = 0; i <= 18; ++i)
		{
			char n = 174;
			gotoxy(3 + i, 4);
			cout << n;
			n = 175;
			gotoxy(3 + i, 6);
			cout << n;
		}
		TextColor(11);
		n = 178;
		gotoxy(2, 5);
		cout << n;
		gotoxy(22, 5);
		cout << n;
		TextColor(6);
		for (int i = 0; i < 28; i++)
		{
			for (int j = 9; j < 40; j += 4)
			{
				char n = 127;
				gotoxy(i, j);
				cout << n;
			}
		}
		TextColor(7);
		gotoxy(0, 11);
		cout << "   [] CHECK-IN           ";
		gotoxy(0, 15);
		cout << "   [] VIEW CHECK-IN RESULT";
		gotoxy(0, 19);
		cout << "   [] VIEW SCHEDULE       ";//3
		gotoxy(0, 23);
		cout << "   [] VIEW SCOREBOARD     ";
		gotoxy(0, 27);
		cout << "   [] VIEW INFORMATION    ";
		TextColor(3);
		gotoxy(0, 30);
		cout << "                          " << endl;
		cout << "   {}   Change Password   " << endl;
		cout << "                          " << endl;
		gotoxy(0, 34);
		TextColor(3);
		cout << "                          " << endl;
		cout << "   {}   Log Out           " << endl;
		cout << "                          " << endl;
		ControlStudentMenuScreen(Usn);

	}
}
