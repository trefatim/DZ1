#include "Group.h"
#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

StudyGroup::StudyGroup()
{
	NumOfStud=0;
	NumOfSubj=0;
	Group="";
	Curator="";
	Subjects=NULL;
	pSFirst=NULL;
}

StudyGroup::StudyGroup(int NoSub, string Gr, string Cur, string *Sub)
{
	NumOfSubj=NoSub;
	NumOfStud=0;
	Group=Gr;
	Curator=Cur;
	Subjects= new string[NoSub];
	for (int i=0; i<NoSub; i++)
	{
		Subjects[i]=Sub[i];
	}
	pSFirst=NULL;
}

int StudyGroup::get_NumOfStud()
{
	return NumOfStud;
}

string StudyGroup::get_GroupName()
{
	return Group;
}

Students* StudyGroup::get_First()
{
	return pSFirst;
}

void StudyGroup::set_First(Students *pS)
{
	pSFirst=pS;
}

int StudyGroup::get_NumOfSubj()
{
	return NumOfSubj;
}

void StudyGroup::set_NumOfStud(int n)
{
	NumOfStud=n;
}

Students* StudyGroup::find_Student(string FIO)
{
	Students *p;
	p=pSFirst;
	string str;
	while (p!=NULL)
	{
		str=p->get_StudentName();
		if (FIO==str)
		{
			return p;
		}
		p=p->get_pNext();
	}
	return NULL;
}

string StudyGroup::get_Subject(int n)
{
	return Subjects[n];
}

int StudyGroup::find_Sub(string Sub)
{
	for (int i=0; i<NumOfSubj; i++)
	{
		if (Sub==Subjects[i])
		{
			return i;
		}
	}
	return -1;
}

void StudyGroup::operator +(Students *stud)
{
	Students *pNext;
	pNext=stud->get_pNext();
	pNext=pSFirst;
	stud->set_pNext(pNext);
	pSFirst=stud;
}

ostream& operator <<(ostream &out, const StudyGroup &gr)
{
	cout<<"\nГруппа: "<<gr.Group;
	cout<<"\nКуратор: "<<gr.Curator;
	cout<<"\nКол-во студентов: "<<gr.NumOfStud;
	cout<<"\nКол-во предметов: "<<gr.NumOfSubj;
	cout<<"\nПредметы: ";
	for(int i=0; i<gr.NumOfSubj; i++)
	{
		cout<<gr.Subjects[i]<<" ";
	}
	return out;
}