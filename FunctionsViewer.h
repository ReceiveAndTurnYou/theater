#pragma once
#include <iostream>
#include "Viewer.h"


using namespace std;

void create_viewer(Viewer* v[], int size_viewer, int* currentsize_viewer)
{
	if (*currentsize_viewer == size_viewer)
	{
		cout << "\n\tМаксимальное количество зрителей!!!" << endl;
		return;
	}

	int i = *currentsize_viewer;
	int session_id, client_id;
	int age;
	int how_much_tick;

	char fio[20];

	v[i] = new Viewer();

	cout << "\n\t ***** Добавляем зрителя *****" << endl;

	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;

	if (session_id < 0)
	{
		cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		return;
	}

	v[i]->setIdSession(session_id);

	do
	{
		cout << "\n\tВведите ID зрителя: ";
		cin >> client_id;

		if (client_id < 0)
		{
			cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
			return;
		}
	} while (client_id < 0);
	v[i]->setidviewer(client_id);

	do
	{
		cout << "\n\tВведите возраст зрителя: ";
		cin >> age;
		if (age < 18 || age>80)
		{
			cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		}
	} while (age<18 || age>80);

	v[i]->setage(age);


	cout << "\n\tВведите фамилию зрителя: ";
	cin >> fio;

	v[i]->setfio(fio);


	/*do
	{
		cout << "\n\tВведите количество билетов, которое вы хотите взять: ";
		cin >> how_much_tick;

		if (how_much_tick<0 )
		{
			cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl;
		}
	} while (how_much_tick<0);

	cout << "\n\tВы берёте " << how_much_tick << " билетов" << endl;*/

	(*currentsize_viewer)++;
}

void delete_viewer(Viewer* v[], int* currentsize_viewer)
{
	int session_id, viewer_id;

	cout << "\n\t***** Удаляем зрителя *****" << endl;
	cout << "\n\tВведите ID удаляемого зрителя: ";
	cin >> viewer_id;
	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;

	for (int i = 0; i < *currentsize_viewer; i++)
	{
		if (v[i]->getIdSession() == session_id && v[i]->getidviewer() == viewer_id)
		{
			cout << "\n\tУдаляем зрителя с такими параметрами" << endl;
			cout << "\n\tФамилия зрителя: " << v[i]->getfio() << endl;
			cout << "\n\tВозраст зрителя: " << v[i]->getage() << endl;
			cout << "\n\tID зрителя: " << v[i]->getidviewer() << endl;
			cout << "\n\tID сеанса: " << v[i]->getIdSession() << endl;
			delete v[i];
			for (int j = i; j < *currentsize_viewer-1; j++)
			{
				v[j] = v[j + 1];
			}
			(*currentsize_viewer)--;
			return;
		}
	}
	cout << "\n\tОдно из полей введено неверно, попробуйте ещё раз!" << endl;
}

void print_viewer(Viewer* v[], int currentsize_viewer)
{
	if (currentsize_viewer == 0)
	{
		cout << "Ни одного зрителя ещё не создано" << endl;
		return;
	}
	
	cout << "\n\t***** Выводим зрителей *****" << endl;
	cout << "+================================================================+";
	cout << "\n||Фамилия зрителя" << " || Возраст" << "    || ID сеанса " << "||  ID зрителя     ||\n";
	cout << "||================||============||===========||=================||";
	for (int i = 0; i < currentsize_viewer; i++)
	{
		cout << "\n|| " << setw(12) << v[i]->getfio() << "\t  ||\t" << setw(4) << v[i]->getage() << "\t||   " << setw(6) << v[i]->getIdSession() << "  ||\t" << setw(4)
			<< v[i]->getidviewer() << "\t        ||";
	}
	cout << "\n+================================================================+" << endl;
}

void change_viewer(Viewer* v[], int currentsize_viewer)
{
	int session_id;
	int viewer_id;
	int ch;
	char fam[30];
	int age;

	cout << "\n\t***** Изменяем зрителя *****" << endl;
	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;
	cout << "\n\tВведите ID зрителя: ";
	cin >> viewer_id;

	for (int i = 0; i < currentsize_viewer; i++)
	{
		if (v[i]->getIdSession() == session_id && v[i]->getidviewer() == viewer_id)
		{
			cout << "\n\t***** Информация о зрителе *****" << endl;
			cout << "+================================================================+";
			cout << "\n||Фамилия зрителя" << " || Возраст" << "    || ID сеанса " << "||  ID зрителя     ||\n";
			cout << "||================||============||===========||=================||";
			cout << "\n|| " << setw(12) << v[i]->getfio() << "\t  ||\t" << setw(4) << v[i]->getage() << "\t||   " << setw(6) << v[i]->getIdSession() << "  ||\t" << setw(4)
				<< v[i]->getidviewer() << "\t        ||";
			cout << "\n+================================================================+" << endl;
			cout << endl << endl;
			cout << "\n\tКакой параметр вы хотите изменить: " << endl;
			cout << "1. ID клиента" << endl;
			cout << "2. ID сеанса" << endl;
			cout << "3. Фамилия" << endl;
			cout << "4. Возраст" << endl;
			cout << ">> ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "Введите новый ID клиента: ";
				cin >> viewer_id;
				v[i]->setidviewer(viewer_id);
				break;

			case 2:
				cout << "Введите новый ID сеанса: ";
				cin >> session_id;

				v[i]->setIdSession(session_id);
				break;
				
			case 3:
				cout << "Введите новую фамилию: ";
				cin >> fam;
				v[i]->setfio(fam);
				break;

			case 4:
				cout << "Введите возраст: ";
				cin >> age;
				v[i]->setage(age);
				break;
			}
			return;
		}
		cout << "\n\tЗрителя с такими параметрами найти не удалось" << endl;
	}
}

namespace sortfam
{
	void sorting(Viewer* v[], int currentsize_viewer)
	{
		cout << "\n\t***** Сортируем зрителей по фамилии *****" << endl;
		Viewer* tmp;
		for (int i = 0; i < currentsize_viewer; i++)
		{
			for (int j = i; j < currentsize_viewer; j++)
			{
				if (strcmp(v[i]->getfio(), v[j]->getfio()) > 0)
				{
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;
				}
			}
		}
	}
}

namespace sortid
{
	void sorting(Viewer* v[], int currentsize_session)
	{
		cout << "\n\t***** Сортируем зрителей по ID *****" << endl;
		Viewer* tmp;

		for (int i = 0; i < currentsize_session; i++)
		{
			for (int j = i; j < currentsize_session; j++)
			{
				if (v[i]->getidviewer() > v[j]->getidviewer())
				{
					tmp = v[i];
					v[i] = v[j];
					v[j] = tmp;

				}
			}
		}
	}
}

void count_middle_age(Viewer* v[], Session* sess[], int currentsize_session, int currentsize_viewer)
{
	int session_id, ts;
	Viewer tmp;
	cout << "\n\t***** Рассчитываем средний возраст зрителей на сеансе *****" << endl;
	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;
	int c = 0;

	for (int i = 0; i < currentsize_session; i++)
	{
		if (sess[i]->getIdSession() == session_id)
		{
			cout << "\n\tНайден сеанс с такими параметрами:" << endl;
			cout << endl;
			sess[i]->print();
			cout << endl;
			for (int j = 0; j < currentsize_viewer; j++)
			{
				if (session_id == v[j]->getIdSession())
				{
					tmp.setage(tmp + v[j]);
					c++;
				}
			}

		}
	}
	
	cout << "\n\tСумма: " << tmp.getage() << endl;

	ts = tmp.getage() / c;

	cout << "\n\tСредний возраст равен: " << ts << endl;



}