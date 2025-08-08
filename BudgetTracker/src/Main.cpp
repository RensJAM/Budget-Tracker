#include <iostream>
#include <string>

#include "Calculations.h"

int main()
{

	static int choice;
	static double expens;
	static std::string desc;
	static int sel;

	loadTransactions();

	while (true)
	{
	std::cout << "1. Add a new transaction\n"
			<< "2. View all transactions\n"
			<< "3. Remove a transaction\n"
			<< "4. Show transactions summary\n"
			<< "5. Exit programm\n";
	if (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Incorrect entry. Try again: \n";
	}

	switch(choice)
	{
	case 1: {
		std::cin.ignore();
		std::cout << "What is the description of your transaction?: ";
		std::getline(std::cin, desc);
		std::cout << "What is the value of your transaction?: ";
		if (!(std::cin >> expens))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Incorrect entry. Try again: \n";
		}
		addTransaction(desc, expens);
		break;
	}
	case 2: {
		showTransactions();
		break;
	}
	case 3: {
		showTransactions();
		std::cout << "Enter number to remove: \n";
		if (!(std::cin >> sel))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Incorrect entry. Try again: \n";
		}
		removeTransaction(sel);
		break;
	}
	case 4: {
		showSum();
		break;
	}
	case 5: {
		return 0;
	}

	}
	}
	

}