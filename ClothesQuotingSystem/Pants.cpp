#include "Pants.h"
#include <iostream>

Pants::Pants()
{
	derivedName = "Pants";
	stockAmount = 1000;
}

Pants::~Pants()
{
}

void Pants::setDerivedOptions(int alternative[])
{
	std::cout << "PANTALOOON" << std::endl;
}

int Pants::getDerivedClothes()
{
	if (!skinny) // Normal
		return 1;
	if (skinny) // Skinny
		return 2;
	else // En caso de error
		return -1;
}