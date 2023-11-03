#pragma once
#include "Theater.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Session : public Theater
{
protected:
	int idSession;
	double price_ticket;
	char movie_name[30];
	int tickets;
	double time_h, time_m;

public:

	void setIdSession(int id);
	int getIdSession();

	void setMovieName(char* mvnm);
	char* getMovieName();

	void settickets(int tick);
	int gettickets();

	void settime_h(double t);
	void settime_m(double t);

	double gettime_h();
	double gettime_m();

	void sepriceticket(double pt);
	double getpriceticket();

	virtual void print();

	void print_select(int a) override;
	void change_all_names() override;

	friend void sorting(Session* [], int);
	friend void sorting(int, Session* []);

};

