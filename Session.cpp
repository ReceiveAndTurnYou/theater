#include "Session.h"


void Session::setIdSession(int id)
{
	idSession = id;
}

int Session::getIdSession()
{
	return idSession;
}


void Session::setMovieName(char* mvnm)
{
	strcpy_s(movie_name, mvnm);
}

char* Session::getMovieName()
{
	return movie_name;
}

void Session::settickets(int tick)
{
	tickets = tick;
}

int Session::gettickets()
{
	return tickets;
}

void Session::settime_h(double t)
{
	time_h = t;
}

void Session::settime_m(double t)
{
	time_m = t;
}

double Session::gettime_h()
{
	return time_h;
}

double Session::gettime_m()
{
	return time_m;
}

void Session::sepriceticket(double pt)
{
	price_ticket = pt;
}

double Session::getpriceticket()
{
	return price_ticket;
}


void Session::print()
{
	cout << "\n\t\t\t\t\t --- Информация о сеансе ---\n";
	cout << "+=================================================================================================================+";
	cout << "\n||ID сеанса" << "             ||Цена билета           ||" << " Название фильма  " << " ||Количество билетов  ||" << "Время сеанса   \t||\n";
	cout << "||======================||======================||===================||====================||===================||\n";
	cout << "||" << setw(10) << getIdSession() << "\t\t||" << setw(12) << getpriceticket() << "$" << "\t\t||\t" << setw(12) << getMovieName() << " || " << setw(5) << gettickets() << "\t\t   ||" << setw(8) << gettime_h() << ":" << gettime_m() << "\t||" << endl;
	cout << "+=================================================================================================================+" << endl;
}

void Session::print_select(int a)
{
	switch (a)
	{
	case 1:
		cout << "ID Сеанса: " << idSession << endl;
		break;

	case 2:
		cout << "Цена билета: " << price_ticket << endl;
		break;

	case 3:
		cout << "Название фильма: " << movie_name << endl;
		break;

	case 4:
		cout << "Количество билетов: " << tickets << endl;
		break;

	case 5:
		cout << "Время сеанса: " << time_h << ":" << time_m << endl;
		break;
	default: cout << "Неверное значение" << endl; break;
	}
}

void Session::change_all_names()
{
	cout << "Введите новое название фильма: ";
	cin >> movie_name;
}