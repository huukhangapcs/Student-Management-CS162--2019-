#include"DisplayStudent.h"
#include"DesignAffect.h"
void displayAStudent(Student st)
{
	
	
	gotoxy(89, 7);
	cout <<  "                         ________________________                         ";
	gotoxy(112-25, 8);

	cout << "                         <<  STUDENT  INFORMATION  >>                         " ;
	gotoxy(101-25, 9);

	cout << "                                      | || ||| |||| ||||| |||                         ";
	
	TextColor(6);
	for (int i = 0; i <= 50; ++i)
	{
		for (int j = 0; j <= 18; j += 3)
		{
			char n = 196;

			gotoxy(100 + i, 10 + j);
			cout << n;
			gotoxy(100 + i, 10 + j + 2);
			cout << n;
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		char n = 218;
		gotoxy(99, 10 + 3 * i);
		cout << n;
	}
	for (int i = 0; i < 7; ++i)
	{
		char n = 192;
		gotoxy(99, 12 + 3 * i);
		cout << n;

	}
	for (int i = 0; i < 7; ++i)
	{
		char n = 191;
		gotoxy(151, 10 + 3 * i);
		cout << n;
	}
	for (int i = 0; i < 7; ++i)
	{
		char n = 217;
		gotoxy(151, 12 + 3 * i);
		cout << n;
	}
	TextColor(11);
	for (int i = 0; i < 7; ++i)
	{
		char n = '|';
		gotoxy(151, 11 + 3 * i);
		cout << n;
	}

	gotoxy(85, 11);
	cout << " S E R I A L :|   " << st.No ;
	gotoxy(93, 14);
	cout << " I D :|   " << st.Id ;
	gotoxy(81, 17);
	cout << "L A S T  n a m e :|   " << st.lName ;
	gotoxy(80, 20);
	cout << "F I R S T n a m e :|   " << st.fName ;
	gotoxy(86, 23);
	cout << "G E N D E R :|   " << st.gender ;
	gotoxy(76,26 );
	cout << "D a t e of  B i r t h :|   " << st.YearOB << "-" << st.MonthoB << "-" << st.DateOB ;

}
void displayAStudent2(Student st)
{
	TextColor(7);

	gotoxy(89, 7);
	cout << "                         ________________________                         ";
	gotoxy(112 - 25, 8);

	cout << "                         <<  STUDENT  INFORMATION  >>                         ";
	gotoxy(101 - 25, 9);

	cout << "                                      | || ||| |||| ||||| |||                         ";

	TextColor(6);
	for (int i = 0; i <= 50; ++i)
	{
		for (int j = 0; j <= 15; j += 3)
		{
			char n = 196;

			gotoxy(100 + i, 10 + j);
			cout << n;
			gotoxy(100 + i, 10 + j + 2);
			cout << n;
		}
	}
	for (int i = 0; i <6; ++i)
	{
		char n = 218;
		gotoxy(99, 10 + 3 * i);
		cout << n;
	}
	for (int i = 0; i < 6; ++i)
	{
		char n = 192;
		gotoxy(99, 12 + 3 * i);
		cout << n;

	}
	for (int i = 0; i < 6; ++i)
	{
		char n = 191;
		gotoxy(151, 10 + 3 * i);
		cout << n;
	}
	for (int i = 0; i < 6; ++i)
	{
		char n = 217;
		gotoxy(151, 12 + 3 * i);
		cout << n;
	}
	TextColor(11);
	for (int i = 0; i < 6; ++i)
	{
		char n = '|';
		gotoxy(151, 11 + 3 * i);
		cout << n;
	}

	gotoxy(85, 11);
	cout << " S E R I A L :|   " << st.No;
	gotoxy(93, 14);
	cout << " I D :|   " << st.Id;
	gotoxy(81, 17);
	cout << "L A S T  n a m e :|   " << st.lName;
	gotoxy(80, 20);
	cout << "F I R S T n a m e :|   " << st.fName;
	gotoxy(86, 23);
	cout << "G E N D E R :|   " << st.gender;
	gotoxy(76, 26);
	cout << "D a t e of  B i r t h :|   " << st.YearOB << "-" << st.MonthoB << "-" << st.DateOB;

}

bool displayStudentList(string className)
{
	ifstream fin;
	Student st;
	fin.open(className + ".txt");
	if (!fin.is_open()) return false;
	string x;
	getline(fin, x);
	gotoxy(56, 7);
	TextColor(6);
	cout << "<\><\><\> S T U D E N T  L I S T |:|"; TextColor(10); gotoxy(90, 7); cout<<className ;
	
	char m;
	TextColor(6);
	for (int i = 0; i <= 128; ++i)
	{
		m = 196;

		gotoxy(58 + i, 8);
		cout << m;
		gotoxy(58 + i, 10);
		cout << m;

	}

	m = 218;
	gotoxy(57, 8);
	cout << m;

	m = 192;
	gotoxy(57, 10);
	cout << m;



	m = 191;
	gotoxy(186, 8);
	cout << m;


	m = 217;
	gotoxy(186, 10);
	cout << m;

	TextColor(11);
	
	{
		char n = '|';
		gotoxy(186, 9);
		cout << n;

	}
	TextColor(6);
	gotoxy(56 + 12, 10);
	 m = 193;
	cout << m;
	gotoxy(56 + 12 + 14, 10);
	cout << m;
	gotoxy(57 + 12+14+25, 10);
	cout << m;
	gotoxy(57 + 12 + 14 + 25+28, 10);
	cout << m;
	gotoxy(57 + 12 + 14 + 25 + 28+21, 10);
	cout << m;
	gotoxy(56 + 12, 8);
	 m = 194;
	cout << m;
	gotoxy(56 + 12 + 14,8);
	cout << m;
	gotoxy(57 + 12 + 14 + 25, 8);
	cout << m;
	gotoxy(57 + 12 + 14 + 25 + 28, 8);
	cout << m;
	gotoxy(57 + 12 + 14 + 25 + 28 + 21, 8);
	cout << m;
	gotoxy(57, 9);
	TextColor(15);
	cout << "|. N O     |. I D        |. L A S T  N A M E       |. F I R S T  N A M E       |. G E N D E R       |. D A T E  O F  B I R T H  " ;
	
	int i = 0;
	while (!fin.eof())
	{
		
		getline(fin, st.No, ',');
		getline(fin, st.Id, ',');
		getline(fin, st.lName, ',');
		getline(fin, st.fName, ',');
		getline(fin, st.gender, ',');
		getline(fin, st.YearOB);
		if (st.No != "")
		{
			TextColor(11);
			gotoxy(57,i+11);
			cout <<"| "<< st.No; 
			gotoxy(67, i + 11);
			cout<< "| | "<< st.Id ;
			gotoxy(81, i + 11);
			cout <<"| |   "<< st.lName; 
			gotoxy(107, i + 11);
			cout<<"| |     "<< st.fName;
			gotoxy(135, i + 11);
			cout <<"| |    "<< st.gender;
			gotoxy(156, i + 11);
			cout<<"| | "<< st.YearOB;
			gotoxy(186, i + 11);
			cout << "|";
			gotoxy(58,i+12);
			TextColor(6);
			cout << "________________________________________________________________________________________________________________________________";
			i+=2;
		}
		
	}
	fin.close();
	return true;
}