#ifndef _GETCURRENTTIME_H_
#define _GETCURRENTTIME_H_

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>

#include<string>
#include<cmath>
#include <ctime>
using namespace std;

void getAcayearvsTerm(string &acaYear, string &term);
void getWeekDay(string &dayofweek);
void getDayMonthYear(string &day, string &month, string &year);
void getCurrentWeek(int &curWeek);
void updateCurrentWeek(int &curWeek);
#endif
