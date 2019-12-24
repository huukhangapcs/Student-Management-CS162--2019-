#include"Term.h"

void addNewTerm(string acaYear, char *term)
{
	string t = term;
	if (!checkIfTermIsExisted(acaYear, t))
	{
		ofstream fout;
		fout.open(acaYear + ".txt", ios::out | ios::app);
		fout << term << endl;
		fout.close();
	}
}
void displayTerm(string acaYear)
{
	system("cls");
	cout << acaYear << ":" << endl;
	ifstream fin;
	string term;
	int dem = 0;
	fin.open(acaYear + ".txt");
	if (!fin.is_open()) cout << "THERE IS NO TERM NOW.";
	while (!fin.eof())
	{
		getline(fin, term);
		if (term != "")
		{
			dem++;
			cout << dem << " . " << term << endl;
		}
	}
	if (dem == 0) cout << "THERE IS NO TERM NOW.";
	fin.close();
}

void deleteTerm(string acaYear, int n)
{
	ifstream fin;
	fin.open(acaYear + ".txt");
	string term;
	string content = "";
	string curTerm;
	int dem = 0;
	while (!fin.eof())
	{
		getline(fin, term);
		if (term != "")
		{
			dem++;
			if (dem != n)
			{
				content += term;
				content += "\n";
			}
			else curTerm = term;
		}
	}
	fin.close();
	ofstream fout;
	fout.open(acaYear + ".txt", ios::out | ios::trunc);
	fout << content;
	fout.close();
	removeTermData(acaYear, curTerm);
	remove((acaYear + "_" + term + ".txt").c_str());
	remove((acaYear + "_" + term + "_LecturerList.txt").c_str());
	// Not completed.
}
void removeTermData(string acaYear, string term)
{
	ifstream fin;
	fin.open(acaYear + "_" + term + ".txt");
	if (!fin.is_open()) return;
	string x;
	getline(fin, x); // first line
	string no, id, name, clss, remain;
	while (!fin.eof())
	{
		getline(fin, no, ',');
		getline(fin, id, ',');
		getline(fin, name, ',');
		getline(fin, clss, ',');
		getline(fin, remain);
		if (no != "")
		{
			remove((acaYear + "_" + term + "_" + clss + "_" + id + ".txt").c_str());
			remove((acaYear + "_" + term + "_" + clss + "_" + id + "_AttendanceList.txt").c_str());
			remove((acaYear + "_" + term + "_" + clss + "_" + id + "_ScoreBoard.txt").c_str());
		}
	}
}