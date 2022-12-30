#include "Store.h"
#include "Clothes.h"
#include <iostream>

Store::Store()
{
	std::cout << "Please, introduce your store name: ";
	std::getline(std::cin, storeName);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Store address: ";
	std::getline(std::cin, address);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	clothesList.push_back(shirt);
	clothesList.push_back(pants);
}

Store::~Store()
{
	std::cout << "Store closed" << std::endl;
}

std::string Store::getStoreInfo() const
{
	return storeName + " | " + address;
}