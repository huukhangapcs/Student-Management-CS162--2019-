#include"InputPassword.h"
void InputPassword(char *p)
{
	int i = 0;
	char a;//a Temp char
	while (1)//infinite loop
	{
		a = _getch();//stores char typed in a
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z') || (a >= '0'&&a <= '9'))
			//check if a is numeric or alphabet
		{
			p[i] = a;//stores a in pass
			++i;
			cout << "*";
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
			//i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
		}
		if (a == 13)//if enter is pressed
		{
			p[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}
}