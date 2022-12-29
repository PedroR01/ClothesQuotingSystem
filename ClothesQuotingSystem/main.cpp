#include <iostream>
#include <vector>
#include "Seller.h";
#include "Quote.h";

int Quote::quoteId = 000; // Esto luego deberia inicializarse en el View

class Shop
{
};

class View
{
};

int main()
{
	Seller* user = new Seller();

	delete user;
	return 0;
}