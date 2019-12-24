#ifndef _FINDACOURSE_H_
#define _FINDACOURSE_H_
#include<iostream>
#include<fstream>
#include<string>
#include"Course.h"
using namespace std;
bool FindACourse(string  acaYear, string term, char *Id, char *Class, Course &st);
bool loadCourseInfor(string acaYear, string term, char *Id, char *Class, Course &st);
#endif // !_FINDACOURSE_H_
