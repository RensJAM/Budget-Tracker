#include <iostream>
#include <string>

#include "Calculations.h"

int main()
{

	int choice;
	double expens;
	std::string desc;
	int sel;

	while (true)
	{
	std::cout << "1. Add a new transaction\n"
			<< "2. View all transactions\n"
			<< "3. Remove a transaction\n"
			<< "4. Show summary statistics\n"
			<< "5. Exit programm\n";
	std::cin >> choice;

	switch(choice)
	{
	case 1: {
		std::cin.ignore();
		std::cout << "What is the description of your transaction?: ";
		std::getline(std::cin, desc);
		std::cout << "What is the value of your transaction?: ";
		std::cin >> expens;
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
		std::cin >> sel;
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