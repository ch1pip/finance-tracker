#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
	double amount;
	std::string category;
	std::string type;
	std::string description;
	std::string date;

public:
	Transaction(double amount,
		    const std::string& category, 
		    const std::string& type, 
		    const std::string& description, 
		    const std::string& date);

	double getAmount() const;
	std::string getCategory() const;
	std::string getType() const;
	std::string getDescription() const;
	std::string getDate() const;
};

#endif
