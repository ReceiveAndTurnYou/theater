#include "Viewer.h"
#include <iomanip>

void Viewer::setid(int id)
{
	theater_id = id;
}
int Viewer::getid()
{
	return theater_id;
}

void Viewer::setIdSession(int id)
{
	session_id = id;;
}

int Viewer::getIdSession()
{
	return session_id;
}


void Viewer::setidviewer(int idv)
{
	id = idv;
}

int Viewer::getidviewer()
{
	return id;
}


void Viewer::setfio(char* f)
{
	strcpy_s(fio, f);
}

char* Viewer::getfio()
{
	return fio;
}

void Viewer::setage(int ag)
{
	age = ag;
}

int Viewer::getage()
{
	return age;
}

void Viewer::setticketid(int idtick)
{
	ticketid = idtick;
}

int Viewer::gettickerid()
{
	return ticketid;
}


void Viewer::print()
{
	cout << "\n|| " << setw(12) << fio << "\t  ||\t" << setw(4) << theater_name << "\t||   " << setw(6) << session_id << "  ||\t" << setw(4) << id << "\t ||\t"
		 << setw(5) << age << "  ||  ";
}

int Viewer::operator+(Viewer* obj)
{
	return (this->getage() + obj->getage());
}


void Viewer::change_all_names()
{
	cout << "Введите новую фамилию зрителя: ";
	cin >> fio;
}

void Viewer::print_select(int a)
{
	switch (a)
	{
	case 1:
		cout << "ID зрителя: " << id << endl;
		break;

	case 2:
		cout << "Фамилия зрителя: " << fio << endl;
		break;

	case 3:
		cout << "Возраст зрителя: " << age << endl;
		break;

	default: cout << "Неверное значение" << endl; break;
	}
}