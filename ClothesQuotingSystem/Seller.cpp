#include "Seller.h"
#include "Quote.h"
#include <iostream>
#include <sstream>

//#define SECTION "---------------------------------------"
int Quote::quoteId = 000;

Seller::Seller()
{
	std::string _name;
	std::string _lastname;
	int _sellerCode;

	std::cout << "Seller name: ";
	std::getline(std::cin, _name);
	std::cout << "Lastname: ";
	std::getline(std::cin, _lastname);
	std::cout << "Seller code: ";
	std::cin >> _sellerCode;

	this->name = &_name;
	this->lastname = &_lastname;
	this->sellerCode = &_sellerCode;
}

Seller::~Seller()
{
	std::cout << "\nSeller went home! Please come back tomorrow" << std::endl;
}

void Seller::quoteProduct(int& clothes)
{
	Quote* quote = new Quote(clothes);

	quotesRecord.push_back(quote); // Asi o con el agregado del "*" o "&"

	delete quote;
}

/// ------ GETTERS error de acceso nullptr cuando se quieren acceder externamente
std::string Seller::getSellerName()
{
	return *name + " " + *lastname;
}

const int* Seller::getSellerCode()
{
	return sellerCode;
}
/// ------

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}