#pragma once
#ifndef CLOTHES_H
#define CLOTHES_H
#include <string>

class Clothes
{
public:
	std::string quality[2];
	double unitPrice;
	int stockAmount[2]; // Deberia hacerlo matriz??

	Clothes();
	virtual ~Clothes();
};
#endif // !CLOTHES_H
