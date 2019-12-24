#ifndef _TERM_H_
#define _TERM_H_
#include<iostream>
#include<fstream>
#include"AcademicYear.h"
#include"Course.h"
using namespace std;

void addNewTerm(string acaYear, char *term);
void displayTerm(string acaYear);
void deleteTerm(string acaYear, int n);
void removeTermData(string acaYear, string term);
#endif