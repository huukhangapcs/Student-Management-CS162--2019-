#include"EditACourse.h"
#include"DesignAffect.h"

void EditACourse(string acaYear, string  term, char *id, char *Class)
{
	Course st;
	if (FindACourse(acaYear, term, id, Class, st))
	{
		Course pre = st; // luu thong tin cua hoc sinh truoc khi thay doi de thuc hien viec doi mat khau.
		changeCourseInfor(acaYear, term, id, Class, st);
		saveEditedLecLogin(st, pre);
		saveEditedLecData(acaYear, term, st, pre);
	}
	else return;
}
void changeCourseInfor(string acaYear, string term, char *id, char *Class, Course &st)
{
	displayCourse(acaYear, term, id, Class, st);
	int n = 0;
	while (1)
	{
		
		
		
		int point = _getch();
		if (point == 80)//down
		{
			n++;
			if (n > 6)
				n = 1;
		}
		if (point == 72)//up 
		{
			n--;
			if (n < 1)
				n = 6;
		}
		if (point == 27)//esc
		{
			return;
		}
		if (point == 13)//enter
		{
			break;
		}
	
		if (n == 1) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 11);
			cout << ".COURSE Id     :| " << st.Id;
		
		}
		if (n == 2) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 14);
			cout << ".COURSE Name   :| " << st.Name;
		}
		if (n == 3) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 20);
			cout << ".Lecturer      :| " << st.LecAccount;
		}
		if (n == 4) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 23);
			cout << ".Start( y-m-d) :| " << st.stDay;
		}
		if (n == 5) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 26);
			cout << ".End  ( y-m-d) :| " << st.enDay;
		}
		if (n == 6) {
			displayCourse(acaYear, term, id, Class, st);
			TextColor(6);
			gotoxy(83, 29);
			cout << ".Schedule      :| " << st.day << "( " << st.stHour << "-" << st.enHour << " ) ROOM  " << st.Room;
		}
	}
	
	if (n == 1)
	{
		char *nId = new char[100];
		gotoxy(83+18,11);
		cout << "                                              ";
		gotoxy(83 + 18, 11);
		TextColor(15);
		cin.ignore(1);
		inputData(nId);
		st.Id = nId;
		delete[]nId;
		changeCourseInfor(acaYear, term, id, Class, st);
	}
	else if (n == 2)
	{
		char *name = new char[100];
		gotoxy(83 + 18, 14);
		cout << "                                              ";
		gotoxy(83 + 18, 14);
		TextColor(15);
		cin.ignore(1);
		inputData(name);
		st.Name = name;
		delete[]name;
		changeCourseInfor(acaYear, term, id, Class, st);
	}
	else if (n == 3)
	{
		char *lec = new char[100];
		gotoxy(83 + 18, 20);
		cout << "                                              ";
		gotoxy(83 + 18, 20);
		TextColor(15);
		cin.ignore(1);
		inputData(lec);
		st.LecAccount = lec;
		delete[]lec;
		changeCourseInfor(acaYear, term, id, Class, st);

	}
	else if (n == 4)
	{
		gotoxy(83 + 18, 23);
		cout << "                                              ";
		int stday, stmonth, styear;
		TextColor(11);
		gotoxy(100, 32);
		cout << "Date: ";
		cin >> stday;

		gotoxy(100,34);
		cout << "Month: ";
		cin >> stmonth;
		gotoxy( 100,36);

		cout << "Year: ";
		cin >> styear;
		if (checkValidDate(stday, stmonth, styear))
		{
			st.stDay = to_string(styear) + "-" + to_string(stmonth) + "-" + to_string(stday);
		}
		else
		{
			gotoxy( 100,38);

			cout << "Not valid date. ";
			
		}
		for (int i = 32; i < 50; i++) {
			gotoxy(60, i);
			cout << "                                                                                    ";
		}
		changeCourseInfor(acaYear, term, id, Class, st);
	}
	else if (n == 5)
	{
		gotoxy(83 + 18, 26);
		cout << "                                              ";
		int enday, enmonth, enyear;
		TextColor(11);
		gotoxy(100,32);
		cout << "Date: ";
		cin >> enday;
		gotoxy(100,34);
		cout << "Month: ";
		cin >> enmonth;
		gotoxy(100,36);
		cout << "Year: ";
		cin >> enyear;
		if (checkValidDate(enday, enmonth, enyear))
		{
			st.enDay = to_string(enyear) + "-" + to_string(enmonth) + "-" + to_string(enday);
		}
		else
		{
			gotoxy(100,38);
			cout << "Not valid date. ";
		
		}
		for (int i = 32; i < 50; i++) {
			gotoxy(60, i);
			cout << "                                                                                    ";
		}
		changeCourseInfor(acaYear, term, id, Class, st);
	}
	else if (n == 6)
	{
		gotoxy(83 + 18, 29);
		cout << "                                              ";
		gotoxy(100,32);
		cout << "Date in week change to :";
		gotoxy(100,34);
		TextColor(11);
		cout << "1. Mon  2. Tue  3. Wed  4. Thu  5. Fri  6. Sat  7. Sun" ;
		int M;
		gotoxy(100,36);
		cout << " PLEASE CHOOSE DAY:";
		TextColor(15);
		cin >> M;
		switch (M)
		{
		case 1: st.day = "Mon"; break;
		case 2: st.day = "Tue"; break;
		case 3: st.day = "Wed"; break;
		case 4: st.day = "Thu"; break;
		case 5: st.day = "Fri"; break;
		case 6: st.day = "Sat"; break;
		case 7: st.day = "Sun"; break;
		default: changeCourseInfor(acaYear, term, id, Class, st);
		}
		int stH, stMin, enH, enMin;
		gotoxy(60,38);
		TextColor(6);
		cout << "Start time change to :";
		gotoxy(100,38);
		cout << "Hour :";
		TextColor(15);
		cin >> stH;
		gotoxy(120,38);
		TextColor(6);
		cout << "Min :";
		TextColor(15);
		cin >> stMin;
		gotoxy(60,40 );
		TextColor(6);
		cout << "End time change to :";
		gotoxy( 100, 40 );
		cout << "Hour :";
		TextColor(15);
		cin >> enH;
		gotoxy(120,40);
		TextColor(6);

		cout << "Min :";
		TextColor(15);
		cin >> enMin;
		if (checkValidTime(stH, stMin) && checkValidTime(enH, enMin))
		{
			st.stHour = to_string(stH) + ":" + to_string(stMin);
			st.enHour = to_string(enH) + ":" + to_string(enMin);
		}
		else changeCourseInfor(acaYear, term, id, Class, st);

		gotoxy(60,44);
		cout << "ROOM CHANGE TO:";
		char * room = new char[10];
		inputData(room);
		st.Room = room;
		delete[]room;
		for (int i = 32; i <50 ; i++) {
			gotoxy(60,i);
			cout << "                                                                                                  ";
		}
		changeCourseInfor(acaYear, term, id, Class, st);
	}
	
}


void saveEditedLecLogin(Course st, Course pre)
{
	ifstream fin;
	string pass, usn;
	string content = "";
	fin.open("LecturerLogin.txt");
	while (!fin.eof())
	{
		getline(fin, usn, ',');
		getline(fin, pass);
		if (usn == "") continue;
		else
		{
			if (usn != pre.LecAccount)
			{
				content += usn;
				content += ",";
				content += pass;
				content += "\n";
			}
			else
			{
				content += st.LecAccount;
				content += ",";
				content += pass;
				content += "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open("LecturerLogin.txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
}
void saveEditedLecData(string acaYear, string term, Course st, Course pre)
{
	ifstream fin;
	string acaY = acaYear;
	string trm = term;
	fin.open(acaY + "_" + trm + ".txt");
	string no, sId, name, Clss, lecAcc, stD, enD, day, stH, enH, room;
	string content;
	//
	getline(fin, content); // loai bo dong dau tien
	content += '\n';
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, sId, ',');
		getline(fin, name, ',');
		getline(fin, Clss, ',');
		getline(fin, lecAcc, ',');
		getline(fin, stD, ',');
		getline(fin, enD, ',');
		getline(fin, day, ',');
		getline(fin, stH, ',');
		getline(fin, enH, ',');
		getline(fin, room);
		if (no == "") continue;
		else
		{
			if (sId != pre.Id || Clss != pre.Class)
			{
				content += no;
				content += ',';
				content += sId;
				content += ',';
				content += name;
				content += ',';
				content += Clss;
				content += ',';
				content += lecAcc;
				content += ',';
				content += stD;
				content += ',';
				content += enD;
				content += ',';
				content += day;
				content += ',';
				content += stH;
				content += ',';
				content += enH;
				content += ',';
				content += room;
				content += '\n';
			}
			else
			{
				content += no;
				content += ',';
				content += st.Id;
				content += ',';
				content += st.Name;
				content += ',';
				content += st.Class;
				content += ',';
				content += st.LecAccount;
				content += ',';
				content += st.stDay;
				content += ',';
				content += st.enDay;
				content += ',';
				content += st.day;
				content += ',';
				content += st.stHour;
				content += ',';
				content += st.enHour;
				content += ',';
				content += st.Room;
				content += '\n';
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaY + "_" + trm + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	rename((acaY + "_" + trm + "_" + pre.Class + "_" + pre.Id + ".txt").c_str(), (acaY + "_" + trm + "_" + st.Class + "_" + st.Id + ".txt").c_str());
}