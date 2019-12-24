#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void ChangeLecturerPassWord(string userName, char * cfmPass, char * ePass, char *rePass);
bool isMatchLecturerPass(string userName, char * cfmPass, char * ePass, char *rePass);
void saveLecturerPassToFile(string userName, char *ePass);