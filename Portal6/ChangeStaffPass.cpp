#include"ChangeStaffPass.h"
#include"DesignAffect.h"
// chỉ cần dùng hàm ChangeStaffPass, ko cần quan tâm hàm khác
void ChangeStaffPass(char * cfmPass, char * ePass, char *rePass)
{
	char *curPass = new char[100];
	if (isMatchStaffPass(curPass, cfmPass, ePass, rePass))
	{
		string pass = ePass;
		ofstream fout;
		fout.open("StaffPassWord.txt");
		fout << pass;
		fout.close();
		delete[]curPass;
		gotoxy(110,20);
		TextColor(11);
		cout << "CHANGED PASSWORD SUCCESSFULLY";
	}
	else
	{
		gotoxy(110, 20);
		TextColor(11);
		cout << "FAILED TO CHANGE PASSWORD ";
		delete[]curPass;
		return;
	}
}
bool isMatchStaffPass(char *curPass, char * cfmPass, char * ePass, char *rePass)
{
	ifstream fin;
	fin.open("StaffPassWord.txt");
	if (!fin.is_open()) strcpy_s(curPass, 6, "admin");
	fin >> curPass;
	fin.close();
	if (strcmp(curPass, cfmPass) == 0 && strcmp(ePass, rePass) == 0)
	{
		return true;
	}
	return false;
}

