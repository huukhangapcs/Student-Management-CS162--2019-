#ifndef _ADDNEWSTUDENT_H_
#define _ADDNEWSTUDENT_H_

#include<iostream>
#include<string>
#include<fstream>
#include"AddNewClass.h"
using namespace std;
void AddNewStudent(char* ClassName, char* nId, char* nLName, char* nFName, char* nGender, char* nYearOB, char* nMonthOB, char* nDateOB);
bool CheckIsExistedStudent(string nId);
int CountNumOfStudent(string ClassName);
void saveStudent(string ClassName, int nNO, string nId, string nLName, string nFName, string nGender, string nYearOB, string nMonthOB, string nDateOB);
#endif

