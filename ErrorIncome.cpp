#include "ErrorIncome.h"

void IncomeError<double>::showErrorIncome(double inc)
{
	cout << "\n\tОшибка: ваш доход - " << inc << " не может уйти в минус" << endl;
}
