#pragma once
#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <ctime>

class Seller;

class Quote
{
private:
	Seller* seller;

	static int quoteId;
	time_t quoteTime;
	const int* sellerCode; // error
	std::string quotedClothes;
	int quotedUnits;
	double quoteOutcome;

public:
	Quote(int& clothes);
	~Quote();
	void calculate();
};

#endif // !QUOTE_H
