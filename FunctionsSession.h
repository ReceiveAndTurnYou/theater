#pragma once
#include <iostream>
#include <conio.h>
#include "Session.h"
#include "Viewer.h"
#include <iomanip>
#include <cmath>

using namespace std;

void create_session(Session* sess[], int sizesession, int* currentsize_session)
{
	if (*currentsize_session == sizesession)
	{
		cout << "\n\tМаксимальное число сеансов!!!" << endl;
		return;
	}

	int i = *currentsize_session;
	int session_id, tick;
	char mv_n[30];
	double price;
	double time, init=0;

	sess[i] = new Session();
	cout << "\n\t ***** Создаём сеанс *****" << endl;
	cout << "\n\t Введите ID сеанса: ";
	cin >> session_id;
	if (session_id < 0)
	{
		cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		return;
	}
	sess[i]->setIdSession(session_id);

	
	cout << "\n\tВведите название фильма: ";
	cin.ignore(32767, '\n'); 
	cin.getline(mv_n, 29);


	sess[i]->setMovieName(mv_n);
	do
	{
		cout << "\n\tВведите количество билетов на фильм: ";
		cin >> tick;
		if (tick <= 0)
		{
			cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		}
	} while (tick<=0);

	sess[i]->settickets(tick);

	do
	{
		cout << "\n\tВведите цену билета: ";
		cin >> price;
		if (price <= 0)
		{
			cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		}
	} while (price <= 0);

	sess[i]->sepriceticket(price);

	cout << "\n\tВведите время сеанса: ";
	cin >> time;

	time = modf(time, &init);

	time = time * 100;

	sess[i]->settime_h(init);
	sess[i]->settime_m(time);


	(*currentsize_session)++;
}

void delete_session(Session* sess[], int* currentsize_session)
{
	int session_id;

	cout << "\n\t***** Удаление сеанса *****" << endl;
	cout << "\n\tВведите ID удаляемого сеанса: ";
	cin >> session_id;

	for (int i = 0; i < *currentsize_session; i++)
	{
		if (sess[i]->getIdSession() == session_id)
		{
			delete sess[i];
			for (int j = i; j < *currentsize_session - 1; j++)
			{
				sess[i] = sess[j + 1];
				
			}
			(*currentsize_session)--;
			return;
		}
	}
	cout << "\n\tТакого cеанса нет" << endl;
}

void print_session(Session* sess[], int currentsize_session)
{
	if (currentsize_session == 0)
	{
		cout << "\n\tСеанс ещё не создан" << endl;
		return;
	}

	cout << "\n\t\t\t\t\t --- Информация о сеансах ---\n";
	cout << "+=================================================================================================================+";
	cout << "\n||ID сеанса" << "             ||Цена билета           ||" << " Название фильма  " << " ||Количество билетов  ||" << "Время сеанса   \t||\n";
	cout << "||======================||======================||===================||====================||===================||\n";
	for (int i = 0; i < currentsize_session; i++)
	{
		cout << "||" << setw(10) << sess[i]->getIdSession() << "\t\t||" << setw(12) << sess[i]->getpriceticket()<<"$" << "\t\t||\t" << setw(12) << sess[i]->getMovieName() << " || " << setw(5) << sess[i]->gettickets() << "\t\t   ||"<<setw(8)<<sess[i]->gettime_h()<<":"<<sess[i]->gettime_m()<<"\t||" << endl;
	}
	cout << "+=================================================================================================================+" << endl;
}

template <typename T1, typename T2>
T1 change_session(T1 sess[], T2 currentsize_session)
{
	cout << "\n\t***** Изменяем параметры сеанса *****" << endl;
	int c;
	int session_id;
	int tickets;
	double pricetickets, time, init;
	char mvnm[30];

	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;
	
	for (int i = 0; i < currentsize_session; i++)
	{
		if (sess[i]->getIdSession()==session_id)
		{
			cout << "\n\t\t\t\t\t --- Информация о сеансе ---\n";
			cout << "+=================================================================================================================+";
			cout << "\n||ID сеанса" << "             ||Цена билета           ||" << " Название фильма  " << " ||Количество билетов  ||" << "Время сеанса   \t||\n";
			cout << "||======================||======================||===================||====================||===================||\n";
			cout << "||" << setw(10) << sess[i]->getIdSession() << "\t\t||" << setw(12) << sess[i]->getpriceticket() << "$" << "\t\t||\t" << setw(12) << sess[i]->getMovieName() << " || " << setw(5) << sess[i]->gettickets() << "\t\t   ||" << setw(8) << sess[i]->gettime_h() << ":" << sess[i]->gettime_m() << "\t||" << endl;
			cout << "+=================================================================================================================+" << endl;
			cout << endl;
			cout << endl;
			cout << "\n\tКакой параметр вы хотите изменить: " << endl;
			cout << "\n\t1. ID сеанса" << endl;
			cout << "\n\t2. Название фильма" << endl;
			cout << "\n\t3. Количество билетов" << endl;
			cout << "\n\t4. Цена билета" << endl;
			cout << "\n\t5. Время сеанса" << endl;
			cout << ">> ";
			cin >> c;
			
			switch (c)
			{
			case 1:
				cout << "\n\tВведите новый ID сеанса: ";
				cin >> session_id;
				sess[i]->setIdSession(session_id);
				break;
			case 2:
				cout << "\n\tВведите новое название фильма: ";
				cin.ignore(32767, '\n');
				cin.getline(mvnm, 29);
				sess[i]->setMovieName(mvnm);

				break;
			case 3:
				cout << "\n\tВведите новое количество билетов: ";
				cin>>tickets;
				sess[i]->settickets(tickets);
				break;
			case 4:
				cout << "\n\tВведите новую цену билета: ";
				cin >> pricetickets;
				sess[i]->sepriceticket(pricetickets);
				break;
			case 5:

				cout << "\n\tВведите новое время сеанса: ";
				cin >> time;

				time = modf(time, &init);

				time = time * 100;

				sess[i]->settime_h(init);
				sess[i]->settime_m(time);

				break;
			}
			return 0;
		}
		cout << "\n\tCеанс с таким ID найти не удалось" << endl;
	}
	

}

void sorting(Session* v[], int currentsize_session)
{
	cout << "\n\t***** Сортируем сеансы по названию фильма *****" << endl;
	Session* tmp;
	for (int i = 0; i < currentsize_session; i++)
	{
		for(int j=i; j<currentsize_session; j++)
		{
			if (strcmp(v[i]->getMovieName(), v[j]->getMovieName()) > 0)
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	cout << "\n\t***** Сортировка завершена *****" << endl;
}

void sorting(int currentsize_session, Session* v[])
{
	cout << "\n\t***** Сортируем сеансы по ID *****" << endl;
	Session* tmp;
	for (int i = 0; i < currentsize_session; i++)
	{
		for (int j = i; j < currentsize_session; j++)
		{
			if (v[i]->getIdSession() > v[j]->getIdSession())
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	cout << "\n\t***** Сортировка завершена *****" << endl;
}

void filtrdelete_session(Session* sess[], int* currentsize_session)
{
	int c = 0;
	int low_tmp;
	int high_tmp;
	cout << "\t Введите нижнюю границу ID:  ";
	cin >> low_tmp;
	cout << "\t Введите верхнюю границу ID:  ";
	cin >> high_tmp;
	for (int i = 0; i < *currentsize_session; i++)
		if (sess[i]->getIdSession() >= low_tmp && sess[i]->getIdSession() <= high_tmp)
		{
			c++;
			delete sess[i];
			for (int j = i; j < *currentsize_session - 1; j++)
				sess[j] = sess[j + 1];
			i--;
			(*currentsize_session)--;
		}
	cout << "\n\t В заданном диапозоне удалено " << c << " игр!" << endl;
}









