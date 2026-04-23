#include "FinanceManager.h"

int main() {
	FinanceManager manager;

	Transaction t1(100.0, "Food", "expense", "Lunch", "2026-04-23");
	Transaction t2(2500.0, "Salary", "income", "Monthly salary", "2026-04-02");

	manager.addTransaction(t1);
	manager.addTransaction(t2);

	manager.printAllTransactions();

	return 0;
}
