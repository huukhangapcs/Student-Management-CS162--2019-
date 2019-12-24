#include"FindACourse.h"
#include"DesignAffect.h"
bool FindACourse(string acaYear, string term, char *Id, char *Class, Course &st)
{
	if (!loadCourseInfor(acaYear, term, Id, Class, st))
	{
		gotoxy(110,20);
		TextColor(12);
		cout << "THE COURSE IS NOT FOUND.";
		return false;
	}
	return true;
}
bool loadCourseInfor(string  acaYear, string term, char *Id, char *Class, Course &st)
{
	string year = acaYear;
	string trm = term;
	string sId = Id;
	string Css = Class;
	ifstream fin;
	fin.open(year + "_" + trm + ".txt");
	if (!fin.is_open()) return false;
	string x; // loai bo dong dau tien
	string no;
	getline(fin, x);
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, st.Id, ',');
		getline(fin, st.Name, ',');
		getline(fin, st.Class, ',');
		getline(fin, st.LecAccount, ',');
		getline(fin, st.stDay, ',');
		getline(fin, st.enDay, ',');
		getline(fin, st.day, ',');
		getline(fin, st.stHour, ',');
		getline(fin, st.enHour, ',');
		getline(fin, st.Room);
		if (st.Id == sId && st.Class == Css) return true;
	}
	fin.close();
	return false;
}
