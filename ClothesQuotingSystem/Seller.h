#pragma once
#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>

class Quote;

class Seller
{
private:
	const std::string* name;
	const std::string* lastname;
	const int* sellerCode;
	std::vector<Quote*> quotesRecord;

public:
	Seller();
	~Seller();
	void quoteProduct(int& clothes);
	std::string getSellerName();
	const int* getSellerCode();
	std::string parseNum(int value);
};
#endif // !SELLER_H
