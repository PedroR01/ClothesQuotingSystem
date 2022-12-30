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

void Seller::quoteProduct(int& clothes)
{
	Quote* quote = new Quote(clothes, this);

	quotesRecord.push_back(quote); // Asi o con el agregado del "*" o "&"

	delete quote; // Esto borra la cotizacion del historial tambien?
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

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}