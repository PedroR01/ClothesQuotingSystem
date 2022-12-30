#include "View.h"
#include "Presenter.h"
#include <iostream>

#define SECTION "---------------------------------------"

View::View()
{
	m_Presenter = new Presenter(this);
	//showMainMenu() // error bad_alloc. creo que es por algo de los getters a los que se quiere acceder, en la anterior version (en github) me daban nullptr al acceder por los getters
	sellerOptions();
}

View::~View()
{
}

void View::showMainMenu()
{
	std::cout << "\nCLOTHES QUOTING SYSTEM  -  MAIN MENU" << std::endl;
	std::cout << SECTION << std::endl;
	std::cout << m_Presenter->seeSellerName() << " | " << m_Presenter->seeSellerCode() << std::endl;
	std::cout << SECTION << std::endl;

	sellerOptions();
}

void View::sellerOptions()
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

void View::quoteMenu()
{
	std::cout << "\nSELECT CLOTHES TO QUOTE:" << std::endl;
	std::cout << "1) Shirt" << std::endl;
	std::cout << "2) Pants" << std::endl;

	int option;
	std::cin >> option;
	m_Presenter->startQuote(option);

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

void View::showText(const std::string& text)
{
}