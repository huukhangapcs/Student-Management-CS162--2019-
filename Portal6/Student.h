#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Student
{
	string No;
	string Id;
	string lName;
	string fName;
	string gender;
	string YearOB;
	string MonthoB;
	string DateOB;
	Student *pNext;
};
struct LinkedList
{
	Student *pHead;
	Student *pTail;
};
Student* CreateNewStudent(string No, string Id, string lName, string fName, string gender, string YearOB, string MonthoB, string DateOB);
void CreateList(LinkedList &list);
void InsertNewStudent(LinkedList&list, string No, string Id, string lName, string fName, string gender, string YearOB, string MonthoB, string DateOB);
bool loadStudentFromFile(string filePath, string &firstLine, LinkedList &list);
void saveStudentToFile(string ClassName, LinkedList list, string firstLine);
void deleteLinkedList(LinkedList &list);
#endif

