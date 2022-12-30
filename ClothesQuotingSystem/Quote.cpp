#include "Quote.h"
#include "Seller.h"
#include <iostream>

Quote::Quote(int& clothes, Seller* accessCode)
{
	quoteId++;
	quoteTime = time(0);
	char qt[26];
	ctime_s(qt, sizeof qt, &quoteTime);
	sellerCode = accessCode->getSellerCode();

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

int Quote::calculate(int& _quotedUnits)
{
	// SHIRT PRICE CHANGERS
	// longSleeve + regularCollar = initialQuote // Precio normal
	// A. shortSleeve = (initialQuote*10) / 100 // Manga corta vale un -10%
	// B. mandarinCollar = initialQuote += (initialQuote*3) / 100 // Cuello mao es un 3% mas cara
	// shortSleeve + mandarinCollar = B - A.

	// PANTS PRICE CHANGERS
	// skinny = (initialQuote*12) / 100 // Precio es -12% si es chupin

	// CLOTHES QUALITY PRICE CHANGERS
	// normal = quoteOutcome // Precio final se mantiene luego de las especificaciones anteriores
	// premium = quoteOutcome = (quoteOutcome*30) / 100 // Precio final es +30% si es calidad premium
	return quoteOutcome;
}