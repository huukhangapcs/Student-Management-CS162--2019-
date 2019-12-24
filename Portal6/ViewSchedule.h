#pragma once
#ifndef _VIEWSCHEDULE_H_
#define _VIEWSCHEDULE_H_
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct schedule
{
	string date;
	string sth;
	string enh;
	string room;
};
void viewSchedule(string acaYear, string term, string Class);
void findDate(string year, string term, string clss, string day,int& i);
#endif