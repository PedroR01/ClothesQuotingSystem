#pragma once
#ifndef CLOTHES_H
#define CLOTHES_H
#include <string>

class Clothes
{
public:
	std::string derivedName;
	std::string quality[2];
	double unitPrice;
	int stockAmount;
	//int stockAmount[2]; // Deberia hacerlo matriz??
	//int shirtStock[14];
	//int pantsStock[6];

	Clothes();
	virtual ~Clothes();
};
#endif // !CLOTHES_H
