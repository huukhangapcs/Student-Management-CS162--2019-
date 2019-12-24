#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Score
{
	string stdLName;
	string stdFName;
	string stdId;
	float Midterm;
	float Lab;
	float Bonus;
	float Final;
	float ave;
};
void importScore(string acaY, string term, char *Class, char *courseId, char *filePath);
void changeScorebyImport(string year, string term, string Class, string stdid, string crsId, string midterm, string lab, string bonus, string Final);

void displayScoreOfACourse(char* acaY, char* term, char *courseId, char  *Class);
void displayScoreOfAStudent(string  acaY, string term, char *courseId, string Class, string stdId);
void exportScoreToCSV(string acaY, string term, char *courseId, char  *Class);
#endif