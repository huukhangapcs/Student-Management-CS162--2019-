#ifndef _DISPLAYACOURSE_H_
#define _DISPLAYACOURSE_H_

#include<iostream>
#include<fstream>
#include<string>
#include"Course.h"
#include"Student.h"
#include"FindACourse.h"
using namespace std;
void displayCourse(string acaYear,string term, char* id, char* Class, Course st);
bool displayStudentListInCourse(string acaYear, string term,char* id, char* Class);

#endif