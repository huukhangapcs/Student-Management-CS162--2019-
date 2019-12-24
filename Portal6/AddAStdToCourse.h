#ifndef _ADDASTDTOCOURSE_H_
#define _ADDASTDTOCOURSE_H_

#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
#include"FindAStudent.h"
using namespace std;

void AddAStdToCourse(char *stdId, string acaYear, string term, char *courseId, char *Class);
void addStdtoAttendanceList(string acaYear, string term, string id, string clss, Student st);
void addStdtoScoreBoard(string acaYear, string term, string id, string clss, Student st);

#endif