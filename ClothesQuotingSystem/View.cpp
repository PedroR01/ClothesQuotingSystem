#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <string>
#include <sstream>
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

void View::header()
{
	system("CLS");

	showTextWithSection("\nCLOTHES QUOTING SYSTEM  -  MAIN MENU");
	showTextWithSection(m_Presenter->seeSellerStore());
	showTextWithSection(m_Presenter->seeSellerName() + " | " + parseNum(m_Presenter->seeSellerCode()));
}

void View::showMainMenu()
{
	system("CLS"); // Activar limpieza solo cuando haya establecido un encabezado con
	header();

	showTextWithSection("\nPLEASE SELECT AN OPTION TO CONTINUE:");
	showText("1) View quote record");
	showText("2) Make a quote");
	showTextWithSection("3) Exit");

	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		system("CLS");
	}
	else if (choice == 2)
		quoteMenu();

	else
		exit(0);
}

void View::quoteMenu()
{
	system("CLS");

	showTextWithSection("\nSTEP 1: Select clothes to quote");
	showText("1) Shirt");
	showTextWithSection("2) Pants");

	int option, alternative1 = 0, alternative2 = 0, quality = 0;
	std::cin >> option;

	system("CLS");

	// DIFERENT CLOTHES AND RETURN OPTIONS
	if (option == 1) // Shirt
	{
		// Podrian reemplazarse las diferentes variables de alternativas por una sola que sea un array declarado para cada caso y que tenga
		// una cantidad determinada para cada tipo de ropa dependiendo de sus cantidades de variaciones
		showTextWithOptions("\nSTEP 2.a: Is the shirt short sleeved?");
		std::cin >> alternative1;
		showTextWithOptions("\nSTEP 2.b: The shirt have mandarin collar?");
		std::cin >> alternative2;
		std::cout << "\n" << std::endl;
	}
	else if (option == 2) // Pants
	{
		showTextWithOptions("\nSTEP 2.a: Are the pants skinny?");
		std::cin >> alternative1;
		alternative2 = 0;
		std::cout << "\n" << std::endl;
	}
	else // Return - Go back
	{
		showMainMenu();
	}

	system("CLS");

	// STANDARD - PREMIUM
	showTextWithSection("\nSTEP 3: Select clothes quality");
	showText("1) Standard");
	showText("2) Premium");
	std::cin >> quality; // Could reset variable option and use it here but it will get messy

	// Send all data selected by the seller/user
	m_Presenter->sendClothesData(option, alternative1, alternative2, quality);

	// Getting clothes stock avaible data
	int stock = m_Presenter->returnStock(option);

	// QUOTE/PRICE X UNIT
	double quote = 0;
	system("CLS");

	showTextWithSection("STEP 4: Enter quote per unit");
	std::cin >> quote;

	// SHOW STOCK AND INPUT NUMBER OF UNITS TO QUOTE
	int unitsToQuote = 0;
	system("CLS");

	showText("IMPORTANT INFORMATION\nThere is only " + parseNum(stock) + " units in stock for the clothes you selected");
	showText("");
	showTextWithSection("STEP 5: Enter the number of units to quote");
	std::cin >> unitsToQuote;

	// Send quote and number of units
	m_Presenter->sendDataToQuote(option, unitsToQuote, quote);

	// GET QUOTE DATA AND MAKE A RECEIPT
	quoteRecord();

	// BACK TO MAIN MENU
	option = 0;
	std::cin >> option;

	while (option != 3)
		std::cin >> option;

	showMainMenu();
}

void View::quoteRecord() // Booleano como parametro para ver el historial?
{
	system("CLS");

	showText(SECTION);
	showTextWithSection("Press 3 to return to Main Menu");

	showText("Quote Id number: " + m_Presenter->seeQuoteInfo(1));
	showText("Time and date of emition: " + m_Presenter->seeQuoteInfo(2));
	showText("Seller code: " + m_Presenter->seeQuoteInfo(3));
	showText("Quoted clothes: " + m_Presenter->seeQuoteInfo(4));
	showText("Unit price: " + parseNum(m_Presenter->seeUnitPrice()));
	showText("Amount of quoted units: " + m_Presenter->seeQuoteInfo(5));
	showText("Final outcome: " + m_Presenter->seeQuoteInfo(6));

	showText(SECTION);
	showTextWithSection("Press 3 to return to Main Menu");
}

void View::showText(const std::string& text)
{
	std::cout << text << std::endl;
}
void View::showTextWithSection(const std::string& text)
{
	std::cout << text << std::endl;
	std::cout << SECTION << std::endl;
}

void View::showTextWithOptions(const std::string& text)
{
	std::cout << text << std::endl;
	std::cout << SECTION << std::endl;
	std::cout << "1) Yes" << std::endl;
	std::cout << "1) No" << std::endl;
	std::cout << SECTION << std::endl;
}

std::string View::parseNum(double value)
{
	std::ostringstream aux;
	aux << value; // Toma los valores de value y los transforma en un array de char
	return aux.str(); // Transforma el array en string y lo retorna
}