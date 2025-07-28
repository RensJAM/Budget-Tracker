#include <iostream>
#include <vector>

std::vector<std::string> transactionDesc;
std::vector<double> transactionValue;

static int size = 0;
static int index = 0;
static double bal = 0;

void addTransaction(std::string desc, double value)
{
	transactionDesc.insert(transactionDesc.begin() + index, desc);
	transactionValue.insert(transactionValue.begin() + index, value);

	std::cout << transactionDesc[index] << " $" << transactionValue[index] << std::endl;
	index++;
	size++;

}

void showTransactions()
{
	for (int i = 0; i < size; i++) {
		std::cout << "\n";
		std::cout << i + 1 <<". " << transactionDesc[i] << " $" << transactionValue[i] << std::endl;
		std::cout << "\n";

	}

}

void removeTransaction(int sel)
{
	if (sel < 1 || sel > transactionDesc.size()) {
		std::cerr << "Invalid transaction number.\n";
		return;
	}
	transactionDesc.erase(transactionDesc.begin() + (sel - 1));
	transactionValue.erase(transactionValue.begin() + (sel - 1));
	index = index - 1;

}

double calcBal();
double calcIncome();
double calcExpenses();

void showSum()
{
	
	double totalIncome = calcIncome();
	std::cout << "Total income: $" << totalIncome << std::endl;

	double totalExpense = calcExpenses();
	std::cout << "Total expenses: $" << -totalExpense << std::endl;

	bal = calcBal();
	std::cout << "Current balance: $" << bal << std::endl;
}

static double calcBal()
{
	double money = 0;

	for (int i = 0; i < index; i++)
	{
		money += transactionValue[i];
	}

	return money;
}

static double calcIncome()
{
	double totalIncome = 0;

	for (int i = 0; i < index; i++)
	{
		if (transactionValue[i] >= 0)
		{
			totalIncome += transactionValue[i];
		}
	}
	return totalIncome;
}

static double calcExpenses()
{
	double totalExpense = 0;

	for (int i = 0; i < index; i++)
	{
		if (transactionValue[i] < 0)
		{
			totalExpense += transactionValue[i];
		}
	}
	return totalExpense;
}