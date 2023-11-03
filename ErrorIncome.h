#pragma once
#include <iostream>
#include "Theater.h"

using namespace std;

template<typename Income>
class IncomeError
{
	Income theater_income;
public:
	void showErrorIncome(Income theater_income);
	IncomeError(Income inc);
};