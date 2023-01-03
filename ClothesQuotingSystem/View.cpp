#include "View.h"
#include "Presenter.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

#define SECTION "---------------------------------------"
#define INT_MAX 2147483647

View::View()
{
	m_Presenter = new Presenter(this);
	showMainMenu();
}

View::~View()
{
}

void View::header(std::string actualSection)
{
	system("CLS");

	showText(SECTION);
	showTextWithSection("\nCLOTHES QUOTING SYSTEM  - " + actualSection);
	if (actualSection == "Main Menu")
	{
		showTextWithSection(m_Presenter->seeSellerStore());
		showTextWithSection(m_Presenter->seeSellerName() + " | " + parseNum(m_Presenter->seeSellerCode()));
	}
	else
	{
		showText(SECTION);
		showTextWithSection("Press 3 to return to Main Menu");
	}
}

void View::showMainMenu()
{
	header("Main Menu");

	showTextWithSection("\nPLEASE SELECT AN OPTION TO CONTINUE:");
	showText("1) View quote record");
	showText("2) Make a quote");
	showTextWithSection("3) Exit");

	int choice = 0;
	do {
		std::cin >> choice;
	} while (choice <= 0 || choice > 3);

	if (choice == 1)
	{
		system("CLS");
	}
	else if (choice == 2)
		quoteMenu();
	else if (choice == 3)
		exit(0);
}

void View::quoteMenu()
{
	step5InputError = false;

	header("Quote");

	showTextWithSection("\nSTEP 1: Select clothes to quote");
	showText("1) Shirt");
	showTextWithSection("2) Pants");

	int option = 0, alternative1 = 0, alternative2 = 0, quality = 0;
	selectOption(option, 1, 3);

	header("Quote");

	// DIFERENT CLOTHES AND RETURN OPTIONS
	if (option == 1) // Shirt
	{
		showTextWithOptions("\nSTEP 2.a: Is the shirt short sleeved?");
		selectOption(alternative1, 1, 3);

		showTextWithOptions("\nSTEP 2.b: The shirt have mandarin collar?");
		selectOption(alternative2, 1, 3);

		std::cout << "\n" << std::endl;
	}
	else if (option == 2) // Pants
	{
		showTextWithOptions("\nSTEP 2.a: Are the pants skinny?");
		selectOption(alternative1, 1, 3);
		alternative2 = 0;

		std::cout << "\n" << std::endl;
	}

	header("Quote");

	// STANDARD - PREMIUM
	showTextWithSection("\nSTEP 3: Select clothes quality");
	showText("1) Standard");
	showText("2) Premium");
	selectOption(quality, 1, 3);

	// Send all data selected by the seller/user
	m_Presenter->sendClothesData(option, alternative1, alternative2, quality);

	// Getting clothes stock avaible data
	int stock = m_Presenter->returnStock(option);

	// QUOTE/PRICE X UNIT
	double quote = 0;
	header("Quote");

	showTextWithSection("STEP 4: Enter quote per unit");
	selectOption(quote, 1, INT_MAX);

	// SHOW STOCK AND INPUT NUMBER OF UNITS TO QUOTE
	int unitsToQuote = 0;
	header("Quote");

	showText("IMPORTANT INFORMATION\nThere is only " + parseNum(stock) + " units in stock for the clothes you selected");
	showText("");
	showTextWithSection("STEP 5: Enter the number of units to quote");
	step5InputError = true; // Allows to show a specific stock message in this step if an invalid value is entered
	selectOption(unitsToQuote, 1, m_Presenter->returnStock(option));

	// Send quote and number of units
	m_Presenter->sendDataToQuote(option, unitsToQuote, quote);

	// GET QUOTE DATA AND MAKE A RECEIPT
	quoteRecord();
	m_Presenter->seeQuoteRecord();

	step5InputError = false;
	// BACK TO MAIN MENU
	option = 0;
	selectOption(option, 3, 3);
}

void View::quoteRecord() // Boolean to see record?
{
	header("Quote Record");

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

void View::selectOption(int& input, int min, int max)
{
	do
	{
		std::cin >> input;
		if (input  < min && step5InputError || input > max && step5InputError) // Showed in Step5 of quoteMenu
			showTextWithSection("UNITS INPUT ERROR: You cant quote 0 units or more units that what are avaible in stock. Please try again.");
	} while (input < min || input > max && max != 0);

	if (input == 3)
		showMainMenu();
}

void View::selectOption(double& input, int min, int max)
{
	do
	{
		std::cin >> input;
	} while (input < min || input > max);

	if (input == 3)
		showMainMenu();
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
	aux << value; // Take the values of variable value and it change them into a char array
	return aux.str(); // Transforms the char array into a string and returns it
}