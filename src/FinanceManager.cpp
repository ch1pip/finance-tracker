#include <iostream>
#include <fstream>
#include "FinanceManager.h"

void FinanceManager::addTransaction(const Transaction& transaction) {
	transactions.push_back(transaction);
}

void FinanceManager::printAllTransactions() const {
	for (const Transaction& t : transactions) {
		std::cout << "Anount: " << t.getAmount() << std::endl;
		std::cout << "Category: " << t.getCategory() << std::endl;
		std::cout << "Type: " << t.getType() << std::endl;
		std::cout << "Description: " << t.getDescription() << std::endl;
		std::cout << "Date: " << t.getDate() << std::endl;
		std::cout << "------------------" << std::endl;
	}
}

void FinanceManager::saveToFile() const {
	std::ofstream file("transactions.txt");

	for (const Transaction& t : transactions) {
		file << t.getAmount() << " "
		     << t.getCategory() << " "
		     << t.getType() << " "
		     << t.getDescription() << " "
		     << t.getDate() << "\n";
	}
	
	file.close();
}

void FinanceManager::loadFromFile() {
	std::ifstream file("transaction.txt");

	double amount;
	std::string category;
	std::string type;
	std::string description;
	std::string date;

	while (file >> amount >> category >> type >> description >> date) {
		Transaction t(amount, category, type, description, date);
		transactions.push_back(t);
	}

	file.close();
}
