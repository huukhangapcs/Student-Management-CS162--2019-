#include"RemoveAStudent.h"
#include"DesignAffect.h"
void RemoveAStudent(char*id, string year, string term)
{
	Student st;
	string className;
	if (FindAStudent(id, st, className))
	{
		gotoxy(95,20);
		cout << "DO YOU WANT TO REMOVE THIS STUDENT FROM THIS CLASS. Y/N? :";
		char key;
		key = _getch();
		if (key == 'Y' || key == 'y')
		{
			RemoveLogin(st, className);
			RemoveInfor(st, className, year, term);
			gotoxy(100, 22);
			cout << "   C H A N G E  S T U D E N T  C O M P L E T E !  ";
			return;
		}
		else return;
	}
	else return;
}
void RemoveLogin(Student st, string& className)
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
				className = clName;
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open("StudentLogin.txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
}
void RemoveInfor(Student st, string className, string acaY, string t)
{
	ifstream fin;
	fin.open(className + ".txt");
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
	fout.open(className + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	//
	ifstream fin2;
	fin2.open(acaY + "_" + t + ".txt");
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
				RemoveCourseData(acaY, t, className, content, cid);
				RemoveScoreBoardData(acaY, t, className, cid, st);
				RemoveAttendanceData(acaY, t, className, cid, st);
			}
		}
	}
	fin2.close();
}

void RemoveCourseData(string acaYear, string term, string className, string content, string cId)
{
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + ".txt");
	fout << content;
	fout.close();
}
void RemoveScoreBoardData(string acaYear, string term, string className, string cId, Student st)
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
			if (id != st.Id)
			{
				dem++;
				data += to_string(dem) + "," + id + "," + lname + "," + fname + "," + diem + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + "_ScoreBoard.txt");
	fout << data;
	fout.close();
}
void RemoveAttendanceData(string acaYear, string term, string className, string cId, Student st)
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

			if (id != st.Id)
			{
				dem++;
				data += to_string(dem) + "," + id + "," + lname + "," + fname + "," + diemdanh + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + className + "_" + cId + "_AttendanceList.txt");
	fout << data;
	fout.close();
}