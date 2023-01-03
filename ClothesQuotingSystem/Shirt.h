#pragma once
#ifndef SHIRT_H
#define SHIRT_H
#include "Clothes.h"

class Shirt : public Clothes
{
private:
	int particularStock[2][6];

public:
	bool shortSleeve;
	bool mandarinCollar;

	Shirt();
	~Shirt() override;

	void setDerivedOptions(int alternative[]) override;
	int getDerivedClothes() override;
	void setParticularStock(int amountQuoted) override;
	int getParticularStock() override;
};

#endif // !SHIRT_H
