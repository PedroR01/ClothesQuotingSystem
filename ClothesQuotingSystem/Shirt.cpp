#include "Shirt.h"
#include <iostream>

Shirt::Shirt()
{
	derivedName = "Shirt";
	stockAmount = 2000;
}

Shirt::~Shirt()
{
}

void Shirt::setDerivedOptions(int alternative[])
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

int Shirt::getDerivedClothes()
{
	// Sumar o restar los valores segun sus variaciones para determinar un resultado final y luego desde Store se asocia ese numero a un las cualidades
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