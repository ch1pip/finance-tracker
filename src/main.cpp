#include <iostream>
#include <string>
#include "FinanceManager.h"

int main() {
	FinanceManager manger;
	int choice;

	while (true) {
		std::cout << "\n=== Personal Finance Tracker ===\n";
		std::cout << "1. Add transaction\n";
		std::cout << "2. Show all transaction\n";
		std::cout << "3. Exit\n";
		std::cout << "Choose option: ";
		std::cin >> choice;


		if (choice == 1) {
			double amount;
			std::string category;
			std::string type;
			std::string description;
			std::string date;

			std::cout << "Enter amount: ";
			std::cin >> amount;

			std::cout << "Enter category: ";
			std::cin >> category;

			std::cout << "Enter type (income/expense): ";
			std::cin >> type;

			std::cout << "Enter description: ";
			std::cin.ignore();
			std::getline(std::cin, description);

			std::cout << "Enter date (YYYY-MM-DD): ";
			std::getline(std::cin, date);

			Transaction newTransaction(
					amount, 
					category, 
					type, 
					description, 
					date
			);

			manger.addTransaction(newTransaction);

			std::cout << "Transaction added successfully.\n";
		}

		else if (choice == 2) {
			manger.printAllTransactions();
		}

		else if (choice == 3) {
			std::cout << "Eciting program...\n";
			break;
		}

		else {
			std::cout << "Invalid option. Try again.\n";
		}
	}
        
	return 0;
}
