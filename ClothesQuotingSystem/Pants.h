#pragma once
#ifndef PANTS_H
#define PANTS_H
#include "Clothes.h"

class Pants : public Clothes
{
private:
	int particularStock[2][3];

public:
	bool skinny;

	Pants();
	~Pants() override;

	void setDerivedOptions(int alternative[]) override;
	int getDerivedClothes() override;
	void setParticularStock(int amountQuoted) override;
	int getParticularStock() override;
};

#endif // !PANTS_H
