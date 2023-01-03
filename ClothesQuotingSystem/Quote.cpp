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
		if (_shortSleeve) // Manga corta vale un -10%
		{
			_initialPrice -= (_initialPrice * 10) / 100;
			str += " - Short sleeve";
		}
		if (_mandarinCollar)
		{
			_initialPrice += (_initialPrice * 3) / 100; // Cuello mao es un 3% mas cara
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
			_initialPrice -= (_initialPrice * 12) / 100; // Precio es -12% si es chupin
			str += " - Skinny pants";
		}
		else if (!_skinny)
			str += " - Regular pants";
	}

	// CLOTHES QUALITY PRICE CHANGERS
	if (premium) // Premium
	{
		quoteOutcome += (_initialPrice * 30) / 100; // Precio final es +30% si es calidad premium
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

std::string Quote::getQuoteInformation(int choose)
{
	if (choose == 1)
		return parseNum(quoteId); // Hace falta que retorne esto al ser static?
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

std::vector<std::string> Quote::getAllQuoteInfo()
{
	std::vector<std::string> allQuoteInfo;

	allQuoteInfo.push_back(parseNum(quoteId));
	allQuoteInfo.push_back(quoteTime);
	allQuoteInfo.push_back(parseNum(sellerCode));
	allQuoteInfo.push_back(quotedClothes);
	allQuoteInfo.push_back(parseNum(quotedUnits));
	allQuoteInfo.push_back(parseNum(quoteOutcome));

	/*
	allQuoteInfo[0] = parseNum(quoteId);
	allQuoteInfo[1] = quoteTime;
	allQuoteInfo[2] = parseNum(sellerCode);
	allQuoteInfo[3] = quotedClothes;
	allQuoteInfo[4] = parseNum(quotedUnits);
	allQuoteInfo[5] = parseNum(quoteOutcome);
	*/

	return allQuoteInfo;
}

std::string Quote::parseNum(double value)
{
	std::ostringstream aux;
	aux << value;
	return aux.str();
}