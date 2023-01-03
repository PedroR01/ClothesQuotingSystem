#include "Store.h"
#include "Clothes.h"
#include "Shirt.h"
#include "Pants.h"
#include <iostream>

std::vector<std::shared_ptr<Clothes>> clothesList;

Store::Store()
{
	std::cout << "Please, introduce your store name: ";
	std::getline(std::cin, storeName);
	std::cout << "Store address: ";
	std::getline(std::cin, address);

	auto theShirt = std::make_shared<Shirt>();
	auto thePants = std::make_shared<Pants>();

	clothesList.push_back(theShirt);
	clothesList.push_back(thePants);
}

Store::~Store()
{
	std::cout << "Store closed" << std::endl;
}

#pragma region SETTERS

// Acording to the values entered from inputs in view.cpp, this method set clothes specification for each case
void Store::setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality)
{
	int _alternative[2];

	if (clothesType == 1)
	{
		if (clothesList.front().get()->derivedName != "Shirt")
		{
			int counter = 0;
			for (auto itr = clothesList.cbegin(); itr != clothesList.cend(); itr++) // Searchs for the clothes specified before (Shirt)
			{
				if (clothesList.at(counter).get()->derivedName == "Shirt")
				{
					clothesList.at(counter).swap(clothesList.front()); // When its found, places it on the front for further uses/setters/getters.
				}
				counter++;
			}
		}
		// SHIRT SPECIFICATIONS FOR FURTHER QUOTE
		_alternative[0] = alternative1;
		_alternative[1] = alternative2;
	}

	else
	{
		if (clothesList.front().get()->derivedName != "Pants")
		{
			int counter = 0;
			for (auto itr = clothesList.cbegin(); itr != clothesList.cend(); itr++) // Same logic as explained before with shirt but now for pants
			{
				if (clothesList.at(counter).get()->derivedName == "Pants")
				{
					clothesList.at(counter).swap(clothesList.front());
				}
				counter++;
			}
		}
		// PANTS SPECIFICATIONS FOR FURTHER QUOTE
		_alternative[0] = alternative1;
		_alternative[1] = alternative2; // This value doesnt matter in Pants
	}

	clothesList.front().get()->setDerivedOptions(_alternative);

	if (quality == 1)
		clothesList.front().get()->quality = 1; // Standard
	else
		clothesList.front().get()->quality = 2; // Premium
}

void Store::setUnitsAndQuote(int units, double quote)
{
	// Always the last type of clothes used/referred is at front of the list
	clothesList.front().get()->stockAmount -= units; // Decrease units from the stock
	clothesList.front().get()->unitPrice = quote; // Establish the initial price per unit
}

#pragma endregion

#pragma region GETTERS

std::string Store::getStoreInfo() const
{
	return storeName + " | " + address;
}

void Store::getClothesInfo() // Only used for debug and check purpose
{
	if (!clothesList.empty())
	{
		for (const auto& clothes : clothesList)
		{
			std::cout << clothes->derivedName << " - " << clothes->stockAmount << std::endl;
		}
	}
	else
		std::cout << "No clothes to sell" << std::endl;
}

int Store::getClothesStock(int clothesType)
{
	return clothesList.front().get()->stockAmount;
}

double Store::getUnitPrice()
{
	// The last clothes to get quoted is always at the front of the Vector --> see setClothesPreferences()
	return clothesList.front().get()->unitPrice;
}

void Store::getClothesSpecs(bool& alternative1, bool& alternative2, bool& quality)
{
	// Shirt for now
	int whatShirt = clothesList.front().get()->getDerivedClothes();

	if (whatShirt == 4) // short & mandarin
	{
		alternative1 = true;
		alternative2 = true;
	}
	else if (whatShirt == 5) // long & mandaring
	{
		alternative1 = false;
		alternative2 = true;
	}
	else if (whatShirt == 6) // short & regular
	{
		alternative1 = true;
		alternative2 = false;
	}
	else if (whatShirt == 7) // long & regular
	{
		alternative1 = false;
		alternative2 = false;
	}

	if (clothesList.front().get()->quality == 1)
		quality = false; // Standard
	else
		quality = true; // Premium
}
void Store::getClothesSpecs(bool& alternative1, bool& quality) // OVERLOAD/SOBRECARGA
{
	// Pants for now
	int whatPants = clothesList.front().get()->getDerivedClothes();

	if (whatPants == 1) // normal
		alternative1 = false;
	else
		alternative1 = true;

	if (clothesList.front().get()->quality == 1)
		quality = false; // Standard
	else
		quality = true; // Premium
}

#pragma endregion