#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#define SECTION "---------------------------------------"

View::View()
{
	m_Presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
}

void View::showMainMenu()
{
	system("CLS");

	std::cout << "\nCLOTHES QUOTING SYSTEM  -  MAIN MENU" << std::endl;
	std::cout << SECTION << std::endl;
	std::cout << m_Presenter->seeSellerStore() << std::endl;
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
	{
		system("CLS");
		quoteMenu();
	}
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

void View::quoteRecord()
{
	// AÑADIR PARA QUE SE LIMPIE LA CONSOLA PREVIAMENTE
	std::cout << SECTION << std::endl;
	std::cout << "Press 3 to return to Main Menu" << std::endl;
	std::cout << SECTION << std::endl;

	std::cout << "Quote Id number: " << " " << std::endl;
	std::cout << "Time and date of emition: " << " " << std::endl;
	std::cout << "Sellers code: " << " " << std::endl;
	std::cout << "Quoted clothes: " << " " << std::endl;
	std::cout << "Unit price: " << " " << std::endl;
	std::cout << "Amount of quoted units: " << " " << std::endl;
	std::cout << "Final outcome: " << " " << std::endl;

	std::cout << SECTION << std::endl;
	std::cout << "Press 3 to return to Main Menu" << std::endl;
	std::cout << SECTION << std::endl;
}

void View::showText(const std::string& text)
{
}