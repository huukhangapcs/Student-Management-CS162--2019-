#include"ChangeStudentPass.h"
#include"DesignAffect.h"
void ChangeStudentPassWord(string id, char * cfmPass, char * ePass, char *rePass)
{
	if (isMatchPassStd(id, cfmPass, ePass, rePass))
	{
		savePassToFile(id, ePass);
		gotoxy(110, 20);
		TextColor(11);
		cout << "CHANGED PASSWORD SUCCESSFULLY";
	}
	else
	{
		gotoxy(110, 20);
		TextColor(11);
		cout << "FAILED TO CHANGE PASSWORD ";
		return;
	}
}
bool isMatchPassStd(string id, char* cfmPass, char * ePass, char *rePass)
{
	ifstream fin;
	fin.open("StudentLogin.txt");
	if (!fin.is_open()) return false;
	string cf = cfmPass;
	string curPass;
	string clName, sId;
	while (!fin.eof())
	{
		getline(fin, sId, ',');
		getline(fin, curPass, ',');
		getline(fin, clName);
		if (id == sId && cf == curPass)
		{
			if (strcmp(ePass, rePass) == 0) return true;
		}
	}
	fin.close();
	return false;
}
void savePassToFile(string id, char *ePass)
{
	string pass = ePass;
	ifstream fin;
	ofstream fout;
	string clName, sId;
	fin.open("StudentLogin.txt");
	fout.open("tmp.txt");
	string x;
	while (!fin.eof())
	{
		getline(fin, sId, ',');
		getline(fin, x, ',');
		getline(fin, clName);
		if (sId == "") continue;
		else
		{
			if (id != sId)
			{
				fout << sId << ",";
				fout << x << ",";
				fout << clName << endl;
			}
			else
			{
				fout << sId << ",";
				fout << pass << ",";
				fout << clName << endl;
			}
		}
	}
	fin.close();
	fout.close();
	remove("StudentLogin.txt");
	rename("tmp.txt", "StudentLogin.txt");
}
