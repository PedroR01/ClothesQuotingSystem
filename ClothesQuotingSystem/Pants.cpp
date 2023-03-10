#include "Pants.h"
#include <iostream>

Pants::Pants()
{
	derivedName = "Pants";
	stockAmount = 2000;
	particularStock[0][0] = 1500; // Skinny
	particularStock[0][1] = 750; // Skinny & Standard
	particularStock[0][2] = 750; // Skinny & Premium
	particularStock[1][0] = 500; // Regular
	particularStock[1][1] = 250; // Regular & Standard
	particularStock[1][2] = 250; // Regular & Premium
}

Pants::~Pants()
{
}

void Pants::setDerivedOptions(int alternative[]) // Sets the type of pants for further quote
{
	if (alternative[0] == 1)
		skinny = true;
	else
		skinny = false;
}

int Pants::getDerivedClothes() // gets wich type of pants are being quoted by returning an int value wich is interpreted later
{
	if (!skinny) // Normal
		return 1;
	else
		return 2;
}

void Pants::setParticularStock(int amountQuoted) // updates the stock for those variations of Pants that are being quoted (not implemented)
{
	if (skinny)
	{
		if (quality == 1)
			particularStock[0][1] -= amountQuoted; // Skinny & Standard
		else if (quality == 2)
			particularStock[0][2] -= amountQuoted; // Skinny & Premium

		particularStock[0][0] -= amountQuoted; // Skinny
	}
	else if (!skinny)
	{
		if (quality == 1)
			particularStock[1][1] -= amountQuoted; // Regular & Standard
		else if (quality == 2)
			particularStock[1][2] -= amountQuoted; // Regular & Premium

		particularStock[1][0] -= amountQuoted; // Regular
	}
}

int Pants::getParticularStock() // get specific stock for each variation of Pants avaible (not implemented)
{
	if (skinny && quality == 1)
		return particularStock[0][1]; // Skinny & Standard
	else if (skinny && quality == 2)
		return particularStock[0][2]; // Skinny & Premium
	else if (!skinny && quality == 1)
		return particularStock[1][1]; // Regular & Standard
	else
		return particularStock[1][2]; // Regular & Premium
}