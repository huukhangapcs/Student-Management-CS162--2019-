#ifndef _ADDNEWCLASS_H_
#define _ADDNEWCLASS_H_
#include<iostream>
#include<fstream>
#include<string>
#include"InputData.h"
#include"Student.h"
using namespace std;
 
void AddNewClass(char *filePath, char *ClassName);
bool CheckIsExistedClass(string ClassName);
void saveClassNametoFile(string ClassName);
#endif
