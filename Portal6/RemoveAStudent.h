#ifndef _REMOVEASTUDENT_H_
#define _REMOVEASTUDENT_H_
#include<iostream>
#include<fstream>
#include"FindAStudent.h"
#include<conio.h>
using namespace std;

void RemoveAStudent(char*id, string year, string term);
void RemoveInfor(Student st, string className, string acaY, string t);
void RemoveLogin(Student st, string& className);
void RemoveCourseData(string acaYear, string term, string className, string content, string cId);
void RemoveScoreBoardData(string acaYear, string term, string className, string cId, Student st);
void RemoveAttendanceData(string acaYear, string term, string className, string cId, Student st);
#endif // !_REMOVEASTUDENT_H_

