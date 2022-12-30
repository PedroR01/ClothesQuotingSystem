#pragma once
#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

class Clothes;

class Store
{
public:
	const std::string* storeName;
	std::string address;
	std::vector<Clothes> clothesList;
};

#endif // !STORE_H
