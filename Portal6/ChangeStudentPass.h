#ifndef _CHANGESTUDENTPASS_H_
#define _CHANGESTUDENTPASS_H_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void ChangeStudentPassWord(string id, char * cfmPass, char * ePass, char *rePass);
bool isMatchPassStd(string id, char * cfmPass, char * ePass, char *rePass);
void savePassToFile(string id, char *ePass);

#endif