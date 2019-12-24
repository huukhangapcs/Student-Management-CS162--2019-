#include"Screen.h"
#include"InputData.h"
#include"InputPassword.h"
#include"CheckLogin.h"
#include<string>
void LoginBox(int type, string &Usn)
{
	string b[9];
	system("cls");

#pragma region the logo                                                                                
	b[0] = "10101110      101100111010    11010010    0110110110111011     110         100                     1001";
	b[1] = "111    011   10   110   001   101    111        o0|1o        011 101       110                    111";
	b[2] = "001     101  10 011     100   001     101        0|0        111    111     101                  110 ";
	b[3] = "110    011   1110       001   111    010         1|1       0101     001    111                 011";
	b[4] = "1001101      010        110   110  111           1|1      1001101    111   000                101    1010";
	b[5] = "001          110       1101   001   010          1|1      111    11  010   110                110       001";
	b[6] = "100          001     101 00   101    110         1|1      011      01101   010            o   001       100";
	b[7] = "111          111   101   11   011     101        1|0      101        011   111           ooo   111     010";
	b[8] = "010           101110101011    110      011       1|1      111        110   ---01010111    o      101010";
#pragma endregion
	//logodisplay
	TextColor(11);
	for (int i = 0; i < 9; ++i)
	{
		gotoxy(45, 5 + i);
		cout << b[i] << endl;
	}
	gotoxy(84, 1);
	TextColor(15);
	cout << "<< G r 0 u P * 6 >> ";
	gotoxy(78, 17);
	cout << "%%%%%  L . </> . G . I . N  %%%%%";

#pragma region login boxes

	for (int i = 0; i <= 30; ++i)
	{
		char n = 196;
		gotoxy(79 + i, 19);
		cout << n;
		gotoxy(79 + i, 21);
		cout << n;
	}
	char n = 218;
	gotoxy(78, 19);
	cout << n;
	n = 192;
	gotoxy(78, 21);
	cout << n;
	n = 191;
	gotoxy(110, 19);
	cout << n;
	n = 217;
	gotoxy(110, 21);
	cout << n;
	gotoxy(59, 20);
	cout << "U s e r n a m e :  |";
	n = '|';
	gotoxy(110, 20);
	cout << n;
	for (int i = 0; i <= 30; ++i)
	{
		char n = 196;
		gotoxy(79 + i, 22);
		cout << n;
		gotoxy(79 + i, 24);
		cout << n;
	}
	n = 218;
	gotoxy(78, 22);
	cout << n;
	n = 192;
	gotoxy(78, 24);
	cout << n;
	n = 191;
	gotoxy(110, 22);
	cout << n;
	n = 217;
	gotoxy(110, 24);
	cout << n;
	gotoxy(59, 23);
	cout << "P a s s w o r d :  |";
	n = '|';
	gotoxy(110, 23);
	cout << n;
	TextColor(6);
	gotoxy(84, 27);
	cout << "<<  S I G N  I N  >> ";
	for (int i = 0; i <= 19; ++i)
	{
		char n = 220;
		gotoxy(84 + i, 26);
		cout << n;
		n = 223;
		gotoxy(84 + i, 28);
		cout << n;
	}
	n = 221;
	gotoxy(84, 27);
	cout << n;
	n = 222;
	gotoxy(103, 27);
	cout << n;

#pragma endregion
	if (type == 1)
	{
		while (1) {
			char *UserName, *PassWord;
			UserName = new char[100];
			PassWord = new char[100];


			TextColor(11);
			gotoxy(80, 20);//dang nhap username
			inputData(UserName);
			gotoxy(80, 23);//nhap pass
			InputPassword(PassWord);

			if (CheckStaffLogin(UserName, PassWord) == true)

			{
				gotoxy(81, 25);
				cout << "                         ";
				gotoxy(83, 29);
				TextColor(11);
				cout << " LOG IN SUCCESSFULLY  ";
				Sleep(300);

				delete[]UserName;
				delete[]PassWord;
				break;
			}

			else {
				gotoxy(81, 25);
				TextColor(12);
				cout << "Invalid email or password!";
				gotoxy(80, 20);
				cout << "              ";
				gotoxy(80, 23);
				cout << "              ";
				delete[]UserName;
				delete[]PassWord;
			}


		}
		MenuDisplay(Usn);
	}
	else if (type == 2)
	{
		while (1) {
			char *UserName, *PassWord;
			UserName = new char[100];
			PassWord = new char[100];


			TextColor(11);
			gotoxy(80, 20);//dang nhap username
			inputData(UserName);
			Usn = UserName;
			gotoxy(80, 23);//nhap pass
			InputPassword(PassWord);

			if (CheckLecturerLogin(UserName, PassWord) == true)

			{
				gotoxy(81, 25);
				cout << "                         ";
				gotoxy(83, 29);
				TextColor(11);
				cout << " LOG IN SUCCESSFULLY  ";
				Sleep(300);

				delete[]UserName;
				delete[]PassWord;
				break;
			}

			else {
				gotoxy(81, 25);
				TextColor(12);
				cout << "Invalid email or password!";
				gotoxy(80, 20);
				cout << "              ";
				gotoxy(80, 23);
				cout << "              ";
				delete[]UserName;
				delete[]PassWord;
			}


		}
		LecturerMenuDisplay(Usn);
	}
	else if (type == 3)
	{
	while (1) {
			char *UserName, *PassWord;
			UserName = new char[100];
			PassWord = new char[100];


			TextColor(11);
			gotoxy(80, 20);//dang nhap username
			inputData(UserName);
			Usn = UserName;
			gotoxy(80, 23);//nhap pass
			InputPassword(PassWord);

			if (CheckStudentLogin(UserName, PassWord) == true)

			{
				gotoxy(81, 25);
				cout << "                         ";
				gotoxy(83, 29);
				TextColor(11);
				cout << " LOG IN SUCCESSFULLY  ";
				Sleep(300);

				delete[]UserName;
				delete[]PassWord;
				break;
			}

			else {
				gotoxy(81, 25);
				TextColor(12);
				cout << "Invalid email or password!";
				gotoxy(80, 20);
				cout << "              ";
				gotoxy(80, 23);
				cout << "              ";
				delete[]UserName;
				delete[]PassWord;
			}


		}
	StudentMenuDisplay(Usn);
	}
}