#ifndef _CHANGESTAFFPASS_H_
#define _CHANGESTAFFPASS_H_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void ChangeStaffPass(char * cfmPass, char * ePass, char *rePass);
bool isMatchStaffPass(char *curPass, char * cfmPass, char * ePass, char *rePass);


#endif
