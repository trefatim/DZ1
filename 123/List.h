#pragma once
#include "Group.h"
#include <string>
using namespace std;

class List
{
	StudyGroup group;
	List *pNext;
public:
	List();
	List(StudyGroup group);
	void addGroup(List *& pFirst, List *p);
	List* FindGroup(List *pFirst, string gr);
	List* get_pNext();
	void set_Group(StudyGroup gr);
	StudyGroup get_Group();
	void printAll(List *pF);
	void del_Group(List *p, List *&pF);
};