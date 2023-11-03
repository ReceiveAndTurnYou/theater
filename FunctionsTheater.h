#pragma once
#include <iostream>
#include "Theater.h"
#include <iomanip>
#include <limits>

using namespace std;

void create_theater(Theater& th)
{
	int id;
	char thnm[30];
	char adress[30];
	int tmp;


	cout << "\n\t ***** ������ ��������� *****" << endl;
	cout << "\n\t������� ID ����������: ";
	cin >> id;
	if (id < 0)
	{
		cout << "\n\t������������ ����, ���������� ��� ���" << endl;
		return;
	}

	th.setid(id);

	cout << "\n\t������� �������� ����������: ";
	cin.ignore(32767, '\n');
	cin.getline(thnm, 29);
	
	th.setname(thnm);

	cout << "\n\t������� ����� ����������: ";
	cin.getline(adress, 29);


	th.setadress(adress);




}


void print_theater(Theater th)
{
	cout << "\n\t\t\t\t\t --- ���������� � ���������� ---\n";
	cout << "+===================================================================================================+";
	cout << "\n||ID ����������" << "                 ||�������� ����������   ||" << " ����� ����������" << "||������� �� ����       ||  \n";
	cout << "||==============================||======================||=================||======================||\n";
	cout << "||\t" << setw(10) << th.getid() << "\t\t||" << setw(8) << th.getname() << "\t\t||\t" << setw(10) << th.getadress() << " || " << setw(17) << th.getincome() << "\t   ||" << endl;
	cout << "+===================================================================================================+" << endl;
}