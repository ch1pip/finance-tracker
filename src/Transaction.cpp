#include "Transaction.h"

Transaction::Transaction(double amount,
		         const std::string& category, 
			 const std::string& type, 
			 const std::string& description, 
			 const std::string& date) {
	this->amount = amount;
	this->category = category;
	this->type = type;
	this->description = description;
	this->date = date;
}

double Transaction::getAmount() const {
	return amount;
}

std::string Transaction::getCategory() const {
	return category;
}

std::string Transaction::getType() const {
	return type;
}

std::string Transaction::getDescription() const {
	return description;
}

std::string Transaction::getDate() const {
	return date;
} 
