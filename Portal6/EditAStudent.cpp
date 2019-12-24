#include"EditAStudent.h"
#include"DesignAffect.h"
void EditAStudent(char *id, string acaYear, string term)
{
	Student st;
	string ClassName;
	if (FindAStudent(id, st, ClassName))
	{
		Student pre = st; // luu thong tin cua hoc sinh truoc khi thay doi de thuc hien viec doi mat khau.
		changeStudentInfor(id, st, acaYear, term);
		saveEditedLogin(st, pre);
		saveEditedData(st, ClassName, acaYear, term);
	}
	else return;
}
int StdPointer = 2;
void changeStudentInfor(char *id, Student &st, string acaYear, string term)
{
	while (1)
	{
		displayAStudent2(st);

		
		int n;
		n = _getch();
		if (n == 80)//down
		{
			StdPointer++;
			if (StdPointer > 6)
				StdPointer = 3;
		}
		if (n == 72)//up 
		{
			StdPointer--;
			if (StdPointer < 3)
				StdPointer = 6;
		}
		if (n == 27)//esc
		{
			return;
		}
		if (n == 13)//enter
		{
			break;
		}
		{

			if (StdPointer == 1) {
				TextColor(12);
				gotoxy(152,11);
				cout << "<>";
				gotoxy(152, 14);
				cout << "  ";
				gotoxy(152, 17);
				cout << "  ";
				gotoxy(152, 20);
				cout << "  ";
				gotoxy(152, 23);
				cout << "  ";
				gotoxy(152, 26);
				cout << "  ";
			}
			if (StdPointer == 2) {
				TextColor(12);
				gotoxy(152, 11);
				cout << "  ";
				gotoxy(152, 14);
				cout << "<>";
				gotoxy(152, 17);
				cout << "  ";
				gotoxy(152, 20);
				cout << "  ";
				gotoxy(152, 23);
				cout << "  ";
				gotoxy(152, 26);
				cout << "  ";
			}
			if (StdPointer == 3) {
				TextColor(12);
				gotoxy(152, 11);
				cout << "  ";
				gotoxy(152, 14);
				cout << "  ";
				gotoxy(152, 17);
				cout << "<>";
				gotoxy(152, 20);
				cout << "  ";
				gotoxy(152, 23);
				cout << "  ";
				gotoxy(152, 26);
				cout << "  ";
			}
			if (StdPointer == 4) {
				TextColor(12);
				gotoxy(152, 11);
				cout << "  ";
				gotoxy(152, 14);
				cout << "  ";
				gotoxy(152, 17);
				cout << "  ";
				gotoxy(152, 20);
				cout << "<>";
				gotoxy(152, 23);
				cout << "  ";
				gotoxy(152, 26);
				cout << "  ";
			}
			if (StdPointer == 5) {
				TextColor(12);
				gotoxy(152, 11);
				cout << "  ";
				gotoxy(152, 14);
				cout << "  ";
				gotoxy(152, 17);
				cout << "  ";
				gotoxy(152, 20);
				cout << "  ";
				gotoxy(152, 23);
				cout << "<>";
				gotoxy(152, 26);
				cout << "  ";
			}
			if (StdPointer == 6) {
				TextColor(12);
				gotoxy(152, 11);
				cout << "  ";
				gotoxy(152, 14);
				cout << "  ";
				gotoxy(152, 17);
				cout << "  ";
				gotoxy(152, 20);
				cout << "  ";
				gotoxy(152, 23);
				cout << "  ";
				gotoxy(152, 26);
				cout << "<>";
			}

		}
	}

	if (StdPointer == 1)//lastname
	{
		char *lname = new char[100];
		gotoxy(100, 11);
		cout << "                            ";
		gotoxy(100, 11);
		cin.ignore(1);
		inputData(lname);
		st.No = lname;
		delete[]lname;
		changeStudentInfor(id, st, acaYear, term);
	}
	if (StdPointer == 2)//lastname
	{
		char *lname = new char[100];
		gotoxy(100, 14);
		cout << "                            ";
		gotoxy(100, 14);
		cin.ignore(1);
		inputData(lname);
		st.Id = lname;
		delete[]lname;
		changeStudentInfor(id, st, acaYear, term);
	}
	if (StdPointer == 3)//lastname
	{
		char *lname = new char[100];
		gotoxy(100,17);
		cout << "                            ";
		gotoxy(100, 17);
		cin.ignore(1);
		inputData(lname);
		st.lName = lname;
		delete[]lname;
		changeStudentInfor(id, st, acaYear, term);
	}
	if (StdPointer == 4)//firstname
	{
		char *fname = new char[100];
		gotoxy(100, 20);
		cout << "                            ";
		gotoxy(100, 20);
		cin.ignore(1);
		inputData(fname);
		st.fName = fname;
		delete[]fname;
		changeStudentInfor(id, st, acaYear, term);
	}
	if (StdPointer == 5)//gender
	{
		char *gender = new char[100];
		gotoxy(100, 23);
		cout << "                            ";
		gotoxy(100, 23);
		cin.ignore(1);
		inputData(gender);
		st.gender = gender;
		delete[]gender;
		changeStudentInfor(id, st, acaYear, term);
	}
	if (StdPointer == 6)
	{
		int day, month, year;
		gotoxy(100, 28);
		cout << "Date: ";
		cin >> day;
		gotoxy(100, 30);
		cout << "Month: ";
		cin >> month;
		gotoxy(100, 32);
		cout << "Year: ";
		cin >> year;
		if (checkValidDate(day, month, year))
		{
			st.YearOB = to_string(year);
			st.MonthoB = to_string(month);
			st.DateOB = to_string(day);
		}
		else
		{
			gotoxy(100, 34);
			cout << "Not valid date. ";
		
		}
		for (int i = 28; i < 35; i++)
		{
			gotoxy(100, i);
			cout << "                                                     ";
		}
		changeStudentInfor(id, st, acaYear, term);
		
	}
	
}
void saveEditedLogin(Student st, Student pre)
{
	ifstream fin;
	string clName, pass, id;
	string content = "";
	fin.open("StudentLogin.txt");
	while (!fin.eof())
	{
		getline(fin, id, ',');
		getline(fin, pass, ',');
		getline(fin, clName);
		if (id == "") continue;
		else
		{
			if (id != st.Id)
			{
				content += id;
				content += ",";
				content += pass;
				content += ",";
				content += clName;
				content += "\n";
			}
			else
			{
				content += id;
				content += ",";
				if (pass == (pre.YearOB + pre.MonthoB + pre.DateOB))
				{
					content += (st.YearOB + st.MonthoB + st.DateOB);
				}
				else content += pass;
				content += ",";
				content += clName;
				content += "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open("StudentLogin.txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
}
void saveEditedData(Student st, string className, string acaYear, string term)
{
	ifstream fin;
	fin.open(className + ".txt");
	string no, id, lname, fname, gender, yob, mob, dob;
	string content;
	//
	getline(fin, content); // loai bo dong dau tien
	content += '\n';
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, gender, ',');
		getline(fin, yob, '-');
		getline(fin, mob, '-');
		getline(fin, dob);
		if (no == "") continue;
		else
		{
			if (no != st.No)
			{
				content += no;
				content += ',';
				content += id;
				content += ',';
				content += lname;
				content += ',';
				content += fname;
				content += ',';
				content += gender;
				content += ',';
				content += yob;
				content += '-';
				content += mob;
				content += '-';
				content += dob;
				content += '\n';
			}
			else
			{
				content += st.No;
				content += ',';
				content += st.Id;
				content += ',';
				content += st.lName;
				content += ',';
				content += st.fName;
				content += ',';
				content += st.gender;
				content += ',';
				content += st.YearOB;
				content += '-';
				content += st.MonthoB;
				content += '-';
				content += st.DateOB;
				content += '\n';
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(className + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	//
	ifstream fin2;
	fin2.open(acaYear + "_" + term + ".txt");
	if (!fin2.is_open()) return;
	string x, cid, cn, css, remain;
	getline(fin2, x);
	while (!fin2.eof())
	{
		getline(fin2, no, ',');
		getline(fin2, cid, ',');
		getline(fin2, cn, ',');
		getline(fin2, css, ',');
		getline(fin2, remain);
		if (no != "")
		{
			if (css == className)  // find the course name
			{
				saveEditedDataToCourse(acaYear, term, className, content, cid);
				saveEditedDatatoScoreBoard(acaYear, term, className, cid, st);
				saveEditedDatatoAttendance(acaYear, term, className, cid, st);

			}
		}
	}
	fin2.close();
}

void saveEditedDataToCourse(string acaYear, string term, string className, string content, string cId)
{
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + ".txt");
	fout << content;
	fout.close();
}
void saveEditedDatatoScoreBoard(string acaYear, string term, string className, string cId, Student st)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + className + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string no, id, lname, fname, diem;
	string data = "";
	getline(fin, data);
	data += "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, diem);
		if (no != "")
		{
			dem++;
			if (id != st.Id)
			{
				data += to_string(dem) + "," + id + "," + lname + "," + fname + "," + diem + "\n";
			}
			else
			{
				data += to_string(dem) + "," + st.Id + "," + st.lName + "," + st.fName + "," + diem + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + "_ScoreBoard.txt");
	fout << data;
	fout.close();
}
void saveEditedDatatoAttendance(string acaYear, string term, string className, string cId, Student st)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open()) return;
	string no, id, lname, fname, diemdanh;
	string data = "";
	getline(fin, data);
	data += "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, diemdanh);
		if (no != "")
		{
			dem++;
			if (id != st.Id)
			{
				data += to_string(dem) + "," + id + "," + lname + "," + fname + "," + diemdanh + "\n";
			}
			else
			{
				data += to_string(dem) + "," + st.Id + "," + st.lName + "," + st.fName + "," + diemdanh + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	fout << data;
	fout.close();
}