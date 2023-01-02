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

	if (quotedClothes == "Shirt")
	{
		_seller->getClothesSpecifications(_initialPrice, _shortSleeve, _mandarinCollar, premium);

		// SHIRT PRICE CHANGERS
		if (_shortSleeve)
			_initialPrice -= (_initialPrice * 10) / 100; // Manga corta vale un -10%
		if (_mandarinCollar)
			_initialPrice += (_initialPrice * 3) / 100; // Cuello mao es un 3% mas cara

		// if both booleans are false, the initial price stays the same --> shirt will be longSleeve & regularCollar
	}
	else if (quotedClothes == "Pants")
	{
		_seller->getClothesSpecifications(_initialPrice, _skinny, premium);
		std::cout << "---------------------\n----------------\n" << _initialPrice << " | " << _skinny << " | " << premium << std::endl;
		// PANTS PRICE CHANGERS
		if (_skinny)
			_initialPrice -= (_initialPrice * 12) / 100; // Precio es -12% si es chupin
	}

	// CLOTHES QUALITY PRICE CHANGERS
	if (premium) // Premium
		quoteOutcome += (_initialPrice * 30) / 100; // Precio final es +30% si es calidad premium
	else // Standard --> Doesn´t affect the final quote value
		quoteOutcome = _initialPrice;

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

std::string Quote::parseNum(double value)
{
	std::ostringstream aux;
	aux << value;
	return aux.str();
}