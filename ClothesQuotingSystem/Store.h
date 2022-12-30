#pragma once
#ifndef STORE_H
#define STORE_H
#include <string>
#include <vector>

class Clothes;

class Store
{
private:
	std::string storeName;
	std::string address;
	Clothes* shirt;
	Clothes* pants;
	std::vector<Clothes*> clothesList;

public:
	Store();
	~Store();
	std::string getStoreInfo() const;
};

#endif // !STORE_H
