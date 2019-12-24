#include"Student.h"

Student* CreateNewStudent(string No, string Id, string lName, string fName, string gender, string YearOB, string MonthoB, string DateOB)
{
	Student *p = new Student;
	if (p != nullptr)
	{
		p->No = No;
		p->Id = Id;
		p->lName = lName;
		p->fName = fName;
		p->gender = gender;
		p->YearOB = YearOB;
		p->MonthoB = MonthoB;
		p->DateOB = DateOB;
		p->pNext = nullptr;
	}
	return p;
}
void CreateList(LinkedList &list)
{
	list.pHead = list.pTail = nullptr;
}
void InsertNewStudent(LinkedList&list, string No, string Id, string lName, string fName, string gender, string YearOB, string MonthoB, string DateOB)
{
	Student *p = CreateNewStudent(No, Id, lName, fName, gender, YearOB, MonthoB, DateOB);
	if (p == nullptr) return;
	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		list.pHead = list.pTail = p;
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
}
bool loadStudentFromFile(string filePath, string &firstLine, LinkedList &list)
{
	ifstream fin;
	fin.open(filePath);
	if (!fin.is_open()) return false;
	string No, Id, lName, fName, gender, YearOB, MonthOB, DateOB;
	getline(fin, firstLine); // loai bo dong dau tien
	while (!fin.eof())
	{
		getline(fin, No, ',');
		if (No == "") break;
		getline(fin, Id, ',');
		getline(fin, lName, ',');
		getline(fin, fName, ',');
		getline(fin, gender, ',');
		getline(fin, YearOB, '-');
		getline(fin, MonthOB, '-');
		getline(fin, DateOB);
		InsertNewStudent(list, No, Id, lName, fName, gender, YearOB, MonthOB, DateOB);
	}
	fin.close();
	return true;

}
void saveStudentToFile(string ClassName, LinkedList list, string firstLine)
{
	ofstream fout1;
	fout1.open(ClassName + ".txt");
	fout1 << firstLine << endl;
	Student *tmp = list.pHead;
	int dem = 0;
	while (tmp != nullptr)
	{
		dem++;
		fout1 << dem << ",";
		fout1 << tmp->Id << ",";
		fout1 << tmp->lName << ",";
		fout1 << tmp->fName << ",";
		fout1 << tmp->gender << ",";
		fout1 << tmp->YearOB << "-";
		fout1 << tmp->MonthoB << "-";
		fout1 << tmp->DateOB << endl;
		tmp = tmp->pNext;
	}
	fout1.close();
	ofstream fout2;
	fout2.open("StudentLogin.txt", ios::out | ios::app);
	Student *tmp2 = list.pHead;
	while (tmp2 != nullptr)
	{
		fout2 << tmp2->Id << ",";
		fout2 << tmp2->YearOB << tmp2->MonthoB << tmp2->DateOB << ",";
		fout2 << ClassName << endl;
		tmp2 = tmp2->pNext;
	}
	fout2.close();
}
void deleteLinkedList(LinkedList &list)
{
	Student *tmp = list.pHead;
	while (tmp != nullptr)
	{
		list.pHead = list.pHead->pNext;
		delete tmp;
		tmp = list.pHead;
	}
}
