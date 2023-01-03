#include "Seller.h"
#include "Quote.h"
#include "Store.h"
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Quote>> quotesRecord_2;
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

#pragma region ACTIONS

void Seller::quoteProduct(int& clothes, int units)
{
	//std::unique_ptr<Quote> quote(new Quote(clothes, this));
	auto quote = std::make_shared<Quote>(clothes, this);

	//Quote* quote = new Quote(clothes, this);

	quote->calculate(units, this);
	quotesRecord_2.push_back(quote);

	//return result;
}

#pragma endregion

#pragma region SETTERS

void Seller::setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality)
{
	sellerStore->setClothesPreferences(clothesType, alternative1, alternative2, quality);
}

void Seller::setUnitsAndQuote(int& clothes, int units, double quote)
{
	sellerStore->setUnitsAndQuote(clothes, units, quote); // Units are required to rest them from the stock avaible
	quoteProduct(clothes, units); // Units are required to make the correct quote // Returns the resu
}

#pragma endregion

#pragma region GETTERS

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

std::string Seller::getQuoteInfo(int choose)
{
	return quotesRecord_2.back()->getQuoteInformation(choose);
}

double Seller::getUnitPrice()
{
	return sellerStore->getUnitPrice();
}

#pragma endregion

void Seller::getQuoteRecord()
{
	std::vector<std::string> quoteInfoVec = quotesRecord_2.back()->getAllQuoteInfo();
	std::string info[6];
	int counter = 0;

	for (auto itr = quotesRecord_2.rbegin(); itr != quotesRecord_2.rend(); itr++)
	{
		std::cout << "PROBANDO IMPRESION DE DATOS DE COTIZACION" << std::endl;
		// this throws me an error // Trying to get al the info for each clothes quoted
		/*for (auto itr = quoteInfoVec.cbegin(); itr != quoteInfoVec.cend(); itr++)
		{
			info[counter] = quoteInfoVec.at(counter);
			std::cout << info[counter] << std::endl;
			counter++;
		}
		*/
	}
}

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}