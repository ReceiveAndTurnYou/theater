#pragma once
#include "Session.h"
#include <iostream>

using namespace std;


class Viewer : public Session
{
protected:
	int id, theater_id, session_id;
	char fio[30];
	char moviename[30];
	int age;
	int ticketid;
public:

	int gethowmuchtickets()
	{
		return tickets;
	}

	Viewer()
	{
		id = 0;
		theater_id = 0;
		session_id = 0;
		strcpy_s(fio, "Неизвестно");
		strcpy_s(moviename, "Неизвестно");
		age = 0;
	}
	~Viewer()
	{

	}

	void setid(int theater_id);
	int getid();

	void setIdSession(int id);
	int getIdSession();

	void setidviewer(int idv);
	int getidviewer();

	void setfio(char* f);
	char* getfio();

	void setage(int ag);
	int getage();

	void setticketid(int idtick);
	int gettickerid();

	virtual void print();

	void print_select(int a) override;
	void change_all_names() override;
	

	int operator+(Viewer*);

};

