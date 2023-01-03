#include "Seller.h"
#include "Quote.h"
#include "Store.h"
#include <iostream>
#include <sstream>

std::vector<std::shared_ptr<Quote>> quotesRecord;
int Quote::quoteId = 000;

Seller::Seller()
{
	std::cout << "Seller name: ";
	std::getline(std::cin, name);
	std::cout << "Lastname: ";
	std::getline(std::cin, lastname);
	std::cout << "Seller code: ";
	std::cin >> sellerCode;
	std::cin.get();

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
	// Creates a new quote and executes the constructor through a smart shared pointer
	auto quote = std::make_shared<Quote>(clothes, this);

	quote->calculate(units, this);
	quotesRecord.push_back(quote);
}

#pragma endregion

#pragma region SETTERS

void Seller::setClothesSpecifications(int clothesType, int alternative1, int alternative2, int quality)
{
	sellerStore->setClothesPreferences(clothesType, alternative1, alternative2, quality);
}

void Seller::setUnitsAndQuote(int& clothes, int units, double quote)
{
	sellerStore->setUnitsAndQuote(units, quote); // Units are required to rest them from the stock avaible
	quoteProduct(clothes, units); // Units are required to make the correct quote // Returns the resu
}

#pragma endregion

#pragma region GETTERS

std::string Seller::getSellerStore()const
{
	return sellerStore->getStoreInfo(); // returns the store name and address
}

std::string Seller::getSellerName()const
{
	return name + " " + lastname;
}

int Seller::getSellerCode() const
{
	return sellerCode;
}

// Gets values stored in the store obj and the clothes obj for further use in the Quote obj. They are needed to make counts
void Seller::getClothesSpecifications(double& initialPrice, bool& alternative1, bool& alternative2, bool& quality) // This is for the shirt, because it has 2 alterations in his type
{
	initialPrice = sellerStore->getUnitPrice();
	sellerStore->getClothesSpecs(alternative1, alternative2, quality);
}
void Seller::getClothesSpecifications(double& initialPrice, bool& alternative1, bool& quality) // OVERLOAD/SOBRECARGA --> this overload is for Pants.
{
	initialPrice = sellerStore->getUnitPrice();
	sellerStore->getClothesSpecs(alternative1, quality);
}

int Seller::getClothesStockAmount(int clothesType) // returns the stock depending on the type of clothes
{
	return sellerStore->getClothesStock(clothesType);
}

std::string Seller::getQuoteInfo(int choose) // Returns specific info from the quote to show a final receipt in View.cpp
{
	return quotesRecord.back()->getQuoteInformation(choose);
}

double Seller::getUnitPrice()
{
	return sellerStore->getUnitPrice();
}

void Seller::getQuoteRecord() // I try to get every info from the quotation, save it and iterate it but it didnt work, maybe its better if I try to make a dynamic pile list
{
	quoteInfoVec = quotesRecord.back()->getAllQuoteInfo();
	std::string info[50];
	int counter = 0;

	for (auto itr = quotesRecord.cbegin(); itr != quotesRecord.cend(); itr++)
	{
		// this throws me an error // Trying to get al the info for each clothes quoted
		/*
		for (auto itr = quoteInfoVec.cbegin(); itr != quoteInfoVec.cend(); itr++)
		{
			info[counter] = quoteInfoVec.at(counter); // This is the cause --> info tries to access to an inexisting vector index.
			std::cout << info[counter] << std::endl;
			counter++;
		}
		*/
	}
}

#pragma endregion

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}