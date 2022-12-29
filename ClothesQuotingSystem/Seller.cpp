#include "Seller.h"
#include "Quote.h"
#include <iostream>
#include <sstream>

#define SECTION "---------------------------------------"

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

	mainMenu();
}

Seller::~Seller()
{
	std::cout << "\nSeller went home! Please come back tomorrow" << std::endl;
}

void Seller::mainMenu()
{
	std::cout << "\nCLOTHES QUOTING SYSTEM  -  MAIN MENU" << std::endl;
	std::cout << SECTION << std::endl;
	std::cout << *name << " " << *lastname << " | " << *sellerCode << std::endl;
	std::cout << SECTION << std::endl;

	sellerOptions();
}

void Seller::sellerOptions()
{
	std::cout << "\nPLEASE SELECT AN OPTION TO CONTINUE:" << std::endl;
	std::cout << "1) Make a quote" << std::endl;
	std::cout << "2) Exit" << std::endl;
	std::cout << "\n";

	int choice;
	std::cin >> choice;

	if (choice == 1)
		quoteMenu();
	else if (choice == 2)
	{
	}
	else
		return;
}

void Seller::quoteMenu()
{
	std::cout << "\nSELECT CLOTHES TO QUOTE:" << std::endl;
	std::cout << "1) Shirt" << std::endl;
	std::cout << "2) Pants" << std::endl;

	int option;
	std::cin >> option;
	quoteProduct(option);

	if (option == 1) // Shirt
	{
		std::cout << "\n" << std::endl;
	}
	else if (option == 2) // Pants
	{
	}
	else
		return;
}

void Seller::quoteProduct(int& clothes)
{
	Quote* quote = new Quote(clothes);

	quotesRecord.push_back(quote); // Asi o con el agregado del "*" o "&"

	delete quote;
}

std::string Seller::getSellerName()
{
	return *name + " " + *lastname;
}

const int* Seller::getSellerCode()
{
	return sellerCode;
}

std::string Seller::parseNum(int value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}