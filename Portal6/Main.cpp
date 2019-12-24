



#include"Login.h"
#include"Screen.h"
#include"AddANewCourse.h"
#include"ChangeLecturerPass.h"
#include"InputData.h"
//

int main()
{
	string Usn;
	Intro();
	Login(Usn);
//	MenuDisplay();
	//LecturerMenuDisplay();
	//StudentMenuDisplay(Usn);
	system("pause");
	return 0;
}