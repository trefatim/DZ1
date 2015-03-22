#pragma once
#include <string>
using namespace std;

class Students
{
	int *points;
	string FIO;
	Students *pN;
public:
	Students();
	Students(string FIO, int* points, int N);
	string get_StudentName();
	int* get_StudentPoints();
	Students* get_pNext();
	void set_pNext(Students *pNext);
	void printStudent(int n, Students *pF);
	void del_Student(Students *&pF, Students *p);
	void find_Duty(Students *pF, int n);
	void find_Excellent(Students *pF, int n);
	void srAllSub(Students *pF, int nSub, int nStud);
	void srOneSub(Students *pF, int nStud, int ind);
};