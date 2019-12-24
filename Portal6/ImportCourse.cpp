#include"ImportCourse.h"
#include"DesignAffect.h"
void ImportCourse(char *filePath, string term, string acaYear) // ham do hoa cho man hinh add new class
{
	string fP = filePath;
	string Tm = term;
	string year = acaYear;
	string firstLine; // dung de doc dong dau tien trong file
	Linked list;
	CreateList(list);
	if (!loadCourseFromFile(fP, firstLine, list))
	{
		gotoxy(112,28);
		cout << "Failed to read";
		return;
	}
	saveCourseToFile(year, Tm, list, firstLine);
	deleteLinked(list);
	gotoxy(112, 28);
	cout << "IMPORT COMPLETED!";
	return;
}

