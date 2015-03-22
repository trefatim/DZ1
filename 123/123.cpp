#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <fstream>
#include "Group.h"
#include "Student.h"
#include "List.h"
using namespace std;

int main(int argc, char * argv[])
{
	setlocale(LC_ALL,"rus");
	int a, *points, NumOfSt, index;
	string Grou, Cura, *Subj, Stud, Sub;
	List *pp, *pFirst=NULL;
	StudyGroup b;
	Students *d, *e;
	char c;
	while (1)
	{
		system("cls");
		cout<<"1:�������� ������\n";
		cout<<"2:�������� ��������\n";
		cout<<"3:������\n";
		cout<<"4:������� ������\n";
		cout<<"5:������� ��������\n";
		cout<<"6:��������\n";
		cout<<"7:���������\n";
		cout<<"8:������� ���� �� ���� ���������\n";
		cout<<"9:������� ���� �� ����� ��������\n";
		cout<<"e:�����\n";
		c=_getch();
		switch (c)
		{
		case '1':
			{
				fflush(stdin);
				cout<<"������� �������� ������:"<<endl;
				getline(cin,Grou);
				cout<<"������� ��� ��������:"<<endl;
				getline(cin,Cura);
				cout<<"������� ���-�� ���������:"<<endl;
				cin>>a;
				Subj=new string[a];
				cout<<"������� ������ ���������:"<<endl;
				fflush(stdin);
				for (int i=0; i<a; i++)
				{
					getline(cin,Subj[i]);
				}
				StudyGroup gruppa(a,Grou,Cura,Subj);
				pp=new List(gruppa);
				pp->addGroup(pFirst,pp);
				cout<<"������ ���������";
				break;
			}

		case '2':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{				
					cout<<"������� ������, ���� �������� ��������:";
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout <<"������ �� �������\n";
					}
					else
					{
						b=pp->get_Group();
						a=b.get_NumOfSubj();
						cout<<"������� ��� ��������:";
						fflush(stdin);
						getline(cin,Stud);
						points=new int[a];
						cout<<"������� �����\n";
						for(int i=0; i<a; i++)
						{
							cout<<b.get_Subject(i)<<" ";
							fflush(stdin);
							cin>>points[i];
						}
						Students *st;
						st = new Students(Stud, points,a);
						b+st;
						a=b.get_NumOfStud();
						a+=1;
						b.set_NumOfStud(a);
						pp->set_Group(b);
						cout<<"������� ��������\n";
					}
				}
				system("pause");
				break;
			}

		case '3':
			if(pFirst==NULL)
			{
				cout<<"there's no any group";
			}
			else
			{
				pp=pFirst;
				if (pp!=NULL)
				{
					while (pp!=NULL)
					{
						b=pp->get_Group();
						d=b.get_First();
						cout<<b;
						a=b.get_NumOfSubj();
						d->printStudent(a,d);
						pp=pp->get_pNext();
						cout<<"\n";
					} 
				}
			}
			system("pause");
			break;

		case '4':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if(pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						pFirst->del_Group(pp,pFirst);
						cout<<"������ �������";
					}
				}
				system("pause");
				break;
			}

		case '5':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������, �� ������� ������� ��������: ";\
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						b=pp->get_Group();
						cout<<"������� ��� ��������: ";\
						fflush(stdin);
						getline(cin,Stud);
						d=b.find_Student(Stud);
						if (d==NULL)
						{
							cout<<"������� �� ������";
						}
						else
						{
							e=b.get_First();
							d->del_Student(e,d);
							b.set_First(e);
							a=b.get_NumOfStud();
							a--;
							b.set_NumOfStud(a);
							pp->set_Group(b);
							cout<<"������� ������";
						}
					}
				}
				system("pause");
				break;
			}

		case '6':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������, � ������� ������ ���������: ";\
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						b=pp->get_Group();
						a=b.get_NumOfSubj();
						e=b.get_First();
						e->find_Duty(e,a);
					}
				}
				system("pause");
				break;
			}
	
		case '7':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������, � ������� ������ ����������: ";
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						b=pp->get_Group();
						a=b.get_NumOfSubj();
						e=b.get_First();
						e->find_Excellent(e,a);
					}
				}
				system("pause");
				break;
			}

		case '8':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						b=pp->get_Group();
						a=b.get_NumOfSubj();
						e=b.get_First();
						NumOfSt=b.get_NumOfStud();
						e->srAllSub(e,a,NumOfSt);
					}
				}
				system("pause");
				break;
			}

		case '9':
			{
				if(pFirst==NULL)
				{
					cout<<"there's no any group";
				}
				else
				{
					cout<<"������� ������: ";
					fflush(stdin);
					getline(cin,Grou);
					pp=pFirst->FindGroup(pFirst,Grou);
					if (pp==NULL)
					{
						cout<<"������ �� �������";
					}
					else
					{
						b=pp->get_Group();
						a=b.get_NumOfSubj();
						e=b.get_First();
						cout<<"������� �������: ";
						fflush(stdin);
						getline(cin,Sub);
						index=b.find_Sub(Sub);
						if (index==-1)
						{
							cout<<"������� �� ������";
						}
						else
						{
							NumOfSt=b.get_NumOfStud();
							e->srOneSub(e,NumOfSt,index);
						}
					}
				}
				system("pause");
				break;
			}
			
		case 'e':
			return 0;

		default:
			cout<<"������, ���������� ��� ���\n";
			system("Pause");
		}
	}


	system("pause");
	return 0;
}
