#pragma once
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <ctime>

class Seller;

class Quote
{
private:

	static int quoteId;
	time_t quoteTime;
	int sellerCode;
	std::string quotedClothes;
	int quotedUnits;
	double quoteOutcome;

public:
	Quote(int& clothes, Seller* accessCode);
	~Quote();
	int calculate(int& _quotedUnits);
};

#endif // !QUOTE_H
