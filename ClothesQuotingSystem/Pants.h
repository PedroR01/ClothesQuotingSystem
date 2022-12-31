#pragma once
#ifndef PANTS_H
#define PANTS_H
#include "Clothes.h"

enum class PantsVariations
{
	skinny
};

class Pants : public Clothes
{
public:
	bool skinny;

	Pants();
	~Pants() override;
};

#endif // !PANTS_H
