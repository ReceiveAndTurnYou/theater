#include "Theater.h"

Theater::Theater()
{
	strcpy_s(theater_name, "����������");
	strcpy_s(adress, "����������");
	income_theater = 0;
}

Theater::~Theater()
{

}

void Theater::setid(int id)
{
	theater_id = id;
}

int Theater::getid()
{
	return theater_id;
}


void Theater::setname(char* name)
{
	strcpy_s(theater_name, name);
}

char* Theater::getname()
{
	return theater_name;
}

void Theater::setadress(char* adr)
{
	strcpy_s(adress, adr);
}
char* Theater::getadress()
{
	return adress;
}

void Theater::setincome(double inc)
{
	income_theater = inc;
}

double Theater::getincome()
{
	return income_theater;
}

void Theater::print()
{
	cout << "ID ����������: " << theater_id << endl;
	cout << "��� ����������: " << theater_name << endl;
	cout << "����� ����������: " << adress << endl;
	cout << "������� �� ����: " << income_theater << endl;
}

void Theater::change_all_names()
{
	cout << "������� ����� ��� ����������: ";
	cin >> theater_name;
}

void Theater::print_select(int a)
{
	switch (a)
	{
	case 1:
		cout << "ID ����������: " << theater_id << endl;
		break;
	case 2:
		cout << "��� ����������: " << theater_name << endl;
		break;

	case 3:
		cout << "����� ����������: " << adress << endl;
		break; 

	case 4:
		cout << "����� ����������: " << income_theater << endl;
		break;
	default: cout << "�������� ��������" << endl; break;
	}
}
