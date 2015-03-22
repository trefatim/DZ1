#include "Student.h"
#include <iostream>
using namespace std;

Students::Students()
{
	points=NULL;
	FIO="";
	pN=NULL;
}

Students::Students(string FIO, int* points, int N)
{
	this->FIO=FIO;
	this->points = new int[N];
	for(int i=0; i<N; i++)
	{
		this->points[i]=points[i];
	}
	pN=NULL;
}

string Students::get_StudentName()
{
	return FIO;
}

int* Students::get_StudentPoints()
{
	return points;
}

Students* Students::get_pNext()
{
	return pN;
}

void Students::set_pNext(Students *pNext)
{
	pN=pNext;
}

void Students::printStudent(int n, Students *pF)
{
	Students *p;
	p=pF;
	if (p!=NULL)
	{
		while (p!=NULL)
		{
			cout<<"\nСтудент: "<<p->FIO;
			cout<<"\nБаллы: ";
			for(int i=0; i<n; i++)
			{
				cout<<p->points[i]<<" ";
			}
			p=p->pN;
		} 
	}
}

void Students::del_Student(Students *&pF, Students *p)
{
	if (p==pF)
	{
		pF=pF->pN;
	}
	else
	{
		Students *pPred=pF;
		while(pPred->pN!=p && pPred->pN)
		{
			pPred=pPred->pN;
		}
		pPred->pN=p->pN;
	}
}

void Students::find_Duty(Students *pF, int n)
{
	int k,k1=0;
	Students *p;
	p=pF;
	while (p!=NULL)
	{
		k=0;
		for (int i=0; i<n; i++)
		{
			if (p->points[i]<60)
			{
				k=1;
				k1++;
			}
		}
		if (k==1)
		{
			cout<<p->FIO<<"\n";
		}
		p=p->get_pNext();
	}
	if(k1==0)
	{
		cout<<"Должников нет";
	}
}

void Students::find_Excellent(Students *pF, int n)
{
	int k,k1=0;
	Students *p;
	p=pF;
	while (p!=NULL)
	{
		k=0;
		for (int i=0; i<n; i++)
		{
			if (p->points[i]>=85)
			{
				k++;
			}
		}
		if (k==n)
		{
			cout<<p->FIO<<"\n";
			k1++;
		}
		p=p->get_pNext();
	}
	if(k1==0)
	{
		cout<<"Отличников нет";
	}
}

void Students::srAllSub(Students *pF, int nSub, int nStud)
{
	if(nStud==0)
	{
		cout<<"В группе нет студентов";
	}
	else
	{
		int k=0;
		float sr=0;
		Students *p;
		p=pF;
		while (p!=NULL)
		{
			k=0;
			for (int i=0; i<nSub; i++)
			{
				k+=p->points[i];
			}
			sr=sr+(k/nSub);
			p=p->get_pNext();
		}
		sr/=nStud;
		cout<<sr;
	}
}

void Students::srOneSub(Students *pF, int nStud, int ind)
{
	if(nStud==0)
	{
		cout<<"В группе нет студентов";
	}
	else
	{
		float sr=0;
		Students *p;
		p=pF;
		while (p!=NULL)
		{
			sr+=p->points[ind];
			p=p->get_pNext();
		}
		sr/=nStud;
		cout<<sr;
	}
}