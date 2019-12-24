#include"Course.h"

void CreateList(Linked &list)
{
	list.pHead = list.pTail = nullptr;
}
//
Course* CreateNewCourse(string Id, string Name, string Class, string LecAccount, string stDay, string enDay, string day, string stHour, string enHour, string Room)
{
	Course *p = new Course;
	if (p != nullptr)
	{
		p->Id = Id;
		p->Name = Name;
		p->Class = Class;
		p->LecAccount = LecAccount;
		p->stDay = stDay;
		p->enDay = enDay;
		p->day = day;
		p->stHour = stHour;
		p->enHour = enHour;
		p->Room = Room;
		p->pNext = nullptr;
	}
	return p;
}
//
void InsertNewCourse(Linked &list, string Id, string Name, string Class, string LecAccount, string stDay, string enDay, string day, string stHour, string enHour, string Room)
{
	Course *p = CreateNewCourse(Id, Name, Class, LecAccount, stDay, enDay, day, stHour, enHour, Room);
	if (p == nullptr) return;
	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		list.pHead = list.pTail = p;
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
}
//
bool loadCourseFromFile(string filePath, string &firstLine, Linked &list)
{
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) return false;
	string No, Id, Name, Class, LecAccount, stDay, enDay, day, stHour, enHour, Room;
	getline(fin, firstLine); // loai bo dong dau tien
	while (!fin.eof())
	{
		getline(fin, No, ',');
		if (No == "") break;
		getline(fin, Id, ',');
		getline(fin, Name, ',');
		getline(fin, Class, ',');
		getline(fin, LecAccount, ',');
		getline(fin, stDay, ',');
		getline(fin, enDay, ',');
		getline(fin, day, ',');
		getline(fin, stHour, ',');
		getline(fin, enHour, ',');
		getline(fin, Room);
		InsertNewCourse(list, Id, Name, Class, LecAccount, stDay, enDay, day, stHour, enHour, Room);
	}
	fin.close();
	return true;
}
//
int countNumOfExistedCourse(string acaYear, string term)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + ".txt");
	int dem = 0;
	string x;
	getline(fin, x); // bo dong dau tien
	while (!fin.eof())
	{
		getline(fin, x);
		if (x != "") dem++;
	}
	return dem;
}
//
bool checkIfCourseExisted(string acaYear, string term, string CourseId, string ClassName)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + ".txt");
	if (!fin.is_open()) return false;
	string No, id, name, Class, data;
	string trash;

	getline(fin, trash); // dong dau tien
	while (!fin.eof())
	{
		getline(fin, No, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, Class, ',');
		getline(fin, data);
		/////
		if (CourseId == id && ClassName == Class) return true;
	}
	fin.close();
	return false;
}
//
bool checkIfLecAccountExisted(string LecAccount)
{
	ifstream fin;
	fin.open("LecturerLogin.txt");
	string usN;
	string pass;
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		getline(fin, usN, ',');
		getline(fin, pass);
		if (usN == LecAccount) return true;
	}
	fin.close();
	return false;
}
//
void saveCourseToFile(string acaYear, string term, Linked list, string firstLine)
{
	CreateAcaYear(acaYear, term);
	// save to file ex: 2018-2019term2.txt
	ifstream fin;
	ofstream fout1;
	fin.open(acaYear + "_" + term + ".txt");
	fout1.open(acaYear + "_" + term + ".txt", ios::out | ios::app);
	int dem = 0;
	if (!fin.is_open()) fout1 << firstLine << endl;
	else dem = countNumOfExistedCourse(acaYear, term);
	fin.close();
	////////////////////////////////////////////////////////////////////////// 
	Course *tmp = list.pHead;
	while (tmp != nullptr)
	{
		if (!checkIfCourseExisted(acaYear, term, tmp->Id, tmp->Class))
		{
			dem++;
			fout1 << dem << ",";
			fout1 << tmp->Id << ",";
			fout1 << tmp->Name << ",";
			fout1 << tmp->Class << ",";
			fout1 << tmp->LecAccount << ",";
			fout1 << tmp->stDay << ",";
			fout1 << tmp->enDay << ",";
			fout1 << tmp->day << ",";
			fout1 << tmp->stHour << ",";
			fout1 << tmp->enHour << ",";
			fout1 << tmp->Room << endl;
			loadStudentToCourse(tmp, acaYear, term);
			CreateAttendanceList(tmp, acaYear, term);
			CreateScoreBoard(tmp, acaYear, term);
		}
		tmp = tmp->pNext;
	}
	fout1.close();

	// save to file Lecturer Login
	ofstream fout2;
	fout2.open("LecturerLogin.txt", ios::out | ios::app);
	ofstream fout3;
	fout3.open(acaYear + "_" + term + "_LecturerList.txt", ios::out | ios::app);
	Course *tmp2 = list.pHead;
	while (tmp2 != nullptr)
	{
		if (!checkIfLecAccountExisted(tmp2->LecAccount))
		{
			fout2 << tmp2->LecAccount << ",";
			fout2 << tmp2->LecAccount << endl;
			fout3 << tmp2->LecAccount << endl;
		}
		tmp2 = tmp2->pNext;

	}
	fout2.close();
	fout3.close();
}
//
void loadStudentToCourse(Course *p, string acaYear, string term)
{
	ifstream fin;

	fin.open(p->Class + ".txt");
	string content = "";
	string x;
	if (!fin.is_open())
	{
		return;
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, x);
			if (x != "") content += x + "\n";
		}
	}
	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + p->Class + "_" + p->Id + ".txt", ios::out | ios::app);
	fout << content;
	fout.close();
	fin.close();
}
//
void CreateAcaYear(string acaYear, string term)
{
	if (!checkIfAcaYearIsExisted(acaYear))
	{
		ofstream fout;
		fout.open("ListAcademicYear.txt", ios::out | ios::app);
		fout << acaYear << endl;
		fout.close();
	}
	if (!checkIfTermIsExisted(acaYear, term))
	{
		ofstream fout1;
		fout1.open(acaYear + ".txt", ios::out | ios::app);
		fout1 << term << endl;
		fout1.close();
	}
}
//
bool checkIfAcaYearIsExisted(string acaYear)
{
	ifstream fin;
	fin.open("ListAcademicYear.txt");
	if (!fin.is_open()) return false;
	string eY;
	while (!fin.eof())
	{
		getline(fin, eY);
		if (eY == acaYear) return true;
	}
	fin.close();
	return false;
}
//
bool checkIfTermIsExisted(string acaYear, string term)
{
	ifstream fin;
	fin.open(acaYear + ".txt");
	if (!fin.is_open()) return false;
	string tm;
	while (!fin.eof())
	{
		getline(fin, tm);
		if (tm == term) return true;
	}
	fin.close();
	return false;
}
//
void CreateAttendanceList(Course *p, string Year, string Term)
{
	ifstream fin;
	fin.open(p->Class + ".txt");
	string content = "";
	string x;
	string no, id, lname, fname, remain;
	if (!fin.is_open())
	{
		return;
	}
	else
	{
		getline(fin, x, ',');
		if (x != "")
		{
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",Week 1,Week 2,Week 3,Week 4,Week 5,Week 6,Week 7,Week 8,Week 9,Week 10\n";
			getline(fin, x);
		}

		while (!fin.eof())
		{
			getline(fin, no, ',');
			getline(fin, id, ',');
			getline(fin, lname, ',');
			getline(fin, fname, ',');
			getline(fin, remain);
			if (no != "")
			{
				content += no + ",";
				content += id + ",";
				content += lname + ",";
				content += fname + ",-,-,-,-,-,-,-,-,-,-\n";
			}

		}
	}
	ofstream fout;
	fout.open(Year + "_" + Term + "_" + p->Class + "_" + p->Id + "_AttendanceList" + ".txt", ios::out | ios::app);
	fout << content;
	fout.close();
	fin.close();
}
//
void CreateScoreBoard(Course *p, string Year, string Term)
{
	ifstream fin;
	fin.open(p->Class + ".txt");
	string content = "";
	string x;
	string no, id, lname, fname, remain;
	if (!fin.is_open())
	{
		return;
	}
	else
	{
		getline(fin, x, ',');
		if (x != "")
		{
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",";
			getline(fin, x, ',');
			content += x + ",Midterm,Lab,Bonus,Final\n";
			getline(fin, x);
		}
		while (!fin.eof())
		{
			getline(fin, no, ',');
			getline(fin, id, ',');
			getline(fin, lname, ',');
			getline(fin, fname, ',');
			getline(fin, remain);
			if (no != "")
			{
				content += no + ",";
				content += id + ",";
				content += lname + ",";
				content += fname + ",0,0,0,0\n";
			}

		}
	}
	ofstream fout;
	fout.open(Year + "_" + Term + "_" + p->Class + "_" + p->Id + "_ScoreBoard" + ".txt", ios::out | ios::app);
	fout << content;
	fout.close();
	fin.close();
}
//
void deleteLinked(Linked &list)
{
	Course *tmp = list.pHead;
	while (tmp != nullptr)
	{
		list.pHead = list.pHead->pNext;
		delete tmp;
		tmp = list.pHead;
	}
}
