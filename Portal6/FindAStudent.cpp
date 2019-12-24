#include"FindAStudent.h"
#include"DesignAffect.h"

bool FindAStudent(char *Id, Student &st, string &ClassName)
{
	if (!findStudentClassName(Id, ClassName))
	{
		TextColor(12);
		gotoxy(110,18);
		cout << "THE ID IS NOT MATCH.";
		//system("pause");
		return false;
	}
	if (!loadStudentInfor(ClassName, Id, st))
	{
		TextColor(12);
		gotoxy(110, 18);
		cout << "THE STUDENT IS NOT FOUND.";
		//system("pause");
		return false;
	}
	return true;
}
bool findStudentClassName(char *Id, string &ClassName)
{
	ifstream fin;
	fin.open("StudentLogin.txt");
	if (!fin.is_open()) return false;
	string id, pass;
	while (!fin.eof())
	{
		getline(fin, id, ',');
		getline(fin, pass, ',');
		getline(fin, ClassName);
		if (Id == id) return true;
	}
	fin.close();
	return false;
}
bool loadStudentInfor(string ClassName, char *id, Student &st)
{
	ifstream fin;
	fin.open(ClassName + ".txt");
	if (!fin.is_open()) return false;
	string x; // loai bo dong dau tien
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, st.No, ',');
		getline(fin, st.Id, ',');
		getline(fin, st.lName, ',');
		getline(fin, st.fName, ',');
		getline(fin, st.gender, ',');
		getline(fin, st.YearOB, '-');
		getline(fin, st.MonthoB, '-');
		getline(fin, st.DateOB);
		if (st.Id == id) return true;
	}
	fin.close();
	return false;
}