#include <iostream>
#include <Windows.h>
#include <string>
#include "Theater.h"
#include "Session.h"
#include "Viewer.h"
#include "Functions.h"
#include "FunctionsTheater.h"
#include "FunctionsSession.h"
#include "FunctionsViewer.h"
#include "Files.h" 

using namespace std;


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	admin_file();
	const int size_session = 10, size_viewer=30;
	int currentsize_session = 0, currentsize_viewer = 0;
	int choice;
	
	Theater theater;

	Session* session[size_session], temp_session[10];
	Viewer* viewer[size_viewer], temp_viewer[30];

	bool is_theater = false;
	bool is_session = false;
	bool is_viewer = false;
	bool admin = false;
	bool newday = false;

	while (true)
	{
		cout << "Под каким правами вы хотите войти:" << endl;
		cout << "0. Выход из программы" << endl;
		cout << "1. Права администратора" << endl;
		cout << "2. Права клиента" << endl;
		cout << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 0: return;

		case 1:
			system("CLS");
			if (admin == false)
			{
				if (check_login() == false || check_password() == false)
				{
					cout << "\n\tНеверный логин или пароль" << endl;
					return;
				}
				else
				{
					admin = true;
				}
			}

			while (true)
			{
				system("CLS");
				cout << endl;
				cout << "\t ***** Меню администратора *****" << endl;
				choice = menu_admin();
				if (choice == 0)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					system("CLS");
					if (is_theater)
					{
						cout << "\n\tКинотеатр уже создан!!!" << endl;
						
					}
					else
					{
						create_theater(theater);
						is_theater = true;
					}
					system("PAUSE");
					break;

				case 2:
					system("CLS");
					if (is_theater)
					{
						print_theater(theater);
					}
					else
					{
						cout << "\n\tВы ещё не создали кинотеатр" << endl;
					}
					system("PAUSE");
					break;

				case 3:
					system("CLS");
					if (is_theater)
					{
						create_session(session, size_session, &currentsize_session);
						is_session = true;
					}
					else
					{
						cout << "\n\tВы ещё не создали кинотеатр!" << endl;
					}
					system("PAUSE");
					break;

				case 4:
					system("CLS");

					if (is_theater && is_session)
					{
						delete_session(session, &currentsize_session);
					}
					else
					{
						cout << "\n\tКинотеатр или сессия ещё не была создана" << endl;
					}

					system("PAUSE");
					break;

				case 5:
					system("CLS");
					if (is_theater && is_session)
					{
						print_session(session, currentsize_session);
					}
					else
					{
						cout << "\n\tКинотеатр или сессия ещё не была создана" << endl;
					}
					system("PAUSE");
					break;

				
				case 6:
					system("CLS");
					if (is_theater && is_session)
					{
						change_session(session, currentsize_session);
					}	
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан!" << endl;
					}
					system("PAUSE");
					break;

				case 7:
					system("CLS");
					if (is_theater && is_session)
					{
						create_viewer(viewer, size_viewer, &currentsize_viewer);
						is_viewer = true;
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}
					system("PAUSE");

					break;

				case 8:
					system("CLS");
					if (is_theater && is_session && is_viewer)
					{
						print_viewer(viewer, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}
					system("PAUSE");

					break;

				case 9:
					system("CLS");
					if (is_theater && is_session && is_viewer)
					{
						delete_viewer(viewer, &currentsize_viewer);

					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}

					system("PAUSE");
					break;
				case 10:
					system("CLS");
					if (is_theater && is_session && is_viewer)
					{
						change_viewer(viewer, currentsize_viewer);

					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан!!!" << endl;
					}

					system("PAUSE");
					break;

				case 11:
					system("CLS");
					if (is_theater && is_session)
					{
						sorting(session, currentsize_session);
					}
					else
					{
						cout << "\n\tКинотеатр или сессия не создана" << endl;
					}
					system("PAUSE");
					break;

				case 12:
					system("CLS");
					if (is_theater && is_session)
					{
						sorting(currentsize_session, session);
					}
					else
					{
						cout << "\n\tКинотеатр или сессия ещё не создана" << endl;
					}

					system("PAUSE");
					break;

				case 13:
					
					system("CLS");
					if (is_theater && is_session && is_viewer)
					{
						sortfam::sorting(viewer, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс не создан!" << endl;
					}
					system("PAUSE");
					break;

				case 14:
					system("CLS");
					if (is_theater && is_session && is_viewer)
					{
						sortid::sorting(viewer, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан!" << endl;
					}

					system("PAUSE");
					break;

				case 15:
					system("CLS");

					if (is_theater && is_session && is_viewer)
					{
						inputfile_all(theater, session, temp_session, currentsize_session, viewer, temp_viewer, currentsize_viewer);
						newday = true;
					}
					else
					{	
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}

					system("PAUSE");
					break;

				case 16:
					system("CLS");
					if (!newday)
					{
						cout << "\n\tЗАГРУЖАЕМ" << endl;
						startnewday(session, size_session, viewer, size_viewer);
						admin = true;
						is_theater = true;
						is_session = true;
						is_viewer = true;
						newday = true;
						outfile_all(theater, session, temp_session, viewer, temp_viewer, &currentsize_session, &currentsize_viewer);

					}
					else
					{
						if (is_theater && is_session && is_viewer)
						{
							outfile_all(theater, session, temp_session, viewer, temp_viewer, &currentsize_session, &currentsize_viewer);
						}
					}
					system("PAUSE");
					break;

				case 17:
					system("CLS");
					if (is_theater && is_session)
					{
						filtrdelete_session(session, &currentsize_session);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс не создан" << endl;
					}


					system("PAUSE");
					
					break;

				case 18:
					system("CLS");

					if (is_theater && is_session)
					{
						buyticket(theater, session, currentsize_session);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}

					system("PAUSE");
					break;

				case 19:
					system("CLS");

					if (is_theater && is_session && is_viewer)
					{
						count_middle_age(viewer, session, currentsize_session, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}

					system("PAUSE");

					break;

				case 20:

					system("CLS");
					
					if (is_theater && is_session && is_viewer)
					{
						prsel(theater, session, viewer, currentsize_session, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}
					system("PAUSE");
					break;

				case 21:

					system("CLS");

					if (is_theater && is_session && is_viewer)
					{
						challnam(theater, session, viewer, currentsize_session, currentsize_viewer);
					}
					else
					{
						cout << "\n\tКинотеатр или сеанс ещё не создан" << endl;
					}
					system("PAUSE");
					break;

				default: cout << "Неверный выбор, попробуйте ещё раз!" << endl; system("PAUSE"); break;
				}
			}
			break;

		case 2:
			system("CLS");
			while (true)
			{
				cout << endl;
				cout << "\n\t***** Меню клиента *****" << endl;
				choice = menu_user();
				if (choice == 0)
				{
					break;
				}
				switch (choice)
				{
				case 1:
					
					system("CLS");
					if (is_theater)
					{
						print_theater(theater);
					}
					else
					{
						cout << "\n\tКинотеатр ещё не создан" << endl;
					}
					system("PAUSE");
					break;

				case 2:
					
					system("CLS");
					print_session(session, currentsize_session);
					system("PAUSE");
					break;

				case 3:
				
					system("CLS");
					print_viewer(viewer, currentsize_viewer);
					system("PAUSE");
					break;

				case 4:
					
					system("CLS");
					sorting(session, currentsize_session);
					system("PAUSE");
					break;

				case 5:
					
					system("CLS");
					sorting(currentsize_session, session);
					system("PAUSE");
					break;

				case 6:
					
					system("CLS");
					sortfam::sorting(viewer, currentsize_viewer);
					system("PAUSE");
					break;

				case 7:
					
					system("CLS");
					sortid::sorting(viewer, currentsize_viewer);
					system("PAUSE");
					break;

				case 8:
					buyticket(theater, session, currentsize_session);
					break;

				case 9:
					system("CLS");

					if (is_theater && is_session && is_viewer)
					{
						challnam(theater, session, viewer, currentsize_session, currentsize_viewer);
					}

					system("PAUSE");
					break;

				default:cout << "\n\tНекорректный ввод, попробуйте ещё раз!" << endl; system("PAUSE");
					break;
				}
			
			}
			break;
		}
	}


}