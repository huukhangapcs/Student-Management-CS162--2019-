#include"ChangeLecturerPass.h"
#include"DesignAffect.h"
void ChangeLecturerPassWord(string  userName, char * cfmPass, char * ePass, char *rePass)
{
	if (isMatchLecturerPass(userName, cfmPass, ePass, rePass))
	{
		saveLecturerPassToFile(userName, ePass);
		gotoxy(110, 20);
		TextColor(11);
		cout << "CHANGED PASSWORD SUCCESSFULLY";
	}
	else { 
		gotoxy(110, 20);
		TextColor(11);
		cout << "FAILED TO CHANGE PASSWORD ";
		return; }
}
bool isMatchLecturerPass(string userName, char * cfmPass, char * ePass, char *rePass)
{
	ifstream fin;
	fin.open("LecturerLogin.txt");
	if (!fin.is_open()) return false;
	string usn, pass;
	string cfP = cfmPass;
	while (!fin.eof())
	{
		getline(fin, usn, ',');
		getline(fin, pass);
		if (usn == userName && cfP == pass)
		{
			if (strcmp(ePass, rePass) == 0) return true;
		}
	}
	fin.close();
	return false;
}
void saveLecturerPassToFile(string userName, char *ePass)
{
	ifstream fin;

	string eP = ePass;
	string usn, pass;
	string content = "";
	fin.open("LecturerLogin.txt");

	while (!fin.eof())
	{
		getline(fin, usn, ',');
		getline(fin, pass);
		if (usn != "") 
		{
			if (usn != userName)
			{
				content += usn + ",";
				content += pass + "\n";
			}
			else
			{
				content += usn + ",";
				content += eP + "\n";
			}
		}
	}
	fin.close();
	ofstream fout;
	fout.open("LecturerLogin.txt");
	fout << content;
	fout.close();
}