#pragma once
#include <iostream>
#include "Viewer.h"


using namespace std;

void create_viewer(Viewer* v[], int size_viewer, int* currentsize_viewer)
{
	if (*currentsize_viewer == size_viewer)
	{
		cout << "\n\t������������ ���������� ��������!!!" << endl;
		return;
	}

	int i = *currentsize_viewer;
	int session_id, client_id;
	int age;
	int how_much_tick;

	char fio[20];

	v[i] = new Viewer();

	cout << "\n\t ***** ��������� ������� *****" << endl;

	cout << "\n\t������� ID ������: ";
	cin >> session_id;

	if (session_id < 0)
	{
		cout << "\n\t������������ ����, ���������� ��� ���!" << endl;
		return;
	}

	v[i]->setIdSession(session_id);

	do
	{
		cout << "\n\t������� ID �������: ";
		cin >> client_id;

		if (client_id < 0)
		{
			cout << "\n\t������������ ����, ���������� ��� ���!" << endl;
			return;
		}
	} while (client_id < 0);
	v[i]->setidviewer(client_id);

	do
	{
		cout << "\n\t������� ������� �������: ";
		cin >> age;
		if (age < 18 || age>80)
		{
			cout << "\n\t������������ ����, ���������� ��� ���!" << endl;
		}
	} while (age<18 || age>80);

	v[i]->setage(age);


	cout << "\n\t������� ������� �������: ";
	cin >> fio;

	v[i]->setfio(fio);


	/*do
	{
		cout << "\n\t������� ���������� �������, ������� �� ������ �����: ";
		cin >> how_much_tick;

		if (how_much_tick<0 )
		{
			cout << "\n\t������������ ����, ���������� ��� ���!" << endl;
		}
	} while (how_much_tick<0);

	cout << "\n\t�� ����� " << how_much_tick << " �������" << endl;*/

	(*currentsize_viewer)++;
}

void delete_viewer(Viewer* v[], int* currentsize_viewer)
{
	int session_id, viewer_id;

	cout << "\n\t***** ������� ������� *****" << endl;
	cout << "\n\t������� ID ���������� �������: ";
	cin >> viewer_id;
	cout << "\n\t������� ID ������: ";
	cin >> session_id;

	for (int i = 0; i < *currentsize_viewer; i++)
	{
		if (v[i]->getIdSession() == session_id && v[i]->getidviewer() == viewer_id)
		{
			cout << "\n\t������� ������� � ������ �����������" << endl;
			cout << "\n\t������� �������: " << v[i]->getfio() << endl;
			cout << "\n\t������� �������: " << v[i]->getage() << endl;
			cout << "\n\tID �������: " << v[i]->getidviewer() << endl;
			cout << "\n\tID ������: " << v[i]->getIdSession() << endl;
			delete v[i];
			for (int j = i; j < *currentsize_viewer-1; j++)
			{
				v[j] = v[j + 1];
			}
			(*currentsize_viewer)--;
			return;
		}
	}
	cout << "\n\t���� �� ����� ������� �������, ���������� ��� ���!" << endl;
}

void print_viewer(Viewer* v[], int currentsize_viewer)
{
	if (currentsize_viewer == 0)
	{
		cout << "�� ������ ������� ��� �� �������" << endl;
		return;
	}
	
	cout << "\n\t***** ������� �������� *****" << endl;
	cout << "+================================================================+";
	cout << "\n||������� �������" << " || �������" << "    || ID ������ " << "||  ID �������     ||\n";
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

	cout << "\n\t***** �������� ������� *****" << endl;
	cout << "\n\t������� ID ������: ";
	cin >> session_id;
	cout << "\n\t������� ID �������: ";
	cin >> viewer_id;

	for (int i = 0; i < currentsize_viewer; i++)
	{
		if (v[i]->getIdSession() == session_id && v[i]->getidviewer() == viewer_id)
		{
			cout << "\n\t***** ���������� � ������� *****" << endl;
			cout << "+================================================================+";
			cout << "\n||������� �������" << " || �������" << "    || ID ������ " << "||  ID �������     ||\n";
			cout << "||================||============||===========||=================||";
			cout << "\n|| " << setw(12) << v[i]->getfio() << "\t  ||\t" << setw(4) << v[i]->getage() << "\t||   " << setw(6) << v[i]->getIdSession() << "  ||\t" << setw(4)
				<< v[i]->getidviewer() << "\t        ||";
			cout << "\n+================================================================+" << endl;
			cout << endl << endl;
			cout << "\n\t����� �������� �� ������ ��������: " << endl;
			cout << "1. ID �������" << endl;
			cout << "2. ID ������" << endl;
			cout << "3. �������" << endl;
			cout << "4. �������" << endl;
			cout << ">> ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				cout << "������� ����� ID �������: ";
				cin >> viewer_id;
				v[i]->setidviewer(viewer_id);
				break;

			case 2:
				cout << "������� ����� ID ������: ";
				cin >> session_id;

				v[i]->setIdSession(session_id);
				break;
				
			case 3:
				cout << "������� ����� �������: ";
				cin >> fam;
				v[i]->setfio(fam);
				break;

			case 4:
				cout << "������� �������: ";
				cin >> age;
				v[i]->setage(age);
				break;
			}
			return;
		}
		cout << "\n\t������� � ������ ����������� ����� �� �������" << endl;
	}
}

namespace sortfam
{
	void sorting(Viewer* v[], int currentsize_viewer)
	{
		cout << "\n\t***** ��������� �������� �� ������� *****" << endl;
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
		cout << "\n\t***** ��������� �������� �� ID *****" << endl;
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
	cout << "\n\t***** ������������ ������� ������� �������� �� ������ *****" << endl;
	cout << "\n\t������� ID ������: ";
	cin >> session_id;
	int c = 0;

	for (int i = 0; i < currentsize_session; i++)
	{
		if (sess[i]->getIdSession() == session_id)
		{
			cout << "\n\t������ ����� � ������ �����������:" << endl;
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
	
	cout << "\n\t�����: " << tmp.getage() << endl;

	ts = tmp.getage() / c;

	cout << "\n\t������� ������� �����: " << ts << endl;



}