#ifndef _CHECKLOGIN_H_
#define _CHECKLOGIN_H_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool CheckStaffLogin(char *eUserName, char *ePassWord); // kiem tra co phai staff
bool CheckStudentLogin(char *eUserName, char *ePassWord); // kiem tra co phai student
bool CheckLecturerLogin(char *eUserName, char *ePassWord); // kiem tra co phai lecturer

#endif // !_CHECKLOGIN_H_

