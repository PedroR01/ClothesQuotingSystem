#include "Shirt.h"
#include <iostream>

Shirt::Shirt()
{
	derivedName = "Shirt";
	stockAmount = 1000;
}

Shirt::~Shirt()
{
}

void Shirt::setDerivedOptions(int alternative[]) // Sets the type of shirt for further quote
{
	if (alternative[0] == 1)
		shortSleeve = true;
	else
		shortSleeve = false;

	if (alternative[1] == 1)
		mandarinCollar = true;
	else
		mandarinCollar = false;
}

int Shirt::getDerivedClothes() // gets wich type of shirt is being quoted by returning an int value wich is interpreted later
{
	int _short = 1, _long = 2, mandarin = 3, regular = 5;
	int finalShirt = 0;

	if (shortSleeve)
		finalShirt += _short;
	if (!shortSleeve)
		finalShirt += _long;
	if (mandarinCollar)
		finalShirt += mandarin;
	if (!mandarinCollar)
		finalShirt += regular;

	// short & mandarin = 4
	// long & mandaring = 5
	// short & regular = 6
	// long & regular = 7

	return finalShirt;
}

void Shirt::setParticularStock(int amountQuoted) // updates the stock for those variations of shirt that are being quoted
{
}

int Shirt::getParticularStock() // get specific stock for each variation of Shirts avaible
{
	return -1;
}