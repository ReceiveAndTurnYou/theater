#pragma once
#include <iostream>
#include "AbstractClass.h"

using namespace std;


class Theater : public Abstract
{
protected:
	int theater_id;
	char theater_name[30];
	char adress[30];
	double income_theater;
public:

	Theater();

	~Theater();


	void setid(int id);
	int getid();

	void setname(char* name);
	char* getname();

	void setadress(char* adr);
	char* getadress();

	void setincome(double inc);
	double getincome();

	virtual void print();
	
	void print_select(int a) override;
	void change_all_names() override;

};

