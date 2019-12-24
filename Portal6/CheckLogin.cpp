#include"CheckLogin.h"

bool CheckStaffLogin(char *eUserName, char *ePassWord)
{
	char* curPass = new char[100];
	ifstream fin;
	fin.open("StaffPassWord.txt");
	if (!fin.is_open()) strcpy_s(curPass, 6, "admin");
	fin >> curPass;
	fin.close();
	if (strcmp(eUserName, "admin") == 0 && strcmp(ePassWord, curPass) == 0)
	{
		delete[]curPass;
		return true;
	}
	delete[]curPass;
	return false;
}
bool CheckStudentLogin(char *eUserName, char *ePassWord)
{
	char *curPass = new char[100];
	char *userName = new char[100];
	string x; // để đọc phần class name
	ifstream fin;
	fin.open("StudentLogin.txt");
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		fin.getline(userName, 100, ',');
		fin.getline(curPass, 100, ',');
		getline(fin, x);
		if (strcmp(userName, eUserName) == 0 && strcmp(curPass, ePassWord) == 0)
		{
			delete[]curPass;
			delete[]userName;
			return true;
		}
	}
	delete[]curPass;
	delete[]userName;
	return false;
}
bool CheckLecturerLogin(char *eUserName, char *ePassWord)
{
	char *curPass = new char[100];
	char *userName = new char[100];
	ifstream fin;
	fin.open("LecturerLogin.txt");
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		fin.getline(userName, 100, ',');
		fin.getline(curPass, 100);
		if (strcmp(userName, eUserName) == 0 && strcmp(curPass, ePassWord) == 0)
		{
			delete[]curPass;
			delete[]userName;
			return true;
		}
	}
	delete[]curPass;
	delete[]userName;
	return false;
}

