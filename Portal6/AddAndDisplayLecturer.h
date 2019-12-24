#ifndef _ADDANDDISPLAYLECTURER_H_
#define _ADDANDDISPLAYLECTURER_H_

#include<iostream>
#include<fstream>
#include<string>
#include"Course.h"
using namespace std;

void AddNewLecturer(char *lecAccount, string acaYear, string term);
void GetCourseName(string acaYear, string term, string LecAccount, string &data);
void DisplayLecturerList(string acaYear, string term);
void DisplayALecturer(char *lecAccount, string acaYear, string term);
#endif