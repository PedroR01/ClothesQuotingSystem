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

	// Pure virtual methods
	virtual void setDerivedOptions(int alternative[]) = 0;
	virtual int getDerivedClothes() = 0;
	virtual void setParticularStock(int amountQuoted) = 0;
	virtual int getParticularStock() = 0;
};
#endif // !CLOTHES_H
