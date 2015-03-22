#pragma once
#include "Student.h"
#include <string>
#include <conio.h>
using namespace std;

class StudyGroup
{
	int NumOfStud, NumOfSubj;
	string Group, Curator, *Subjects;
	Students *pSFirst;
public:
	StudyGroup();
	StudyGroup(int NoSub, string Gr, string Cur, string *Sub);
	int get_NumOfStud();
	string get_GroupName();
	int get_NumOfSubj();
	Students* get_First();
	string get_Subject(int n);
	void set_First(Students *pS);
	void set_NumOfStud(int n);
	Students* find_Student(string FIO);
	int find_Sub(string Sub);
	void operator +(Students *stud);
	friend ostream& operator <<(ostream &out, const StudyGroup &gr);
};