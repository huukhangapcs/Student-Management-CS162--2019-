#ifndef _EDITATTENDANCE_H_
#define _EDITATTENDANCE_H_

#include<iostream>
#include<fstream>
#include<string>
#include"Attendance.h"
using namespace std;

void editAttendance(string acaYear, string term, char *Class, char *cId, int curWeek);
void displayAtt(Attendance *at, char *clss, char *cid, int n);
bool loadAttendance(string acaYear, string term, string Class, string cId, Attendance *at, int &n);
void editAttendanceData(string acaYear, string term, char *Class, char *cId, Attendance *&at, int n, int curWeek);
void savetheAttendance(string acaYear, string term, string Class, string cId, Attendance *at, int n);
bool loadAttendance(string acaYear, string term, string Class, string cId, Attendance *at, int &n);

#endif