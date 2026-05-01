#include <sstream>
#include <iostream>
#include <fstream>
#include "FinanceManager.h"

void FinanceManager::addTransaction(const Transaction& transaction) {
	transactions.push_back(transaction);
}

void FinanceManager::printAllTransactions() const {
	for (size_t i = 0; i < transactions.size(); i++) {
		const Transaction& t = transactions[i];

		std::cout << "Index: " << i << std::endl;
		std::cout << "Anount: " << t.getAmount() << std::endl;
		std::cout << "Category: " << t.getCategory() << std::endl;
		std::cout << "Type: " << t.getType() << std::endl;
		std::cout << "Description: " << t.getDescription() << std::endl;
		std::cout << "Date: " << t.getDate() << std::endl;
		std::cout << "------------------" << std::endl;
	}
}

void FinanceManager::showBalance() const {
	double income = 0.0;
	double expense = 0.0;

	for (const Transaction& t : transactions) {
		if (t.getType() == "income") {
			income += t.getAmount();
		}
		else if (t.getType() == "expense") {
			expense += t.getAmount();
		}
	}

	std::cout << "\n=== Balance Summary ===\n";
	std::cout << "Total Income: " << income << std::endl;
	std::cout << "Total Expense: " << expense << std::endl;
	std::cout << "Current Balance: " << income - expense << std::endl;
}

void FinanceManager::filterByCategory(const std::string& category) const {
	bool found = false;

	for (const Transaction& t : transactions) {
		if (t.getCategory() == category) {
			std::cout << "Amount: " << t.getAmount() << std::endl;
			std::cout << "Category: " << t.getCategory() << std::endl;
			std::cout << "Type: " << t.getType() << std:: endl;
			std::cout << "Description: " << t.getDescription() << std::endl;
			std::cout << "Date: " << t.getDate() << std::endl;
			std::cout << "-------------------" << std::endl;

			found = true;
		}
	}

	if (!found) {
		std::cout << "No transactions found for category: " << category << std::endl;
	}
}

void FinanceManager::deleteTransaction(int index) {
	if (index < 0 || index >= transactions.size()) {
		std::cout << "Invalid transaction index." << std::endl;
	}

	transactions.erase(transactions.begin() + index);

	saveToFile();

	std::cout << "Transaction deleted successfully." << std::endl;
}

void FinanceManager::showMonthlyStatus(const std::string& month) const {
	double income = 0.0;
	double expense = 0.0;

	for (const Transaction& t : transactions) {
		std::string date = t.getDate();

		std::string transactionMonth = date.substr(5, 2);

		if (transactionMonth == month) {
			if (t.getType() == "income") {
				income += t.getAmount();
		}
			else if (t.getType() == "expense") {
				expense += t.getAmount();
			}
	        }
        }
	
	std::cout << "\n=== Monthly Status (" << month << ") ===\n";
	std::cout << "Income: " << income << std::endl;
	std::cout << "Expense: " << expense << std::endl;
	std::cout << "Balance: " << income - expense << std::endl;
}

void FinanceManager::saveToFile() const {
	std::ofstream file("transactions.txt");

	for (const Transaction& t : transactions) {
		file << t.getAmount() << ","
		     << t.getCategory() << ","
		     << t.getType() << ","
		     << t.getDescription() << ","
		     << t.getDate() << "\n";
	}
	
	file.close();
}

void FinanceManager::loadFromFile() {
	std::ifstream file("transaction.txt");

	std::string line;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

	        std::string amountStr;
	        std::string category;
	        std::string type;
	        std::string description;
	        std::string date;

		std::getline(ss, amountStr, ',');
		std::getline(ss, category, ',');
		std::getline(ss, type, ',');
		std::getline(ss, description, ',');
		std::getline(ss, date, ',');

		double amount = std::stod(amountStr);

		Transaction t(amount, category, type, description, date);
		transactions.push_back(t);

	}

	file.close();
}
