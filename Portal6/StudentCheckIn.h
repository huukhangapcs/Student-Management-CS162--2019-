#ifndef _STUDENTCHECKIN_H_
#define _STUDENTCHECKIN_H_
#include<iostream>
#include<string>
#include<fstream>
#include"Attendance.h"
#include"GetcurrentTime.h"
using namespace std;
struct Schedule
{
	string CourseId;
	string dayofW;
	string stHour;
	string enHour;
};
void studentCheckin(string id, string className, int curWeek);
bool loadCheckinList(string acaYear, string term, string className, Schedule *&sc, int &dem);
bool loadAttendance(string acaYear, string term, string className, Attendance &at, string stdid, string cId);
void saveCheckin(string year, string term, string className, string cId, Attendance at);
#endif // !_STUDENTCHECKIN_H_
