#ifndef _DISPLAYCOURSELIST_H_
#define _DISPLAYCOURSELIST_H_
#include<iostream>
#include<fstream>
#include<string>
#include"Course.h"
using namespace std;
void displayCourseList(string acaYear, string term, Course st, int &numofCourse);
void takeCourseName(string acaYear, string term, Course &st, int n);
#endif