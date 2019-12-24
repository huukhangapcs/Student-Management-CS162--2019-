#include"getSTDdata.h"

void getClass(string &Class, string userName) // username la cai nguoi ta nhap khi dang nhap
{
	ifstream fin;
	fin.open("StudentLogin.txt");
	string i, p, c;
	while (!fin.eof())
	{
		getline(fin, i, ',' );
		getline(fin, p, ',');
		getline(fin, c);
		if (i != ""  && i == userName)
		{
			Class = c;
			break;
		}
	}
	fin.close();
}
void getstdData(string id, string Class, Student &st) // goi bien st khong can gan gia tri truoc
{
	ifstream fin;
	fin.open(Class + ".txt");
	if (!fin.is_open()) return;
	string x; 
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
		if (st.Id == id) break;
	}
	fin.close();
}