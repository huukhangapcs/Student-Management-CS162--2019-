#pragma once
#include<iostream>
#include<fstream>
#include"Student.h"
using namespace std;


bool FindAStudent(char *Id, Student &st, string &ClassName);
bool findStudentClassName(char *Id, string &ClassName);
bool loadStudentInfor(string ClassName, char *id, Student &st);
