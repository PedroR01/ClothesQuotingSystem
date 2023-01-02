#include "Seller.h"
#include "Quote.h"
#include "Store.h"
#include <iostream>
#include <sstream>

//#define SECTION "---------------------------------------"
int Quote::quoteId = 000;

Seller::Seller()
{
	std::cout << "Seller name: ";
	std::getline(std::cin, name);
	std::cout << "Lastname: ";
	std::getline(std::cin, lastname);
	std::cout << "Seller code: ";
	std::cin >> sellerCode;

	sellerStore = new Store();
}

Seller::~Seller()
{
	delete sellerStore;
	std::cout << "\nSeller went home! Please come back tomorrow" << std::endl;
}

void Seller::quoteProduct(int& clothes, int units)
{
	std::unique_ptr<Quote> quote(new Quote(clothes, this));
	//Quote* quote = new Quote(clothes, this);

	//double result = quote->calculate(units, this);
	quote->calculate(units, this);
	quotesRecord.push_back(*quote); // Asi o con el agregado del "*" o "&"

	//delete quote; // Esto borra la cotizacion del historial tambien?

	//return result;
}

std::string Seller::getSellerStore()const
{
	return sellerStore->getStoreInfo();
}

std::string Seller::getSellerName()const
{
	return name + " " + lastname;
}

int Seller::getSellerCode() const
{
	return sellerCode;
}

void Seller::setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality)
{
	sellerStore->setClothesPreferences(clothesType, alternative1, alternative2, quality);
}

void Seller::getClothesSpecifications(double& initialPrice, bool& alternative1, bool& alternative2, bool& quality)
{
	initialPrice = sellerStore->getUnitPrice();
	sellerStore->getClothesSpecs(alternative1, alternative2, quality);
}
void Seller::getClothesSpecifications(double& initialPrice, bool& alternative1, bool& quality) // OVERLOAD/SOBRECARGA
{
	initialPrice = sellerStore->getUnitPrice();
	sellerStore->getClothesSpecs(alternative1, quality);
}

int Seller::getClothesStockAmount(int clothesType)
{
	return sellerStore->getClothesStock(clothesType);
}

void Seller::setUnitsAndQuote(int& clothes, int units, double quote)
{
	sellerStore->setUnitsAndQuote(clothes, units, quote); // Units are required to rest them from the stock avaible
	quoteProduct(clothes, units); // Units are required to make the correct quote // Returns the resu
}

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}

std::string Seller::getQuoteInfo(int choose)
{
	return quotesRecord.back().getQuoteInformation(choose);
}

double Seller::getUnitPrice()
{
	return sellerStore->getUnitPrice();
}