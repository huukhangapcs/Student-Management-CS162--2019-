#ifndef _GOTOXY_H_
#define _GOTOXY_H_
#include<Windows.h>

inline void gotoxy(short x, short y)
{
	COORD co = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);
}
#endif
