#include"RemoveACourse.h"
#include"DesignAffect.h"
void RemoveACourse(string acaYear, string term, char *id, char *Class)
{
	Course st;
	if (FindACourse(acaYear, term, id, Class, st))
	{
		displayCourse(acaYear, term, id, Class, st);
		gotoxy(106, 33);
		cout << "<> DO YOU WANT TO REMOVE THIS COURSE?  <>   ";
		int key;
		key = _getch();
		if (key == 13)
		{
			RemoveCourseInfor(st, acaYear, term, id, Class);
			gotoxy(104, 33);
        cout << "        <> DELETE COURSE COMPLETED!  <>     ";
			return;
		}
		else if(key==27) {
			gotoxy(98, 33);
			cout << "                                                        ";
			return;
		}
	}
	else return;
}

void RemoveCourseInfor(Course st,string acaYear, string term, char *id, char *Class)
{
	ifstream fin;
	string acaY = acaYear;
	string trm = term;
	string sId = id;
	string css = Class;
	fin.open(acaY + "_" + trm + ".txt");
	string content;
	string n, Id, na, Css, lec, sD, eD, d, sH, eH, rm;
	int dem = 0;
	//
	getline(fin, content); // loai bo dong dau tien
	content += '\n';
	while (!fin.eof())
	{
		getline(fin, n, ',');
		getline(fin, Id, ',');
		getline(fin, na, ',');
		getline(fin, Css, ',');
		getline(fin, lec, ',');
		getline(fin, sD, ',');
		getline(fin, eD, ',');
		getline(fin, d, ',');
		getline(fin, sH, ',');
		getline(fin, eH, ',');
		getline(fin, rm);
		if (n == "") continue;
		else
		{
			if (Id != st.Id || Css != st.Class)
			{
				dem++;
				content += to_string(dem);
				content += ',';
				content += Id;
				content += ',';
				content += na;
				content += ',';
				content += Css;
				content += ',';
				content += lec;
				content += ',';
				content += sD;
				content += ',';
				content += eD;
				content += ',';
				content += d;
				content += ',';
				content += sH;
				content += ',';
				content += eH;
				content += ',';
				content += rm;
				content += '\n';
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaY + "_" + trm + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	remove((acaY + "_" + trm + "_" + st.Class + "_" + st.Id + ".txt").c_str());
	remove((acaY + "_" + trm + "_" + st.Class + "_" + st.Id + "_ScoreBoard.txt").c_str());
	remove((acaY + "_" + trm + "_" + st.Class + "_" + st.Id + "_AttendanceList.txt").c_str());
}