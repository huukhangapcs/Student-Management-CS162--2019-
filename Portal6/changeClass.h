#ifndef _CHANGECLASS_H_
#define _CHANGECLASS_H_

#include<iostream>
#include<fstream>
#include<string>
#include"FindAStudent.h"
#include"InputData.h"
#include"DisplayClass.h"
#include"DisplayStudent.h"
#include"AddNewStudent.h"
#include"ScoreBoard.h"
#include"Attendance.h"
using namespace std;
void ChangeClass(char *id, string acaYear, string term);
void saveLogin(Student st, string classA, string classB);
void saveData(Student &st, string classA, string classB);
void changeCourseList(string year, string term, string cId, string classA, string classB, Student st);
void ChangeStudentInCourse(string acaYear, string term, string ClassA, string ClassB, Student st);
void changeScoreBoard(string year, string term, string cId, string classA, string classB, Student st);
void changeAttendanceList(string year, string term, string cId, string classA, string classB, Student st);

#endif // !_CHANGECLASS_H
