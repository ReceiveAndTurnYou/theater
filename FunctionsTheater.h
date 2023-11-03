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


	cout << "\n\t ***** Создаём кинотеатр *****" << endl;
	cout << "\n\tВведите ID кинотеатра: ";
	cin >> id;
	if (id < 0)
	{
		cout << "\n\tНекорректный ввод, попробуйте ещё раз" << endl;
		return;
	}

	th.setid(id);

	cout << "\n\tВведите название кинотеатра: ";
	cin.ignore(32767, '\n');
	cin.getline(thnm, 29);
	
	th.setname(thnm);

	cout << "\n\tВведите адрес кинотеатра: ";
	cin.getline(adress, 29);


	th.setadress(adress);




}


void print_theater(Theater th)
{
	cout << "\n\t\t\t\t\t --- Информация о кинотеатре ---\n";
	cout << "+===================================================================================================+";
	cout << "\n||ID Кинотеатра" << "                 ||Название кинотеатра   ||" << " Адрес кинотеатра" << "||Выручка за день       ||  \n";
	cout << "||==============================||======================||=================||======================||\n";
	cout << "||\t" << setw(10) << th.getid() << "\t\t||" << setw(8) << th.getname() << "\t\t||\t" << setw(10) << th.getadress() << " || " << setw(17) << th.getincome() << "\t   ||" << endl;
	cout << "+===================================================================================================+" << endl;
}