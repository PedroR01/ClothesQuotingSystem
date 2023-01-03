#pragma once
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <vector>

class Seller;

class Quote
{
private:

	static int quoteId;
	char quoteTime[26];
	int sellerCode;
	std::string quotedClothes;
	int quotedUnits;
	double quoteOutcome;

public:
	Quote(int& clothes, Seller* accessCode);
	~Quote();

	void calculate(int& _quotedUnits, Seller* m_seller);
	std::string getQuoteInformation(int choose);
	std::vector<std::string> getAllQuoteInfo();
	std::string parseNum(double value);
};

#endif // !QUOTE_H
