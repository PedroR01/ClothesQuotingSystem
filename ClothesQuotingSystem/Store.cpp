#include "Store.h"
#include "Clothes.h"
#include "Shirt.h"
#include "Pants.h"
#include <iostream>

Store::Store()
{
	std::cout << "Please, introduce your store name: ";
	std::getline(std::cin, storeName);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BUG: No se imprime en pantalla

	std::cout << "Store address: ";
	std::getline(std::cin, address);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // BUG: Hay que apretar 2 veces enter para introducir el dato

	//Shirt* shirtsToSell = new Shirt();
	//Pants* pantsToSell = new Pants();

	shirt = new Clothes();
	pants = new Clothes();

	_shirt = new Shirt();
	_pants = new Pants();

	//shirtsToSell = dynamic_cast<Shirt*>(shirt);
	//pants = dynamic_cast<Pants*>(pantsToSell);

	//clothesList.push_back(shirtsToSell);
	//clothesList.push_back(shirt);
	//clothesList.push_back(pants);

	clothesList.push_back(_shirt);
	clothesList.push_back(_pants);
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
		for (const auto& clothes : clothesList)
		{
			std::cout << clothes->derivedName << " - " << clothes->stockAmount << std::endl;
		}
	}
	else
		std::cout << "No clothes to sell" << std::endl;
}

void Store::setClothesPreferences(int clothesType, int alternative1, int alternative2, int quality) // Alternativa puede ser hacer una lista generica
{
	std::cout << "\nLA PRUEBA DE FUEGO !!!!!!!!!!!!!!" << std::endl;
	std::cout << clothesList.front()->derivedName << std::endl;

	if (clothesType == 1)
	{
		_shirt = dynamic_cast<Shirt*>(clothesList.front());
		Shirt* _shirt2 = dynamic_cast<Shirt*>(clothesList.front());
		clothesList.erase(clothesList.begin());
		std::cout << "\nLA PRUEBA DE FUEGO 22222 !!!!!!!!!!!!!!" << std::endl;
		std::cout << "SERA VERDADERO O FALSO?" << _shirt2->mandarinCollar << std::endl; // Testeando si se guardan correctamente los valores en el vector de clothes = SI SE GUARDA

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

		std::cout << "\nLA PRUEBA DE FUEGO 33333 !!!!!!!!!!!!!!" << std::endl;
		std::cout << "SERA VERDADERO O FALSO?" << _shirt->mandarinCollar << std::endl;

		clothesList.insert(clothesList.begin(), _shirt);
	}

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

int Store::getClothesStock()
{
	Shirt* _shirt2 = dynamic_cast<Shirt*>(clothesList.front());
	return _shirt2->stockAmount;
}