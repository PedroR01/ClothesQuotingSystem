#include "Store.h"
#include "Clothes.h"
#include "Shirt.h"
#include "Pants.h"
#include <iostream>

std::vector<std::shared_ptr<Clothes>> clothesList_2;

Store::Store()
{
	std::cout << "Please, introduce your store name: ";
	std::getline(std::cin, storeName);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BUG: No se imprime en pantalla

	std::cout << "Store address: ";
	std::getline(std::cin, address);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BUG: Hay que apretar 2 veces enter para introducir el dato

	/*
	Shirt* shirtsToSell = new Shirt();
	Pants* pantsToSell = new Pants();
	shirtsToSell = dynamic_cast<Shirt*>(shirtsToSell);
	pants = dynamic_cast<Pants*>(pantsToSell);
	clothesList.push_back(shirtsToSell);
	clothesList.push_back(pantsToSell);
	*/
	/*
	_shirt = new Shirt();
	_pants = new Pants();

	clothesList.push_back(_shirt);
	clothesList.push_back(_pants);
	*/

	auto theShirt = std::make_shared<Shirt>();
	auto thePants = std::make_shared<Pants>();

	clothesList_2.push_back(theShirt);
	clothesList_2.push_back(thePants);
}

Store::~Store()
{
	std::cout << "Store closed" << std::endl;
}

std::string Store::getStoreInfo() const
{
	return storeName + " | " + address;
}

void Store::getClothesInfo()
{
	if (!clothesList.empty())
	{
		for (const auto& clothes : clothesList_2)
		{
			std::cout << clothes->derivedName << " - " << clothes->stockAmount << std::endl;
		}
	}
	else
		std::cout << "No clothes to sell" << std::endl;
}

void Store::setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality) // Para la variable alternativa1 y 2 podria ser simplemente un array de alternativas? // Alternativa: puede ser hacer una lista generica
{
	int _alternative[2];

	if (clothesType == 1)
	{
		if (clothesList_2.front().get()->derivedName != "Shirt")
		{
			int counter = 0;
			for (auto itr = clothesList_2.cbegin(); itr != clothesList_2.cend(); itr++) // Searchs for the clothes specified before
			{
				if (clothesList_2.at(counter).get()->derivedName == "Shirt")
				{
					clothesList_2.at(counter).swap(clothesList_2.front());
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
		if (clothesList_2.front().get()->derivedName != "Pants")
		{
			int counter = 0;
			for (auto itr = clothesList_2.cbegin(); itr != clothesList_2.cend(); itr++) // Searchs for the clothes specified before
			{
				if (clothesList_2.at(counter).get()->derivedName == "Pants")
				{
					clothesList_2.at(counter).swap(clothesList_2.front());
				}
				counter++;
			}
		}
		// PANTS SPECIFICATIONS FOR FURTHER QUOTE
		_alternative[0] = alternative1;
		_alternative[1] = alternative2;
	}

	clothesList_2.front().get()->setDerivedOptions(_alternative);

	if (quality == 1)
		clothesList_2.front().get()->quality = 1; // Standard
	else
		clothesList_2.front().get()->quality = 2; // Premium

	/*
	if (clothesType == 1)
	{
		Shirt* _shirt2 = dynamic_cast<Shirt*>(clothesList.front());
		clothesList.erase(clothesList.begin());

		// SHIRT SPECIFICATIONS FOR FURTHER QUOTE
		if (alternative1 == 1)
			_shirt2->shortSleeve = true;
		else
			_shirt2->shortSleeve = false; // longSleeve

		if (alternative2 == 1)
			_shirt2->mandarinCollar = true;
		else
			_shirt2->mandarinCollar = false; // regularCollar

		if (quality == 1)
			_shirt2->quality; // Standard - Falta especificar, no deberia ser string creo
		else
			_shirt2->quality; // Premium

		clothesList.insert(clothesList.begin(), _shirt2);
	}
	// Missing behaviour for pants
	*/

	// Trying to change data with local object and downcasting
	/*
	if (clothesType == 1)
	{
		Shirt* _shirt = new Shirt();
		_shirt = dynamic_cast<Shirt*>(clothesList.front());
		clothesList.erase(clothesList.begin());

		// SHIRT SPECIFICATIONS FOR FURTHER QUOTE
		if (alternative1 == 1)
			_shirt->shortSleeve = true;
		else
			_shirt->shortSleeve = false;

		if (alternative2 == 1)
			_shirt->mandarinCollar = true;
		else
			_shirt->mandarinCollar = false;

		if (alternative1 == 1 && alternative2 == 1)
			std::cout << "TODO TRUE Y EN ORDEN" << std::endl;
		else
			std::cout << "TODO FALSE" << std::endl;

		clothesList.insert(clothesList.begin(), _shirt);
	}
	else
	{
		Pants* _pants = new Pants();
		_pants = dynamic_cast<Pants*>(clothesList.front());
		clothesList.erase(clothesList.begin());

		// SHIRT SPECIFICATIONS FOR FURTHER QUOTE
		if (alternative1 == 1)
			_pants->skinny = true;
		else
			_pants->skinny = false;

		if (alternative1 == 1)
			std::cout << "TODO TRUE Y EN ORDEN" << std::endl;
		else
			std::cout << "TODO FALSE" << std::endl;

		clothesList.insert(clothesList.begin(), _pants);
	}
	*/
}

int Store::getClothesStock(int clothesType)
{
	return clothesList_2.front().get()->stockAmount;
}

void Store::setUnitsAndQuote(int& clothes, int units, double quote) // clothes deberia ser borrado
{
	clothesList_2.front().get()->stockAmount -= units;
	clothesList_2.front().get()->unitPrice = quote;

	/*
	if (clothes == 1) //Shirt
	{
		clothesList_2.front().get()->stockAmount -= units;
		clothesList_2.front().get()->unitPrice = quote;
	}
	else // Pants
	{
		clothesList_2.back().get()->stockAmount -= units;
		clothesList_2.back().get()->unitPrice = quote;
	}
	*/
	/*
	Shirt* _shirt2 = dynamic_cast<Shirt*>(clothesList.front());
	_shirt2->stockAmount -= units;
	_shirt2->unitPrice = quote;
	*/
	/*
	_shirt = dynamic_cast<Shirt*>(clothesList.front());
	clothesList.erase(clothesList.begin());
	clothesList.insert(clothesList.begin(), _shirt);
	*/
}

double Store::getUnitPrice()
{
	// The last clothes to get quoted is always at the front of the Vector --> see setClothesPreferences()
	return clothesList_2.front().get()->unitPrice;
}

void Store::getClothesSpecs(bool& alternative1, bool& alternative2, bool& quality)
{
	// Shirt for now
	int whatShirt = clothesList_2.front().get()->getDerivedClothes();

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

	if (clothesList_2.front().get()->quality == 1)
		quality = false; // Standard
	else
		quality = true; // Premium
}
void Store::getClothesSpecs(bool& alternative1, bool& quality) // OVERLOAD/SOBRECARGA
{
	// Pants for now
	int whatPants = clothesList_2.front().get()->getDerivedClothes();

	if (whatPants == 1) // normal
		alternative1 = false;
	else
		alternative1 = true;

	if (clothesList_2.front().get()->quality == 1)
		quality = false; // Standard
	else
		quality = true; // Premium
}