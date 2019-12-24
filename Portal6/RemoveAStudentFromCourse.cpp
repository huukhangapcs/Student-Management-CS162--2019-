#include"RemoveAStudentFromCourse.h"
#include"DesignAffect.h"
void RemoveStdFromCourse(char *stdId, string acaYear, string term, char *courseId, char *Class)
{
	ifstream fin;
	Student st;
	string acaY = acaYear;
	string trm = term;
	string cId = courseId;
	string sId = stdId;
	string css = Class;
	fin.open(acaY + "_" + trm + "_" + css + "_" + cId + ".txt");
	if (!fin.is_open())
	{
		gotoxy(110,18);
		cout << "C A N' T  R E M O V E  ";
		return;
	}
	string x;
	string content = "";
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
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
		if (st.No != "")
		{
			if (st.Id != sId)
			{
				dem++;
				content += to_string(dem);
				content += ",";
				content += st.Id;
				content += ",";
				content += st.lName;
				content += ",";
				content += st.fName;
				content += ",";
				content += st.gender;
				content += ",";
				content += st.YearOB;
				content += "-";
				content += st.MonthoB;
				content += "-";
				content += st.DateOB;
				content += "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaY + "_" + trm + "_" + css + "_" + cId + ".txt");
	fout << content;
	fout.close();
	gotoxy(113,18);
	cout << "R E M O V E  C O M P L E T E D !";
}
void RemoveAStdFromAttendanceList(string acaY, string term, string cId, string clss, string sid)
{
	ifstream fin;
	fin.open(acaY + "_" + term + "_" + clss + "_" + cId + "_AttendanceList.txt");
	if (!fin.is_open()) return;
	string x;
	string no, id, lname, fname, remain;
	string content = "";
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (sid != id)
			{
				dem++;
				content += to_string(dem);
				content += ",";
				content += id;
				content += ",";
				content += lname;
				content += ",";
				content += fname;
				content += ",";
				content += remain;
				content += "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaY + "_" + term + "_" + clss + "_" + cId + "_AttendanceList.txt");
	fout << content;
	fout.close();
}
void RemoveAStdFromScoreBoard(string acaY, string term, string cId, string clss, string sid)
{
	ifstream fin;
	fin.open(acaY + "_" + term + "_" + clss + "_" + cId + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string x;
	string no, id, lname, fname, remain;
	string content = "";
	getline(fin, x);
	content += x + "\n";
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, lname, ',');
		getline(fin, fname, ',');
		getline(fin, remain);
		if (no != "")
		{
			if (sid != id)
			{
				dem++;
				content += to_string(dem);
				content += ",";
				content += id;
				content += ",";
				content += lname;
				content += ",";
				content += fname;
				content += ",";
				content += remain;
				content += "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaY + "_" + term + "_" + clss + "_" + cId + "_ScoreBoard.txt");
	fout << content;
	fout.close();
}