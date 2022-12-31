#include "Clothes.h"

Clothes::Clothes()
{
	derivedName = "Base default";

	quality[0] = "Standard";
	quality[1] = "Premium";

	unitPrice = NULL;
	//stockAmount[0] = 1000; // Shirts
	//stockAmount[1] = 2000; // Pants
}

Clothes::~Clothes()
{
}