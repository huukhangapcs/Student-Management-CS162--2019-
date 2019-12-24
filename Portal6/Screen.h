#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_

#include<iostream>
#include<Windows.h>
#include<string>
#include"Gotoxy.h"
#include"DesignAffect.h"
using namespace std;
void Intro();
void MoveLoginMenu(int loginType);
void ControlClassMenuScreen(string Usn);
void ControlCourseMenuScreen(string Usn);
void ControlScoreboardScreen(string Usn);
void Login(string &Usn);
void MenuDisplay(string Usn);
void LoginBox(int type, string &Usn);
void ViewCourseScreen();
void ViewStudentCourse();
void ViewAttendanceScreen();
void LecturerMenuDisplay(string Usn);
void StudentMenuDisplay(string Usn);
void ControlAttendaceScreen(string Usn);
void ImportScoreBoardScreen();
void ViewScoreBoardScreen();

#endif