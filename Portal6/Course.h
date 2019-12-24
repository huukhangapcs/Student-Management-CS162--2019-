#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Course
{
	string Id;
	string Name;
	string Class;
	string LecAccount;
	string stDay;
	string enDay;
	string day;
	string stHour;
	string enHour;
	string Room;
	Course* pNext;
};
struct Linked
{
	Course *pHead;
	Course *pTail;
};
//
void CreateList(Linked &list);
//
Course* CreateNewCourse(string Id, string Name, string Class, string LecAccount, string stDay, string enDay, string day, string stHour, string enHour, string Room);
//
int countNumOfExistedCourse(string acaYear, string term);
//
bool checkIfCourseExisted(string acaYear, string term, string CourseId, string ClassName);
//
bool checkIfLecAccountExisted(string LecAccount);
//
void InsertNewCourse(Linked &list, string Id, string Name, string Class, string LecAccount, string stDay, string enDay, string day, string stHour, string enHour, string Room);
//
bool loadCourseFromFile(string filePath, string &firstLine, Linked &list);
//
void loadStudentToCourse(Course *p, string acaYear, string term);
//
void saveCourseToFile(string acaYear, string term, Linked list, string firstLine);
//
bool checkIfAcaYearIsExisted(string acaYear);
bool checkIfTermIsExisted(string acaYear, string term);
void CreateAcaYear(string acaYear, string term);
//
void CreateAttendanceList(Course *p, string acaYear, string term);
//
void CreateScoreBoard(Course *p, string acaYear, string term);
//
void deleteLinked(Linked &list);

#endif // !_COURSE_H_
