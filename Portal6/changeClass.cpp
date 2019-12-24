#include"changeClass.h"
#include"DesignAffect.h"
void ChangeClass(char *id, string acaYear, string term)
{
	Student st;
	string ClassA;
	if (FindAStudent(id, st, ClassA))
	{
		displayAStudent(st);
		gotoxy(83, 29);
		cout << "I n  C l a s s :|   " << ClassA;
		gotoxy(60, 34);
		TextColor(12);
		cout << " <>  Choose new class: ";
		gotoxy(65, 35);
		TextColor(11);
		cout << "(Enter the serial";
		gotoxy(60, 36);
		cout << "     of class to change,";
		gotoxy(60, 37);
		cout << "     In case If you want ";
		gotoxy(60, 38);
		cout << "     to cancel process";
		gotoxy(65, 39);
		cout << "-Enter 0)  ";


		int numofClass = 0;
		displayClassList(numofClass);

		int n;
		gotoxy(60 + 24, 34);
		cin >> n;

		if (n == 0)
		{
			for (int i = 32; i < 50; ++i)
			{

				gotoxy(60, i);
				cout << "                                                                                                   ";

			}
			return;
		}
		else if (n <= numofClass)
		{
			string classB;
			takeClassName(classB, n);
			saveLogin(st, ClassA, classB);
			saveData(st, ClassA, classB);
			ChangeStudentInCourse(acaYear, term, ClassA, classB, st);
			for (int j = 31; j < 50; ++j)
			{
				gotoxy(60, j);
				cout << "                                                                                                   ";

			}
			gotoxy(100, 32);
			cout << "   C H A N G E  S T U D E N T  C O M P L E T E !  ";
			return;
		}
		else
		{
			gotoxy(65, 40);
			cout << "<> Serial of Class is Invalid!";
			return;
		}

	}

	else
	{

		return;
	}
	
}
void saveLogin(Student st, string classA, string classB)
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
				content += pass;
				content += ",";
				content += classB;
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
void saveData(Student &st, string classA, string classB)
{
	ifstream fin;
	fin.open(classA + ".txt");
	string no, id, lname, fname, gender, yob, mob, dob;
	string content;
	//
	getline(fin, content); // loai bo dong dau tien
	content += '\n';
	int dem = 0;
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
				dem++;
				content += to_string(dem);
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
		}
	}
	fin.close();
	ofstream fout;
	fout.open(classA + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	//
	st.No = to_string(CountNumOfStudent(classB) + 1);
	ofstream fout2;
	fout2.open(classB + ".txt", ios::out | ios::app);
	fout2 << st.No << ",";
	fout2 << st.Id << ",";
	fout2 << st.lName << ",";
	fout2 << st.fName << ",";
	fout2 << st.gender << ",";
	fout2 << st.YearOB << "-";
	fout2 << st.MonthoB << "-";
	fout2 << st.DateOB << endl;
	fout2.close();
}
void ChangeStudentInCourse(string acaYear, string term, string ClassA, string ClassB, Student st)
{
	// idea: open year + term file to get course which belong to class A _ ex 18CTT2_CS161
	// Move student data from student list in course of classA to student list in course of class B
	// Move student data from attendance list ->...
	// Move student data from scoreboard->....
	ifstream fin;
	fin.open(acaYear + "_" + term + ".txt");
	if (!fin.is_open()) return;
	string x, no, cid, cn, css, remain;
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, cid, ',');
		getline(fin, cn, ',');
		getline(fin, css, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (css == ClassA)  // find the course name
			{
				changeCourseList(acaYear, term, cid, ClassA, ClassB, st);
				changeScoreBoard(acaYear, term, cid, ClassA, ClassB, st);
				changeAttendanceList(acaYear, term, cid, ClassA, ClassB, st);
			}
		}
	}
	fin.close();
}

void changeCourseList(string year, string term, string cId, string classA, string classB, Student st)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + classA + "_" + cId + ".txt");
	if (!fin.is_open()) return;
	string content = "";
	string x, no, id, remain;
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (id != st.Id) // remove out of class a
			{
				dem++;
				content += to_string(dem) + ",";
				content += id + ",";
				content += remain + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(year + "_" + term + "_" + classA + "_" + cId + ".txt");
	fout << content;
	fout.close();
	///////////////////
	string data = "";
	ifstream fin2;
	fin2.open(year + "_" + term + "_" + classB + "_" + cId + ".txt"); // write in class b
	if (!fin2.is_open()) // if file is not exist
	{
		data += "No,Student ID,Lastname,Firstname,Gender,DoB\n";
		data += "1,";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += st.gender + ",";
		data += st.YearOB + "-" + st.MonthoB + "-" + st.DateOB + "\n";
	}
	else
	{
		int numofstd = -1;
		while (!fin2.eof())
		{
			getline(fin2, x);
			if (x != "") numofstd++;
		}
		data += to_string(numofstd + 1) + ",";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += st.gender + ",";
		data += st.YearOB + "-" + st.MonthoB + "-" + st.DateOB + "\n";
	}
	fin2.close();
	ofstream fout2;
	fout2.open(year + "_" + term + "_" + classB + "_" + cId + ".txt", ios::out | ios::app);
	fout2 << data;
	fout2.close();
}

void changeScoreBoard(string year, string term, string cId, string classA, string classB, Student st)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + classA + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string content = "";
	string x;
	string no;
	Score sc;
	string diem;
	string remain;
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, sc.stdId, ',');
		getline(fin, sc.stdLName, ',');
		getline(fin, sc.stdFName, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (sc.stdId != st.Id) // remove out of class a
			{
				dem++;
				content += to_string(dem) + ",";
				content += sc.stdId + ",";
				content += sc.stdLName + ",";
				content += sc.stdFName + ",";
				content += remain + "\n";
			}
			else    // assign score to diem
			{
				diem = remain;
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(year + "_" + term + "_" + classA + "_" + cId + "_ScoreBoard.txt");
	fout << content;
	fout.close();
	///////////////////
	string data = "";
	ifstream fin2;
	fin2.open(year + "_" + term + "_" + classB + "_" + cId + "_ScoreBoard.txt"); // write in class b
	if (!fin2.is_open()) // if file is not exist
	{
		data += "No,Student ID,Lastname,Firstname,Midterm,Lab,Bonus,Final\n";
		data += "1,";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += diem + "\n";
	}
	else
	{
		int numofstd = -1;
		while (!fin2.eof())
		{
			getline(fin2, x);
			if (x != "") numofstd++;
		}
		data += to_string(numofstd + 1) + ",";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += diem + "\n";
	}
	fin2.close();
	ofstream fout2;
	fout2.open(year + "_" + term + "_" + classB + "_" + cId + "_ScoreBoard.txt", ios::out | ios::app);
	fout2 << data;
	fout2.close();
}
void changeAttendanceList(string year, string term, string cId, string classA, string classB, Student st)
{
	ifstream fin;
	fin.open(year + "_" + term + "_" + classA + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open()) return;
	string content = "";
	string x;
	string no;
	Attendance at;
	string diemdanh;
	string remain;
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, at.stdId, ',');
		getline(fin, at.stdLName, ',');
		getline(fin, at.stdFName, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (at.stdId != st.Id) // remove out of class a
			{
				dem++;
				content += to_string(dem) + ",";
				content += at.stdId + ",";
				content += at.stdLName + ",";
				content += at.stdFName + ",";
				content += remain + "\n";
			}
			else    // assign score to diem
			{
				diemdanh = remain;
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(year + "_" + term + "_" + classA + "_" + cId + "_AttendanceList.txt");
	fout << content;
	fout.close();
	///////////////////
	string data = "";
	ifstream fin2;
	fin2.open(year + "_" + term + "_" + classB + "_" + cId + "_AttendanceList.txt"); // write in class b
	if (!fin2.is_open()) // if file is not exist
	{
		data += "No,Student ID,Lastname,Firstname,Week 1,Week 2,Week 3,Week 4,Week 5,Week 6,Week 7,Week 8,Week 9,Week 10\n";
		data += "1,";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += diemdanh + "\n";
	}
	else
	{
		int numofstd = -1;
		while (!fin2.eof())
		{
			getline(fin2, x);
			if (x != "") numofstd++;
		}
		data += to_string(numofstd + 1) + ",";
		data += st.Id + ",";
		data += st.lName + ",";
		data += st.fName + ",";
		data += diemdanh + "\n";
	}
	fin2.close();
	ofstream fout2;
	fout2.open(year + "_" + term + "_" + classB + "_" + cId + "_AttendanceList.txt", ios::out | ios::app);
	fout2 << data;
	fout2.close();
}