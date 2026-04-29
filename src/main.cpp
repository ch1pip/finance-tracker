#include <iostream>
#include <string>
#include "FinanceManager.h"

int main() {
	FinanceManager manger;
	manger.loadFromFile();

	int choice;

	while (true) {
		std::cout << "\n=== Personal Finance Tracker ===\n";
		std::cout << "1. Add transaction\n";
		std::cout << "2. Show all transaction\n";
		std::cout << "3. Show balance\n";
		std::cout << "4. Filter by category\n";
		std::cout << "5. Delete transaction\n";
		std::cout << "6. Exit\n";
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

			std::cin.ignore();

			std::cout << "Enter category: ";
			std::getline(std::cin, category);

			std::cout << "Enter type (income/expense): ";
			std::getline(std::cin, type);

			std::cout << "Enter description: ";
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
			manger.saveToFile();

			std::cout << "Transaction added successfully.\n";
		}

		else if (choice == 2) {
			manger.printAllTransactions();
		}

		else if (choice == 3) {
			manger.showBalance();
		}

		else if (choice == 4) {
			std::string searchCategory;

			std::cout << "Enter category to search: ";
			std::cin.ignore();
			std::getline(std::cin, searchCategory);

			manger.filterByCategory(searchCategory);
		}

		else if (choice == 5) {
			int index;

			std::cout << "Enter transaction idex to delete: ";
			std::cin >> index;

			manger.deleteTransaction(index);
		}

		else if (choice == 6) {
			std::cout << "Eciting program...\n";
			break;
		}

		else {
			std::cout << "Invalid option. Try again.\n";
		}
	}
        
	return 0;
}
