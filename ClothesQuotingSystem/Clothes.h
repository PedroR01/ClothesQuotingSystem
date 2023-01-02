#pragma once
#ifndef CLOTHES_H
#define CLOTHES_H
#include <string>

class Clothes
{
public:
	std::string derivedName;
	int quality;
	double unitPrice;
	int stockAmount;

	Clothes();
	virtual ~Clothes();
	virtual void setDerivedOptions(int alternative[]) = 0;
	virtual int getDerivedClothes() = 0;
};
#endif // !CLOTHES_H
