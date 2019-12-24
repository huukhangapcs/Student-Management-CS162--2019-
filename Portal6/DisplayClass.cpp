#include"DisplayClass.h"
#include"DesignAffect.h"
void displayClassList(int &numofClass)
{
	ifstream fin;
	fin.open("ClassList.txt");
	string className;

	if (!fin.is_open())
	{
		TextColor(12);
		for (int i = 0; i <= 23; ++i)
		{
			char n = 220;
			gotoxy(110 + i, 35);
			cout << n;
			n = 223;
			gotoxy(110 + i, 37);
			cout << n;
		}
		char n = 221;
		gotoxy(109, 35);
		cout << n;
		n = 222;
		gotoxy(132, 37);
		cout << n;
		gotoxy(109, 35);
		TextColor(7);
		cout << "<< N o  C l a s s . >>";
		fin.close();
	}
	else
	{
		while (!fin.eof())
		{
			TextColor(9);
			for (int i = 0; i <= 25; ++i)
			{
				char n = 220;
				gotoxy(113 + i, 31);
				cout << n;
				n = 223;
				gotoxy(113 + i, 33);
				cout << n;
			}
			char n = 221;
			gotoxy(113, 32);
			cout << n;
			n = 222;
			gotoxy(138, 32);
			cout << n;
			gotoxy(114,32);
			TextColor(11);
			cout << "<< C L A S S  L I S T >>";
			getline(fin, className);
			if (className != "")
			{
				TextColor(9);
				numofClass++;
				gotoxy(90, 32 + 2*numofClass);
				cout << "                              ___________________ ";
				gotoxy(106, 33 + 2*numofClass);
				TextColor(6);
				cout << "  <<>>   " << numofClass << " <|| " << className ;
				

			}
		}
		fin.close();
	}
}
void displayClassList2(int &numofClass)
{
	ifstream fin;
	fin.open("ClassList.txt");
	string className;

	if (!fin.is_open())
	{
		TextColor(12);
		for (int i = 0; i <= 23; ++i)
		{
			char n = 220;
			gotoxy(110 + i, 35);
			cout << n;
			n = 223;
			gotoxy(110 + i, 37);
			cout << n;
		}
		char n = 221;
		gotoxy(109, 35);
		cout << n;
		n = 222;
		gotoxy(132, 37);
		cout << n;
		gotoxy(109, 35);
		TextColor(7);
		cout << "<< N o  C l a s s . >>";
		fin.close();
	}
	else
	{
		
		char m;
		TextColor(6);
		for (int i = 0; i <= 44; ++i)
		{
			m = 196;

			gotoxy(90+16 + i, 8);
			cout << m;
			gotoxy(90 + 16+i, 10);
			cout << m;

		}

		m = 218;
		gotoxy(89+16, 8);
		cout << m;

		m = 192;
		gotoxy(89+16, 10);
		cout << m;



		m = 191;
		gotoxy(89+46 + 16, 8);
		cout << m;


		m = 217;
		gotoxy(89+46 + 16, 10);
		cout << m;	

		
		TextColor(6);
		gotoxy(101 + 16, 10);
		m = 193;
		cout << m;
		
		gotoxy(101 + 16, 8);
		m = 194;
		cout << m;
			
		gotoxy(89+16, 9);
		TextColor(15);
		cout << "|. N O     .|.  N A M E  O F  C L A S S       |";
		while (!fin.eof())
		{
			TextColor(9);
			for (int i = 0; i <= 25; ++i)
			{
				char n = 220;
				gotoxy(113+3 + i, 5);
				cout << n;
				n = 223;
				gotoxy(113+3+ i, 7);
				cout << n;
			}
			char n = 221;
			gotoxy(113+3, 6);
			cout << n;
			n = 222;
			gotoxy(138+3, 6);
			cout << n;
			gotoxy(114+3, 6);
			TextColor(11);
			cout << "<< C L A S S  L I S T >>";
			getline(fin, className);
			if (className != "")
			{
				TextColor(6);
				numofClass++;
				gotoxy(89+16, 10 + 2 * numofClass);
				cout << "_______________________________________________ ";
				gotoxy(90+16, 9 + 2 * numofClass);
				TextColor(11);
				cout << "<>  " << numofClass;
				gotoxy(116,9+2*numofClass);
				cout<< "|.|  " << className;
				gotoxy(135+16,9 + 2 * numofClass);
				cout << "|";


			}
		}
		fin.close();
	}
}
void takeClassName(string &classB, int n)
{
	ifstream fin;
	fin.open("ClassList.txt");
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, classB);
		if (classB != "")
		{
			dem++;
			if (dem == n) break;
		}
	}
	fin.close();
}