#pragma once
#ifndef SHIRT_H
#define SHIRT_H
#include "Clothes.h"

class Shirt : public Clothes
{
public:
	bool shortSleeve;
	bool mandarinCollar;

	Shirt();
	~Shirt() override;
};

#endif // !SHIRT_H
