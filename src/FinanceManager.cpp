#include <iostream>
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
