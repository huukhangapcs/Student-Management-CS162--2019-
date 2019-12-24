#ifndef _EDITASTUDENT_H_
#define _EDITASTUDENT_H_
#include<iostream>
#include<fstream>
#include"FindAStudent.h"
#include"DisplayStudent.h"
#include"InputData.h"
#include"CheckvalidDay.h"
using namespace std;
void EditAStudent(char *id, string acaYear, string term);
void changeStudentInfor(char *id, Student &st, string acaYear, string term);
void saveEditedLogin(Student st, Student pre);
void saveEditedData(Student st, string className, string acaYear, string term);
void saveEditedDataToCourse(string acaYear, string term, string className, string content, string cId);
void saveEditedDatatoScoreBoard(string acaYear, string term, string className, string cId, Student st);
void saveEditedDatatoAttendance(string acaYear, string term, string className, string cId, Student st);
#endif
