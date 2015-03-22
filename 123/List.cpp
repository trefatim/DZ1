#include "List.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

List::List()
{
	pNext=NULL;
}

List::List(StudyGroup group)
{
	this->group=group;
	pNext=NULL;
}

void List::addGroup(List *& pFirst, List *p)
{
	p->pNext=pFirst;
	pFirst=p;
}

List* List::get_pNext()
{
	return pNext;
}

List* List::FindGroup(List *pFirst, string gr)
{
	List *p=pFirst;
	string str;
	while (p!=NULL)
	{
		str=p->group.get_GroupName();
		if (gr==str)
		{
			return p;
		}
		p=p->pNext;
	}
	return NULL;
}

StudyGroup List::get_Group()
{
	return group;
}

void List::set_Group(StudyGroup gr)
{
	group=gr;
}

void List::del_Group(List *p, List *&pF)
{
	if (p==pF)
	{
		pF=pF->pNext;
	}
	else
	{
		List *pPred=pF;
		while(pPred->pNext!=p && pPred->pNext)
		{
			pPred=pPred->pNext;
		}
		pPred->pNext=p->pNext;
	}
}