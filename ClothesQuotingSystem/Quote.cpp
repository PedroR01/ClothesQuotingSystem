#include "Quote.h"
#include "Seller.h"
#include <iostream>
#include <ctime>
#include <sstream>

Quote::Quote(int& clothes, Seller* _seller)
{
	quoteId++;
	time_t qt = time(0);
	ctime_s(quoteTime, sizeof quoteTime, &qt);
	sellerCode = _seller->getSellerCode();

	if (clothes == 1)
		quotedClothes = "Shirt";
	else
		quotedClothes = "Pants";

	quotedUnits = 0;
	quoteOutcome = 0;
}

Quote::~Quote()
{
	//this->quoteOutcome;
}

void Quote::calculate(int& _quotedUnits, Seller* _seller)
{
	bool _shortSleeve, _mandarinCollar, _skinny, premium;
	double _initialPrice = 0;
	quotedUnits = _quotedUnits;
	quoteOutcome = 0;

	std::string str = quotedClothes;
	if (str.find("Shirt") != std::string::npos)
	{
		_seller->getClothesSpecifications(_initialPrice, _shortSleeve, _mandarinCollar, premium);

		// SHIRT PRICE CHANGERS
		if (_shortSleeve) // Short sleeve -10% to quote
		{
			_initialPrice -= (_initialPrice * 10) / 100;
			str += " - Short sleeve";
		}
		if (_mandarinCollar)
		{
			_initialPrice += (_initialPrice * 3) / 100; // Mandarin collar +3% to the quote
			str += " - Mandarin collar";
		}
		if (!_shortSleeve)
			str += " - Long sleeve";
		if (!_mandarinCollar)
			str += " - Normal collar";

		// if both booleans are false, the initial price stays the same --> shirt will be longSleeve & regularCollar
	}
	else if (str.find("Pants") != std::string::npos)
	{
		_seller->getClothesSpecifications(_initialPrice, _skinny, premium);
		// PANTS PRICE CHANGERS
		if (_skinny)
		{
			_initialPrice -= (_initialPrice * 12) / 100; // Quote -12% if they are skinny pants
			str += " - Skinny pants";
		}
		else if (!_skinny)
			str += " - Regular pants";
	}

	// CLOTHES QUALITY PRICE CHANGERS
	if (premium) // Premium
	{
		quoteOutcome += (_initialPrice * 30) / 100; // Quote +30% if his quality is premium
		str += " - Premium";
	}
	else // Standard --> Doesn´t affect the final quote value
	{
		quoteOutcome = _initialPrice;
		str += " - Standard";
	}

	quotedClothes = str;
	quoteOutcome = quoteOutcome * quotedUnits; // FINAL QUOTE * UNITS QUOTED
}

std::string Quote::getQuoteInformation(int choose) // returns single information
{
	if (choose == 1)
		return parseNum(quoteId);
	else if (choose == 2)
		return quoteTime;
	else if (choose == 3)
		return parseNum(sellerCode);
	else if (choose == 4)
		return quotedClothes;
	else if (choose == 5)
		return parseNum(quotedUnits);
	else if (choose == 6)
		return parseNum(quoteOutcome);
}

std::vector<std::string> Quote::getAllQuoteInfo() // returns all info in a single vector
{
	std::vector<std::string> allQuoteInfo;

	allQuoteInfo.push_back(parseNum(quoteId));
	allQuoteInfo.push_back(quoteTime);
	allQuoteInfo.push_back(parseNum(sellerCode));
	allQuoteInfo.push_back(quotedClothes);
	allQuoteInfo.push_back(parseNum(quotedUnits));
	allQuoteInfo.push_back(parseNum(quoteOutcome));

	return allQuoteInfo;
}

std::string Quote::parseNum(double value)
{
	std::ostringstream aux;
	aux << value;
	return aux.str();
}