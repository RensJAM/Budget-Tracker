#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<std::string> transactionDesc;
std::vector<double> transactionValue;

static int size = 0;
static int index = 0;
static double bal = 0;

static void updateFile();

void addTransaction(std::string desc, double value)
{
	transactionDesc.insert(transactionDesc.begin() + index, desc);
	transactionValue.insert(transactionValue.begin() + index, value);

	std::cout << transactionDesc[index] << " $" << transactionValue[index] << std::endl;
	index++;
	size++;
	updateFile();

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
	updateFile();

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

static void updateFile()
{
	std::ofstream MyFile("transactions.txt");

	for (int i = 0; i < index; i++)
	{

		MyFile << transactionValue[i] << " " << transactionDesc[i] << "\n";
		std::cout << "Written to file.\n";

	}
	MyFile.close();
}

void loadTransactions()
{
	std::ifstream MyFile("transactions.txt");
	if (!MyFile)
	{
		std::cerr << "Could not open transactions.txt for reading.\n";
		return;
	}

	transactionValue.clear();
	transactionDesc.clear();
	index = 0;
	size = 0;

	double value;
	std::string desc;

	while (MyFile >> value)
	{
		std::getline(MyFile >> std::ws, desc);
		transactionValue.push_back(value);
		transactionDesc.push_back(desc);
		index++;
		size++;
	}

	MyFile.close();
}