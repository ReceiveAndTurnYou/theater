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
		cout << "0. Выход в главное меню" << endl;
		cout << "1. Создать кинотеатр" << endl;
		cout << "2. Вывести кинотеатр" << endl;
		cout << "3. Добавить сеанс" << endl;
		cout << "4. Удалить сеанс" << endl;
		cout << "5. Вывести сеанс" << endl;
		cout << "6. Изменить параметры сеанса" << endl;
		cout << "7. Добавить зрителя" << endl;
		cout << "8. Просмотреть зрителей" << endl;
		cout << "9. Удалить зрителя" << endl;
		cout << "10. Изменить зрителя" << endl;
		cout << "11. Сортировать сеансы по названию фильма" << endl;
		cout << "12. Сортировать сеансы по ID" << endl;
		cout << "13. Сортировать зрителей по фамилии" << endl;
		cout << "14. Сортировать зрителей по ID" << endl;
		cout << "15. Занести данные в файл" << endl;
		cout << "16. Загрузить данные из файла" << endl;
		cout << "17. Удалить несколько сеансов в диапазоне" << endl;
		cout << "18. Купить билет" << endl;
		cout << "19. Рассчитать средний возраст зрителей на сеансе (использование перегруженного оператора)" << endl;
		cout << "20. Вывести определенный параметр" << endl;
		cout << "21. Изменить имена кинотеатру, фильму и зрителю" << endl;
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
		cout << "0. Выход в главное меню" << endl;
		cout << "1. Вывести кинотеатр" << endl;
		cout << "2. Вывести сеанс" << endl;
		cout << "3. Просмотреть зрителей" << endl;
		cout << "4. Сортировать сеансы по названию фильма" << endl;
		cout << "5. Сортировать сеансы по ID" << endl;
		cout << "6. Сортировать зрителей по фамилии" << endl;
		cout << "7. Сортировать зрителей по ID" << endl;
		cout << "8. Купить билет" << endl;
		cout << "9. Вывести определенный параметр" << endl;
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

	cout << "\n\t***** Создание файла администратора *****" << endl;
	cout << "\n\tВведите маску: ";
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
		cout << "\t  Ошибка открытия файла!" << endl;
		return  false;
	}

	fscanf(admin_file, "%s", admin_login);

	int counter = 0;
	char* checking = new char[81];
	while (counter < 3)
	{
		cout << "\t Введите логин администратора:  ";
		fflush(stdin);
		cin >> checking;
		if (strcmp(checking, admin_login) == 0)
		{
			fclose(admin_file);
			return true;
		}
		counter++;
		cout << "\tВведенный логин:" << checking;
		cout << "\n\t Неверный ввод логина!\n";
	}
	cout << "\tВы превысили количество попыток" << endl;
	fclose(admin_file);
	return false;
}

bool check_password()
{
	FILE* admin_file = fopen("admin_file.txt", "r");
	char* admin_password = new char[81];
	if (!admin_file)
	{
		puts("\t  Ошибка открытия файла!\n");
		return  false;
	}
	fscanf(admin_file, "%s%s", admin_password, admin_password);
	int input_counter = 0;
	char* str_symbol = new char[1];
	unsigned char symbol;
	printf("\t Введите маску: ");
	strcpy(str_symbol, inputpass());
	symbol = str_symbol[0];
	char* checking = new char[81];
	while (input_counter < 3)
	{
		printf("\n\t Введите пароль администратора:  ");
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
		cout<<"\n\t\t Неверный ввод пароля!"<<endl;
	}
	cout << "\tВы превысили количество попыток!" << endl;
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
		cout << "\t  Ошибка открытия файла администратора!\n";
		return;
	}
	fscanf(admin_file, "%s%s", login, password);
	fclose(admin_file);

	flag = false;
	if (read_yes_no("\nИзменить логин?"))
	{
		fflush(stdin);  flag = true;
		cout << "\t\t Введите новый логин администратора:  ";
		cin >> login;
		fflush(stdin);
	}
	if (read_yes_no("\nИзменить пароль?"))
	{
		flag = true;
		cout << "\t\t Введите новый пароль администратора:  ";
		fflush(stdin);
		password_new = inputpass();
		if (flag)
		{
			unsigned char maska;
			char* str_maska = new char[1];;
			cout << "\n\t  Введите маску администратора: ";
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

	cout << "\n\t***** Покупаем билет *****" << endl;

	cout << "\n\tВведите ID сеанса: ";
	cin >> session_id;
	
	for (int i = 0; i < currentsize_session; i++)
	{
		if (sess[i]->getIdSession() == session_id)
		{
			cout << "\n\tНайден сеанс с такими параметрами:" << endl;
			cout << endl;
			sess[i]->print();
			cout << endl;
			cout << "\n\tСколько билетов вы хотите купить: ";
			cin >> tickets;
			if (tickets > sess[i]->gettickets())
			{
				cout << "\n\tСтолько билетов нет!" << endl;
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
	cout << "\n\t***** Выводим определенный параметр *****" << endl;
	cout << "Выберите объект: " << endl;
	cout << "1. Кинотеатр" << endl;
	cout << "2. Сеанс" << endl;
	cout << "3. Зритель" << endl;
	cout << ">> ";
	cin >> ch;
	if (ch == 1)
	{
		cout << "Какой параметр вывести: " << endl;
		cout << "1. ID кинотеатра" << endl;
		cout << "2. Название кинотеатра" << endl;
		cout << "3. Адрес кинотеатра" << endl;
		cout << "4. Доход кинотеатра" << endl;
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
		cout << "Введите ID сеанса: ";
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
			cout << "Какой параметр вывести: " << endl;
			cout << "1. ID сеанса" << endl;
			cout << "2. Цена билета" << endl;
			cout << "3. Название фильма" << endl;
			cout << "4. Количество билетов" << endl;
			cout << "5. Время сеанса" << endl;
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

			default: cout << "Неверное значение" << endl;
			}
		}
		else
		{
			cout << "\n\tСеансов с таким ID нет" << endl;
			return;
		}

		
	}
	if (ch == 3)
	{
		cout << "Введите ID зрителя: ";
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
			cout << "Какой параметр вывести: " << endl;
			cout << "1. ID зрителя" << endl;
			cout << "2. Фамилию зрителя" << endl;
			cout << "3. Возраст зрителя" << endl;
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

			default: cout << "Неверное значение" << endl;
			}
		}
		else
		{
			cout << "\n\tЗрителей с таким ID нет" << endl;
			return;
		}
	}

}

void challnam(Theater theater, Session* sess[], Viewer* v[], int sizesession, int sizeviewer)
{
	int ch;
	int tmp=0;
	cout << "\n\t***** Меняем все имена *****" << endl;
	theater.change_all_names();
	
	
	cout << "Введите ID сеанса: ";
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
		cout << "\n\tСеансов с таким ID нет" << endl;
		return;
	}

	
	cout << "Введите ID зрителя: ";
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
		cout << "\n\tЗрителей с таким ID нет" << endl;
		return;
	}

}