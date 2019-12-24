#include"AddANewCourse.h"
#include"DesignAffect.h"
void AddANewCourse(string acaYear, string term, char* Id, char* Name, char* Class, char* LecAccount, char* stDay, char* enDay, char* day, char* stHour, char* enHour, char* Room)
{
	string year = acaYear;
	string tm = term;
	string id = Id;
	string Nm = Name;
	string Css = Class;
	string LAcc = LecAccount;
	string stD = stDay;
	string enD = enDay;
	string d = day;
	string stH = stHour;
	string enH = enHour;
	string Rm = Room;
	string firstLine;
	string No;

	if (checkIfCourseExisted(year, tm, id, Css))
	{

		gotoxy(112, 45);
		cout << "Failed to read";
		return;
	}
	Linked list;
	CreateList(list);

	InsertNewCourse(list, id, Nm, Css, LAcc, stD, enD, d, stH, enH, Rm);
	saveCourseToFile(year, tm, list, firstLine);
	deleteLinked(list);
	deleteLinked(list);
	gotoxy(112, 45);
	cout << "IMPORT COMPLETED!";
	return;

}