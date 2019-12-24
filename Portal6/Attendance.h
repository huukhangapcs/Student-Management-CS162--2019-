#ifndef _ATTENDANCE_H_
#define _ATTENDANCE_H_
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Attendance
{
	string stdLName;
	string stdFName;
	string stdId;
	int check[10];
};
void displayAttendanceOfACourse(char* acaY, char* term, char *courseId, char  *Class);
void displayAttendanceOfAStudent(string  acaY, string  term, char *courseId, string Class, string stdId);
void exportAttendanceListToCSV(string acaY, string term, char *courseId, char  *Class);
#endif