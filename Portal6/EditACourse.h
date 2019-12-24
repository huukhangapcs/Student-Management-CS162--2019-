#ifndef _EDITACOURSE_H_
#define _EDITACOURSE_H_
#include<iostream>
#include<fstream>
#include<string>
#include"InputData.h"
#include"Course.h"
#include"FindACourse.h"
#include"DisplayACourse.h"
#include"CheckvalidDay.h"
using namespace std;

void EditACourse(string acaYear, string term, char *id, char *Class);
void changeCourseInfor(string acaYear, string term, char *id, char *Class, Course &st);
void saveEditedLecLogin(Course st, Course pre);
void saveEditedLecData(string acaYear, string term, Course st, Course pre);
#endif