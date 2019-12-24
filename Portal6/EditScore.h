#pragma once
#ifndef _EDITSCORE_H_
#define _EDITSCORE_H_
#include<iostream>
#include<fstream>
#include<string>
#include"ScoreBoard.h"
using namespace std;
bool findScore(string acaYear, string term, string Class, string courseId, string stdId, Score&sc);
void displayStd(Score sc);
void editScore(string acaY, string term, char *Class, char *courseId, char *stdId);
void editScoreData(string acaY, string term, char *Class, char *courseId, char *stdId, Score&sc);
void saveScore(string year, string term, string css, string cId, Score sc);
#endif // !_EDITSCORE_H
