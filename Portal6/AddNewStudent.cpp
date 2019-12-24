#include"AddNewStudent.h"
#include"DesignAffect.h"
// Chỉ cần dùng hàm AddNewStudent và truyền tham số , ko cần quan tâm mấy cái khác
void AddNewStudent(char* ClassName, char* nId, char* nLName, char* nFName, char* nGender, char* nYearOB, char* nMonthOB, char* nDateOB)
{
	string ClN = ClassName;  
	string id = nId;
	string LN = nLName;
	string FN = nFName;
	string Gen = nGender; 
	string YOB = nYearOB;
	string MOB = nMonthOB;
	string DOB = nDateOB;
	if (!CheckIsExistedClass(ClN))
	{
		TextColor(12);
		gotoxy(102, 33);
		cout << "-Class is not exist! Please add another Class-";

		
		return;
	}
	if (CheckIsExistedStudent(id))
	{
		TextColor(12);
		gotoxy(97, 33);
		cout << "-Student is alreadry exist! Please add another Student-";
		
	
		return;
	}
	int nNo = CountNumOfStudent(ClN) + 1;
	saveStudent(ClN, nNo, id, LN, FN, Gen, YOB, MOB, DOB);
	gotoxy(102, 34);
	TextColor(12);
	cout << "*** I M P O R T I N G   C O M P L E T E D ! ***";
	
	return;
}
int CountNumOfStudent(string ClassName)
{
	ifstream fin;
	fin.open(ClassName + ".txt");
	string x;
	getline(fin, x); // bo dong dau tien
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, x);
		if (x != "") dem++;
	}
	fin.close();
	return dem;
}
bool CheckIsExistedStudent(string nId)
{
	ifstream fin;
	fin.open("StudentLogin.txt");
	string id, remain;
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		getline(fin, id,',');
		if (id == nId) return true;
		getline(fin, remain);
	}
	fin.close();
	return false;
}
void saveStudent(string ClassName, int nNO, string nId, string nLName, string nFName, string nGender, string nYearOB, string nMonthOB, string nDateOB)
{
	ofstream fout1;
	fout1.open(ClassName + ".txt", ios::out | ios::app);
	fout1 << nNO << ",";
	fout1 << nId << ",";
	fout1 << nLName << ",";
	fout1 << nFName << ",";
	fout1 << nGender << ",";
	fout1 << nYearOB << "-";
	fout1 << nMonthOB << "-";
	fout1 << nDateOB << endl;
	fout1.close();
	ofstream fout2;
	fout2.open("StudentLogin.txt", ios::out | ios::app);
	fout2 << nId << ",";
	fout2 << nYearOB << nMonthOB << nDateOB << ",";
	fout2 << ClassName << endl;
	fout2.close();
}