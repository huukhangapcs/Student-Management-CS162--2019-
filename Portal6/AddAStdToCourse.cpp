#include"AddAStdToCourse.h"
#include"DesignAffect.h"
void AddAStdToCourse(char *stdId,string acaYear, string term, char *courseId, char *Class)
{
	Student st;
	string ClassName;
	if (FindAStudent(stdId, st, ClassName))
	{
		Student pre;
		string acaY = acaYear;
		string trm = term;
		string cId = courseId;
		string sId = stdId;
		string css = Class;
		ifstream fin;
		fin.open(acaY + "_" + trm + "_" + css + "_" + cId + ".txt");
		if (!fin.is_open())
		{
			gotoxy(110, 18);
			cout << "  C A N' T   A D D     ";
			return;
		}
		string x;
		string content = "";
		getline(fin, x);
		content += x;
		content += "\n";
		int dem = 0;
		while (!fin.eof())
		{
			getline(fin, pre.No, ',');
			getline(fin, pre.Id, ',');
			getline(fin, pre.lName, ',');
			getline(fin, pre.fName, ',');
			getline(fin, pre.gender, ',');
			getline(fin, pre.YearOB, '-');
			getline(fin, pre.MonthoB, '-');
			getline(fin, pre.DateOB);
			if (pre.No != "")
			{
				if (pre.Id != st.Id)
				{
					dem++;
					content += to_string(dem);
					content += ",";
					content += pre.Id;
					content += ",";
					content += pre.lName;
					content += ",";
					content += pre.fName;
					content += ",";
					content += pre.gender;
					content += ",";
					content += pre.YearOB;
					content += "-";
					content += pre.MonthoB;
					content += "-";
					content += pre.DateOB;
					content += "\n";
					
				}
				else
				{
					gotoxy(106, 18);
					cout << "E X I S T E D   S T U D E N T";
					return;
				}
			}
		}
		fin.close();
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
		ofstream fout;
		fout.open(acaY + "_" + trm + "_" + css + "_" + cId + ".txt");
		fout << content;
		fout.close();
		addStdtoAttendanceList(acaY, trm, cId, css, st);
		addStdtoScoreBoard(acaY, trm, cId, css, st);
		gotoxy(113, 18);
		cout << "I M P O R T  C O M P L E T E D !";
	}
	else return;
}
void addStdtoScoreBoard(string acaYear, string term, string id, string clss, Student st)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + clss + "_" + id + "_ScoreBoard.txt");
	if (!fin.is_open()) return;
	string x;
	getline(fin, x);
	int dem = 0;
	string std;
	while (!fin.eof())
	{
		getline(fin, std);
		if (std != "") dem++;
	}
	fin.close();

	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + clss + "_" + id + "_ScoreBoard.txt", ios::out | ios::app);
	fout << to_string(dem + 1) << "," << st.Id << "," << st.lName << "," << st.fName << "_,_,_,_,_,_,_,_,_,_\n";
	fout.close();
}
void addStdtoAttendanceList(string acaYear, string term, string id, string clss, Student st)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + "_" + clss + "_" + id + "_AttendanceList.txt");
	if (!fin.is_open()) return;
	string x;
	getline(fin, x);
	int dem = 0;
	string std;
	while (!fin.eof())
	{
		getline(fin, std);
		if (std != "") dem++;
	}
	fin.close();

	ofstream fout;
	fout.open(acaYear + "_" + term + "_" + clss + "_" + id + "_AttendanceList.txt", ios::out | ios::app);
	fout << to_string(dem + 1) << "," << st.Id << "," << st.lName << "," << st.fName << "_,_,_,_,_,_,_,_,_,_\n";
	fout.close();
}