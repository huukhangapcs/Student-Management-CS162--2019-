#ifndef _LOGIN_H_
#define _LOGIN_H_

#include<iostream>
#include<Windows.h>
#include<string>
#include"Gotoxy.h"
#include"DesignAffect.h"
#include"InputData.h"
#include"InputPassword.h"
#include"CheckLogin.h"
using namespace std;
void Intro();
void MainMenuAffect(int loginType);
void Login(string &Usn);
#endif 
