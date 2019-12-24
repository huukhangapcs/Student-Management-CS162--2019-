#include"Login.h"
#include"Screen.h"

void Intro()
{
	string  b[10];

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
	gotoxy(84, 1);
	TextColor(15);
	cout << "<< G r 0 u P * 6 >> ";
	TextColor(11);
	for (int i = 0; i < 10; ++i)
	{
		gotoxy(45, 5 + i);
		cout << b[i] << endl;
		Sleep(120);
	}
	Sleep(600);
	TextColor(15);
	gotoxy(79, 16);
	cout << " H";
	Sleep(50);
	gotoxy(83, 16);
	cout << "E";
	Sleep(70);
	gotoxy(86, 16);
	cout << "L";
	Sleep(90);
	gotoxy(89, 16);
	cout << "L";
	Sleep(100);
	gotoxy(92, 16);
	cout << "O";
	Sleep(100);
	gotoxy(95, 16);
	cout << "-";
	Sleep(100);
	gotoxy(98, 16);
	cout << "U";
	Sleep(100);
	gotoxy(101, 16);
	cout << "S";
	Sleep(100);
	gotoxy(104, 16);
	cout << "E";
	Sleep(100);
	gotoxy(107, 16);
	cout << "R";
	Sleep(100);
	gotoxy(200, 16);
	cout << "  !";
	Sleep(1000);
	gotoxy(79, 16);
	TextColor(10);
	cout << " H  E  L  L  O  -  U  S  E  R  !";
	TextColor(15);
	gotoxy(52, 18);
	cout << "  <<><<><<>---------------------------------------------------------------<>><>><>>";
	Sleep(100);
	gotoxy(52, 19); cout << "<<><<><<>"; TextColor(3); gotoxy(62, 19); cout << "     WELCOME TO \" P.O.R.T.A.L 6\" -  HCMUS STUDENT MANAGEMENT SYSTEM."; gotoxy(54 + 69, 19); TextColor(15); cout << "     <>><>><>>";
	Sleep(100);
	gotoxy(52, 20); cout << "  <<><<><<>---------------------------------------------------------------<>><>><>>";
	Sleep(1200);
	gotoxy(70, 22);
	TextColor(14);
	cout << " P L E A S E <> D E C L A I R - I D E N T I T Y :";
	Sleep(500);
	gotoxy(77, 25);
	TextColor(12);
	cout << "* * * * * * | | <!> | | * * * * * *";
	TextColor(7);
	Sleep(150);
	gotoxy(79, 27);
	cout << "- A C A D E M I C  S T A F F -";
	Sleep(150);
	gotoxy(86, 29);
	cout << "- T E A C H E R -";
	Sleep(150);
	gotoxy(86, 31);
	cout << "- S T U D E N T -";


}
void MoveLoginMenu(int loginType) {
	TextColor(7);
	gotoxy(79, 27);
	cout << "- A C A D E M I C  S T A F F -";
	TextColor(7);
	gotoxy(86, 29);
	cout << "- T E A C H E R -";
	TextColor(7);
	gotoxy(86, 31);
	cout << "- S T U D E N T -";

	switch (loginType)
	{
	case 1:
		TextColor(6);
		gotoxy(79, 27);
		cout << "< A C A D E M I C  S T A F F >";
		break;
	case 2:
		TextColor(6);
		gotoxy(86, 29);
		cout << "< T E A C H E R >";
		break;
	case 3:
		TextColor(6);
		gotoxy(86, 31);
		cout << "< S T U D E N T >";
		break;

	default:
		break;
	}
}
void Login(string &Usn)
{
	int loginType = 0;

	while (1)//move con chuot
	{
		int n;
		n = _getch();
		if (n == 80)//down
		{
			loginType++;
			if (loginType > 3)
				loginType = 1;
		}
		if (n == 72)//up 
		{
			loginType--;
			if (loginType < 1)
				loginType = 3;
		}
		if (n == 27)//esc
		{
			ExitProcess(0);
		}
		if (n == 13)
		{
			break;
		}
		MoveLoginMenu(loginType);
	}
		if(loginType==1)LoginBox(loginType, Usn);
		if (loginType == 2)LoginBox(loginType, Usn);
		if (loginType == 3)LoginBox(loginType, Usn);

}
