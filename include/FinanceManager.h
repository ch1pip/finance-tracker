#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include <vector>
#include "Transaction.h"

class FinanceManager {
private:
	std::vector<Transaction> transactions;

public:
	void addTransaction(const Transaction& transaction);
	void printAllTransactions() const;
	void saveToFile() const;
	void loadFromFile();
	void showBalance() const;
};

#endif
