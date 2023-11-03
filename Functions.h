#pragma once
#include <iostream>
#include <conio.h>
#include "Theater.h"
#pragma warning(disable:4996)

using namespace std;

int menu_admin()
{
	int choice;
	do
	{
		cout << "0. ����� � ������� ����" << endl;
		cout << "1. ������� ���������" << endl;
		cout << "2. ������� ���������" << endl;
		cout << "3. �������� �����" << endl;
		cout << "4. ������� �����" << endl;
		cout << "5. ������� �����" << endl;
		cout << "6. �������� ��������� ������" << endl;
		cout << "7. �������� �������" << endl;
		cout << "8. ����������� ��������" << endl;
		cout << "9. ������� �������" << endl;
		cout << "10. �������� �������" << endl;
		cout << "11. ����������� ������ �� �������� ������" << endl;
		cout << "12. ����������� ������ �� ID" << endl;
		cout << "13. ����������� �������� �� �������" << endl;
		cout << "14. ����������� �������� �� ID" << endl;
		cout << "15. ������� ������ � ����" << endl;
		cout << "16. ��������� ������ �� �����" << endl;
		cout << "17. ������� ��������� ������� � ���������" << endl;
		cout << "18. ������ �����" << endl;
		cout << "19. ���������� ������� ������� �������� �� ������ (������������� �������������� ���������)" << endl;
		cout << "20. ������� ������������ ��������" << endl;
		cout << "21. �������� ����� ����������, ������ � �������" << endl;
		cout << ">> ";
		cin >> choice;
		return choice;

	} while(choice<0 || choice>19);
}

int menu_user()
{
	int choice;
	do
	{
		cout << "0. ����� � ������� ����" << endl;
		cout << "1. ������� ���������" << endl;
		cout << "2. ������� �����" << endl;
		cout << "3. ����������� ��������" << endl;
		cout << "4. ����������� ������ �� �������� ������" << endl;
		cout << "5. ����������� ������ �� ID" << endl;
		cout << "6. ����������� �������� �� �������" << endl;
		cout << "7. ����������� �������� �� ID" << endl;
		cout << "8. ������ �����" << endl;
		cout << "9. ������� ������������ ��������" << endl;
		cout << ">> ";
		cin >> choice;
		return choice;
	} while(choice<0 || choice>8);
}

char* inputpass()
{
	int i = 0;
	char c;
	char* passwrd = new char[81];
	while (true)
	{
		c = _getch();
		cout << "*";
		if (c == '\r')
		{
			break;
		}
		if (c != 8)
		{
			passwrd[i] = c;
			i++;
		}
	}
	passwrd[i] = '\0';
	return passwrd;
}

bool admin_file()
{
	FILE* admin_file;

	admin_file = fopen("admin_file.txt", "r");
	if (admin_file != NULL)
	{
		return false;
	}

	const char* login, * passwrd;

	login = new char[81];
	passwrd = new char[81];
	char password_new[81];

	login = "Apenka";
	passwrd = "19012001";

	unsigned char symbol;
	char* str_symbol = new char[1];

	cout << "\n\t***** �������� ����� �������������� *****" << endl;
	cout << "\n\t������� �����: ";
	strcpy(str_symbol, inputpass());

	symbol = str_symbol[0];
	fflush(stdin);
	cin.ignore(32767, '\n');
	for (int i = 0; i < strlen(passwrd); i++)
	{
		password_new[i] = (passwrd[i] + (i + 1) + 129) ^ symbol;
	}
	password_new[strlen(passwrd)] = '\0';
	admin_file = fopen("admin_file.txt", "w");
	fprintf(admin_file, "%s %s\n", login, password_new);
	fclose(admin_file);
	return true;
}


bool check_login()
{
	FILE* admin_file = fopen("admin_file.txt", "r");
	char* admin_login = new char[81];
	if (!admin_file)
	{
		cout << "\t  ������ �������� �����!" << endl;
		return  false;
	}

	fscanf(admin_file, "%s", admin_login);

	int counter = 0;
	char* checking = new char[81];
	while (counter < 3)
	{
		cout << "\t ������� ����� ��������������:  ";
		fflush(stdin);
		cin >> checking;
		if (strcmp(checking, admin_login) == 0)
		{
			fclose(admin_file);
			return true;
		}
		counter++;
		cout << "\t��������� �����:" << checking;
		cout << "\n\t �������� ���� ������!\n";
	}
	cout << "\t�� ��������� ���������� �������" << endl;
	fclose(admin_file);
	return false;
}

bool check_password()
{
	FILE* admin_file = fopen("admin_file.txt", "r");
	char* admin_password = new char[81];
	if (!admin_file)
	{
		puts("\t  ������ �������� �����!\n");
		return  false;
	}
	fscanf(admin_file, "%s%s", admin_password, admin_password);
	int input_counter = 0;
	char* str_symbol = new char[1];
	unsigned char symbol;
	printf("\t ������� �����: ");
	strcpy(str_symbol, inputpass());
	symbol = str_symbol[0];
	char* checking = new char[81];
	while (input_counter < 3)
	{
		printf("\n\t ������� ������ ��������������:  ");
		fflush(stdin);
		checking = inputpass();
		for (int i = 0; i < strlen(checking); i++)
		{
			checking[i] = (checking[i] + (i + 1) + 129) ^ symbol;
		}
		if (strcmp(checking, admin_password) == 0)
		{
			fclose(admin_file);
			return true;
		}
		input_counter++;
		cout<<"\n\t\t �������� ���� ������!"<<endl;
	}
	cout << "\t�� ��������� ���������� �������!" << endl;
	fclose(admin_file);
	return false;
}

bool  read_yes_no(const char* quescin)
{
	char ans[7];
	bool  flag = true;
	while (true)
	{
		cout << "\n %s (yes/no)? " << quescin;
		fflush(stdin);
		cin >> ans;
		if (strcmp(ans, "yes") == 0 || strcmp(ans, "YES") == 0 || strcmp(ans, "no") == 0 || strcmp(ans, "NO") == 0)
		{
			break;
		}
	}
	if (ans[0] == 'n' || ans[0] == 'N')
	{
		flag = false;
	}
	return  flag;
}


void change_login_password(void)
{
	char* login, * password;
	login = new char[81];
	password = new char[81];
	char* password_new;
	password_new = new char[81];

	bool  flag;
	FILE* admin_file = fopen("admin_file.txt", "r");
	if (!admin_file)
	{
		cout << "\t  ������ �������� ����� ��������������!\n";
		return;
	}
	fscanf(admin_file, "%s%s", login, password);
	fclose(admin_file);

	flag = false;
	if (read_yes_no("\n�������� �����?"))
	{
		fflush(stdin);  flag = true;
		cout << "\t\t ������� ����� ����� ��������������:  ";
		cin >> login;
		fflush(stdin);
	}
	if (read_yes_no("\n�������� ������?"))
	{
		flag = true;
		cout << "\t\t ������� ����� ������ ��������������:  ";
		fflush(stdin);
		password_new = inputpass();
		if (flag)
		{
			unsigned char maska;
			char* str_maska = new char[1];;
			cout << "\n\t  ������� ����� ��������������: ";
			str_maska = inputpass();
			sscanf(str_maska, "%b", &maska);
			fflush(stdin);
			for (int i = 0; i < strlen(password_new); i++)
				password[i] = password_new[i] + (i + 1) + 7 ^ maska;
			password[strlen(password_new)] = '\0';
		}
	}
	if (flag)
	{
		FILE* admin_file = fopen("admin_file.txt", "w");
		fprintf(admin_file, "%s %s\n", login, password);
		fclose(admin_file);
	}
}


void buyticket(Theater& theater, Session* sess[], int currentsize_session)
{
	int session_id, viewer_id;
	int tickets;
	double setinc;

	cout << "\n\t***** �������� ����� *****" << endl;

	cout << "\n\t������� ID ������: ";
	cin >> session_id;
	
	for (int i = 0; i < currentsize_session; i++)
	{
		if (sess[i]->getIdSession() == session_id)
		{
			cout << "\n\t������ ����� � ������ �����������:" << endl;
			cout << endl;
			sess[i]->print();
			cout << endl;
			cout << "\n\t������� ������� �� ������ ������: ";
			cin >> tickets;
			if (tickets > sess[i]->gettickets())
			{
				cout << "\n\t������� ������� ���!" << endl;
			}
			else
			{
				setinc = tickets * sess[i]->getpriceticket();
				tickets = sess[i]->gettickets() - tickets;
				sess[i]->settickets(tickets);
				theater.setincome(setinc);
			}
			
		}
	}
}

void prsel(Theater theater, Session* sess[], Viewer* v[], int sizesession, int sizeviewer)
{
	int ch;
	int tmp;
	cout << "\n\t***** ������� ������������ �������� *****" << endl;
	cout << "�������� ������: " << endl;
	cout << "1. ���������" << endl;
	cout << "2. �����" << endl;
	cout << "3. �������" << endl;
	cout << ">> ";
	cin >> ch;
	if (ch == 1)
	{
		cout << "����� �������� �������: " << endl;
		cout << "1. ID ����������" << endl;
		cout << "2. �������� ����������" << endl;
		cout << "3. ����� ����������" << endl;
		cout << "4. ����� ����������" << endl;
		cout << ">> ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			theater.print_select(ch);
			break;

		case 2:
			theater.print_select(ch);
			break;

		case 3:
			theater.print_select(ch);
			break;

		case 4:
			theater.print_select(ch);
			break;
		}


	}
	if (ch == 2)
	{
		cout << "������� ID ������: ";
		cin >> ch;

		for (int i = 0; i < sizesession; i++)
		{
			if (sess[i]->getIdSession() == ch)
			{
				ch = 21;
				tmp = i;
			}
		}
		if (ch == 21)
		{
			cout << "����� �������� �������: " << endl;
			cout << "1. ID ������" << endl;
			cout << "2. ���� ������" << endl;
			cout << "3. �������� ������" << endl;
			cout << "4. ���������� �������" << endl;
			cout << "5. ����� ������" << endl;
			cout << ">> ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				sess[tmp]->print_select(ch);
				break;

			case 2:
				sess[tmp]->print_select(ch);
				break;

			case 3:
				sess[tmp]->print_select(ch);
				break;

			case 4:
				sess[tmp]->print_select(ch);
				break;

			case 5:
				sess[tmp]->print_select(ch);
				break;

			default: cout << "�������� ��������" << endl;
			}
		}
		else
		{
			cout << "\n\t������� � ����� ID ���" << endl;
			return;
		}

		
	}
	if (ch == 3)
	{
		cout << "������� ID �������: ";
		cin >> ch;

		for (int i = 0; i < sizeviewer; i++)
		{
			if (v[i]->getid() == ch)
			{
				ch = 222;
				tmp = i;
			}
		}
		if (ch == 222)
		{
			cout << "����� �������� �������: " << endl;
			cout << "1. ID �������" << endl;
			cout << "2. ������� �������" << endl;
			cout << "3. ������� �������" << endl;
			cout << ">> ";
			cin >> ch;
			switch (ch)
			{
			case 1:
				v[tmp]->print_select(ch);
				break;

			case 2:
				v[tmp]->print_select(ch);
				break;

			case 3:
				v[tmp]->print_select(ch);
				break;

			default: cout << "�������� ��������" << endl;
			}
		}
		else
		{
			cout << "\n\t�������� � ����� ID ���" << endl;
			return;
		}
	}

}

void challnam(Theater theater, Session* sess[], Viewer* v[], int sizesession, int sizeviewer)
{
	int ch;
	int tmp=0;
	cout << "\n\t***** ������ ��� ����� *****" << endl;
	theater.change_all_names();
	
	
	cout << "������� ID ������: ";
	cin >> ch;

	for (int i = 0; i < sizesession; i++)
	{
		if (sess[i]->getIdSession() == ch)
		{
			ch = 21;
			tmp = i;
		}
	}
	if (ch == 21)
	{
		sess[tmp]->change_all_names();
	}
	else
	{
		cout << "\n\t������� � ����� ID ���" << endl;
		return;
	}

	
	cout << "������� ID �������: ";
	cin >> ch;

	for (int i = 0; i < sizeviewer; i++)
	{
		if (v[i]->getidviewer() == ch)
		{
			ch = 222;
			tmp = i;
		}
	}
	if (ch == 222)
	{
		v[tmp]->change_all_names();

	}
	else
	{
		cout << "\n\t�������� � ����� ID ���" << endl;
		return;
	}

}