#pragma once
#ifndef PANTS_H
#define PANTS_H
#include "Clothes.h"

class Pants : public Clothes
{
public:
	bool skinny;

	Pants();
	~Pants() override;
	void setDerivedOptions(int alternative[]) override;
	int getDerivedClothes() override;
};

#endif // !PANTS_H
