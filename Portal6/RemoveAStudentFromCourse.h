#ifndef _REMOVEASTUDENTFROMCOURSE_H_
#define _REMOVEASTUDENTFROMCOURSE_H_

#include<iostream>
#include<fstream>
#include<string>
#include"Student.h"
using namespace std;
void RemoveStdFromCourse(char *stdId, string acaYear,string term, char *courseId, char *Class);
void RemoveAStdFromAttendanceList(string acaY, string term, string cId, string clss, string sid);
void RemoveAStdFromScoreBoard(string acaY, string term, string cId, string clss, string sid);
#endif