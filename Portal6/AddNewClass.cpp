#include"AddNewClass.h"
#include"DesignAffect.h"
//Chỉ cần gọi hàm AddNewClass truyền vào filepath vs ClassName, ko cần quan tâm nhiều.


void AddNewClass(char *filePath, char *ClassName) // ham do hoa cho man hinh add new class
{
	string fp = filePath;
	string cln = ClassName;
	if (CheckIsExistedClass(cln))
	{
		TextColor(12);
		gotoxy(95, 25);
		cout << "-Class is alreadry exist! Please add another Class-";
		
		return;
	}
	string firstLine; // dung de doc dong dau tien trong file
	LinkedList list;
	CreateList(list);
	if (!loadStudentFromFile(fp, firstLine, list))
	{
		gotoxy(110, 26);
		TextColor(12);
		cout << "-Failed to read file-";
		
		return;
	}
	saveStudentToFile(cln, list, firstLine);
	saveClassNametoFile(cln);
	deleteLinkedList(list);
	gotoxy(97, 26);
	TextColor(12);
	cout << "*** I M P O R T I N G   C O M P L E T E D ! ***";
	
	return;
}
bool CheckIsExistedClass(string ClassName)
{
	ifstream fin;
	fin.open("ClassList.txt");
	string x;
	if (!fin.is_open()) return false;
	while (!fin.eof())
	{
		getline(fin, x);
		if (x == ClassName) return true;
	}
	fin.close();
	return false;
}
void saveClassNametoFile(string ClassName)
{
	ofstream fout;
	fout.open("ClassList.txt", ios::out | ios::app);
	fout << ClassName << endl;
	fout.close();
}